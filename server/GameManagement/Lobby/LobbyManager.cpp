#include "LobbyManager.h"

LobbyManager LobbyManager::getInstance() {
    static LobbyManager instance;
    return instance;
}

void LobbyManager::createLobby(const std::string &strAdminPlayer, MapType mapType, int maxPlayers) {
    int lobbyId = GenerateLobbyId();
    m_Lobbies.emplace_back(lobbyId, strAdminPlayer, mapType, maxPlayers);
}

void LobbyManager::createLobby(const Lobby &lobby) {
    m_Lobbies.push_back(lobby);
}

void LobbyManager::removeLobby(int lobbyId) {
    auto it = std::find_if(m_Lobbies.begin(), m_Lobbies.end(), [&lobbyId](const Lobby& l) {
        return l.getLobbyId() == lobbyId;
    });

    if(it != m_Lobbies.end()) {
        m_Lobbies.erase(it);
    }
}

void LobbyManager::updateLobby(int lobbyId, const Lobby &newLobbyDetails) {
    auto it = std::find_if(m_Lobbies.begin(), m_Lobbies.end(), [&lobbyId](const Lobby& l) {
        return l.getLobbyId() == lobbyId;
    });

    if(it != m_Lobbies.end()) {
        *it = newLobbyDetails;
    }
}

Lobby LobbyManager::getLobby(int lobbyId) const {
    auto it = std::find_if(m_Lobbies.begin(), m_Lobbies.end(), [&lobbyId](const Lobby& l) {
        return l.getLobbyId() == lobbyId;
    });

    if(it != m_Lobbies.end()) {
        return *it;
    }

    return Lobby();
}

int LobbyManager::GenerateLobbyId() {
    static int lobbyId = 0;
    return ++lobbyId;
}
