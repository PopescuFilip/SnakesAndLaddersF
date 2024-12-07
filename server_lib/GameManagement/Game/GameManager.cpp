#include "GameManager.h"

#include <thread>

#include "GameManagement/Lobby/LobbyManager.h"

GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

RunningGame GameManager::createGame(const Lobby &lobby) {
    RunningGame newGame{ lobby };
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
                int newPosition = game.getNewTeleportPosition(game.getCurrentPlayer().getCurrentBoardPosition());
                game.getCurrentPlayer().setCurrentBoardPosition(newPosition);
                if (game.getCurrentPlayer().getCurrentBoardPosition() >= MAX_BOARD_POSITION) {
                    game.getCurrentPlayer().setCurrentBoardPosition(MAX_BOARD_POSITION);
                    game.setShouldFinishGame(true);
                    break;
                }

                game.startNewTurn();
            }

            if (game.getCurrentTurnTime() > MAX_SECONDS_PER_TURN) {
                game.startNewTurn();
            }

            if (game.getPlayers().size() == 1) {
                game.setShouldFinishGame(true);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        std::this_thread::sleep_for(std::chrono::seconds(MAX_WAIT_UNTIL_GAME_FINISH_SECONDS));
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

    throw std::runtime_error("Game not found. Game id = " + std::to_string(gameId) + ". Line 90 in GameManager.cpp");
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
        it->rollDice();
        return;
    }

    throw std::runtime_error("Game not found. Game id = " + std::to_string(gameId) + ". Line 90 in GameManager.cpp");
}

RunningGame &GameManager::getRunningGamePtr(int gameId) const {
    for (const RunningGame &game : m_Games) {
        if (game.getGameId() == gameId) {
            return const_cast<RunningGame &>(game);
        }
    }

    throw std::runtime_error("Game not found. Game id = " + std::to_string(gameId) + ". Line 114 in GameManager.cpp");
}


