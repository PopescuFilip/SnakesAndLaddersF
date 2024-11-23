#include "LobbyManager.h"

LobbyManager& LobbyManager::getInstance() {
    static LobbyManager instance;
    return instance;
}

int LobbyManager::createLobby(const std::string &strAdminPlayer, MapType mapType, int maxPlayers) {
    int lobbyId = GenerateLobbyId();
    Lobby newLobby = Lobby{lobbyId, strAdminPlayer, mapType, maxPlayers};
    m_Lobbies.push_back(newLobby);
    return lobbyId;
}

int LobbyManager::createLobby(const Lobby &lobby) {
    m_Lobbies.push_back(lobby);
    return lobby.getLobbyId();
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
