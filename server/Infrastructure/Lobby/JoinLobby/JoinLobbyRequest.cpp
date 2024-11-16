//
// Created by Tudor Andrei on 16.11.2024.
//

#include "JoinLobbyRequest.h"

JoinLobbyRequest::JoinLobbyRequest(int lobbyId, const std::string & strUsername) :
    m_iLobbyId{lobbyId}, m_strUsername{strUsername}
{
    // Empty constructor
}

const std::string & JoinLobbyRequest::getUsername() const {
    return m_strUsername;
}

int JoinLobbyRequest::getLobbyId() const {
    return m_iLobbyId;
}
