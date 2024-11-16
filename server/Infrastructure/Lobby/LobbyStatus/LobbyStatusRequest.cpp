#include "LobbyStatusRequest.h"

LobbyStatusRequest::LobbyStatusRequest(int lobbyId) : m_iLobbyId(lobbyId) {}

int LobbyStatusRequest::GetLobbyId() const {
    return m_iLobbyId;
}
