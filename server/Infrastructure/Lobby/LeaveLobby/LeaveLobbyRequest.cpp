//
// Created by Tudor Andrei on 17.11.2024.
//

#include "LeaveLobbyRequest.h"

LeaveLobbyRequest::LeaveLobbyRequest(int lobbyId, const std::string &strPlayerUsername) : m_lobbyId(lobbyId), m_strPlayerUsername(strPlayerUsername) {

}

int LeaveLobbyRequest::getLobbyId() const {
    return m_lobbyId;
}

std::string LeaveLobbyRequest::getPlayerUsername() const {
    return m_strPlayerUsername;
}
