#include "GameManager.h"

GameManager GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::createGame(const Lobby &lobby) {
    m_Games.emplace_back(lobby);
}

void GameManager::removeGame(int gameId) {
    auto it = std::find_if(m_Games.begin(), m_Games.end(), [&gameId](const RunningGame& game) {
        return game.getGameId() == gameId;
    });

    if(it != m_Games.end()) {
        m_Games.erase(it);
    }
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

