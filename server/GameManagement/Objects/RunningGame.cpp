//
// Created by Tudor Andrei on 16.11.2024.
//

#include "RunningGame.h"

RunningGame::RunningGame(const Lobby &baseLobby) : m_Players{baseLobby.getPlayers()} {
    gameId = baseLobby.getLobbyId();
}

void RunningGame::updatePlayerPosition(const std::string &strUsername, int iPosition) {
    auto it = std::find_if(m_Players.begin(), m_Players.end(), [&strUsername](const Player& player) {
        return player.getUsername() == strUsername;
    });

    if(it != m_Players.end()) {
        it->setCurrentBoardPosition(iPosition);
    }
}

int RunningGame::getGameId() const {
    return gameId;
}

RunningGame::RunningGame() : isNull(true), gameId{-1} {
    // Null constructor. Used for error handling
}
