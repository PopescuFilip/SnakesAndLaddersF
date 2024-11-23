#include "UpdateSettingsRequest.h"

UpdateSettingsRequest::UpdateSettingsRequest(int lobbyId, const std::string &strPlayerUsername, MapType mapType,
    int maxPlayers) : m_iLobbyId{lobbyId}, m_strPlayerUsername{strPlayerUsername}, m_MapType{mapType}, m_iMaxPlayers{maxPlayers} {
    // Constructor
}

int UpdateSettingsRequest::getLobbyId() const {
    return m_iLobbyId;
}

std::string UpdateSettingsRequest::getPlayerUsername() const {
    return m_strPlayerUsername;
}

MapType UpdateSettingsRequest::getMapType() const {
    return m_MapType;
}

int UpdateSettingsRequest::getMaxPlayers() const {
    return m_iMaxPlayers;
}