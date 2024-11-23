//
// Created by Tudor Andrei on 23.11.2024.
//

#include "LeaveGameRequest.h"

LeaveGameRequest::LeaveGameRequest(int gameId, const std::string &playerUsername) : m_GameId{gameId}, m_PlayerUsername{playerUsername} {}

int LeaveGameRequest::getGameId() const {
    return m_GameId;
}

const std::string &LeaveGameRequest::getPlayerUsername() const {
    return m_PlayerUsername;
}
