#include "StartGameRequest.h"

StartGameRequest::StartGameRequest(int lobbyId, const std::string &playerUsername) : m_iLobbyId{lobbyId}, m_strPlayerUsername{playerUsername} {}

int StartGameRequest::GetLobbyId() const {
    return m_iLobbyId;
}

std::string StartGameRequest::GetPlayerUsername() const {
    return m_strPlayerUsername;
}
