#include "GameManager.h"

#include <thread>

#include "GameManagement/Lobby/LobbyManager.h"

GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

RunningGame GameManager::createGame(const Lobby &lobby) {
    RunningGame newGame{lobby};
    m_Games.push_back(newGame);
    createGameThread(newGame.getGameId());
    return newGame;
}

void GameManager::createGameThread(int gameId) {
    std::thread gameThread([gameId] {
        RunningGame& game = GameManager::getInstance().getRunningGamePtr(gameId);
        while (!game.getShouldFinishGame()) {
            // check if dice rolled and player did not move yet

            if (!game.getDiceRolling() && game.getLatestDiceValue() != 0) {
                game.getCurrentPlayer().setCurrentBoardPosition(game.getCurrentPlayer().getCurrentBoardPosition() + game.getLatestDiceValue());
                game.startNewTurn();
            }

            if (game.getCurrentTurnTime() > MAX_SECONDS_PER_TURN) {
                game.startNewTurn();
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        GameManager::getInstance().removeGame(game.getGameId());
    });

    gameThread.detach();
}


bool GameManager::removeGame(int gameId) {
    auto it = std::find_if(m_Games.begin(), m_Games.end(), [&gameId](const RunningGame& game) {
        return game.getGameId() == gameId;
    });

    if(it != m_Games.end()) {
        m_Games.erase(it);
        return true;
    }

    return false;
}

RunningGame GameManager::getRunningGame(int gameId) const {
    auto it = std::find_if(m_Games.begin(), m_Games.end(), [&gameId](const RunningGame& game) {
        return game.getGameId() == gameId;
    });

    if(it != m_Games.end()) {
        return *it;
    }

    return RunningGame();
}


bool GameManager::updateGame(int gameId, const RunningGame &newGameDetails) {
    auto it = std::find_if(m_Games.begin(), m_Games.end(), [&gameId](const RunningGame& game) {
        return game.getGameId() == gameId;
    });

    if(it != m_Games.end()) {
        *it = newGameDetails;
        return true;
    }

    return false;
}

void GameManager::rollDiceInGame(int gameId) {
    auto it = std::find_if(m_Games.begin(), m_Games.end(), [&gameId](const RunningGame& game) {
        return game.getGameId() == gameId;
    });

    if(it != m_Games.end()) {
        it->triggerDiceRolling();
        int random = generateRandomNumber(DICE_ROLL_MIN, DICE_ROLL_MAX);
        it->setLatestDiceValue(random);
    }

    throw std::runtime_error("Game not found. Game id = " + std::to_string(gameId) + ". Line 90 in GameManager.cpp");
}

int GameManager::generateRandomNumber(const int min, const int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

RunningGame &GameManager::getRunningGamePtr(int gameId) const {
    for (const RunningGame &game : m_Games) {
        if (game.getGameId() == gameId) {
            return const_cast<RunningGame &>(game);
        }
    }

    throw std::runtime_error("Game not found. Game id = " + std::to_string(gameId) + ". Line 114 in GameManager.cpp");
}


