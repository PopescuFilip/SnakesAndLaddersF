#include "GameManager.h"

GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

RunningGame GameManager::createGame(const Lobby &lobby) {
    RunningGame newGame{lobby};
    m_Games.push_back(newGame);

    return newGame;
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


