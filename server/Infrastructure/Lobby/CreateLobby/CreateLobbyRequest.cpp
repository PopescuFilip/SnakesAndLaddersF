#include "CreateLobbyRequest.h"

CreateLobbyRequest::CreateLobbyRequest(MapType mapType, int iMaxPlayers, const std::string& strAdminUsername) :
    m_MapType{mapType}, m_iMaxPlayers{iMaxPlayers}, m_strAdminUseranme{strAdminUsername}
{
    // Empty constructor
}

MapType CreateLobbyRequest::getMapType() const {
    return m_MapType;
}

int CreateLobbyRequest::getMaxPlayers() const {
    return m_iMaxPlayers;
}

const std::string& CreateLobbyRequest::getAdminUsername() const {
    return m_strAdminUseranme;
}
