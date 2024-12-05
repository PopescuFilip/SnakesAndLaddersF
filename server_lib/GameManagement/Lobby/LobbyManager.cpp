#include "LobbyManager.h"

#include <thread>

LobbyManager &LobbyManager::getInstance() {
    static LobbyManager instance;
    return instance;
}

int LobbyManager::createLobby(const std::string &strAdminPlayer, MapType mapType, int maxPlayers) {
    int lobbyId = GenerateLobbyId();
    Lobby newLobby{ lobbyId, strAdminPlayer, mapType, maxPlayers };
    m_Lobbies.emplace_back(newLobby);
    return lobbyId;
}

void LobbyManager::removeLobby(int lobbyId) {
    startDeleteProcedure(lobbyId);
}

void LobbyManager::updateLobby(int lobbyId, const Lobby &newLobbyDetails) {
    auto it = std::find_if(m_Lobbies.begin(), m_Lobbies.end(), [&lobbyId](const Lobby &l) {
        return l.getLobbyId() == lobbyId;
    });

    if (it != m_Lobbies.end()) {
        *it = newLobbyDetails;
    }
}

Lobby LobbyManager::getLobby(int lobbyId) const {
    auto it = std::find_if(m_Lobbies.begin(), m_Lobbies.end(), [&lobbyId](const Lobby &l) {
        return l.getLobbyId() == lobbyId;
    });

    if (it != m_Lobbies.end()) {
        return *it;
    }

    throw std::runtime_error("Lobby not found. Lobby id = " + std::to_string(lobbyId) + ". Line 45 in LobbyManager.cpp");
}

int LobbyManager::GenerateLobbyId() {
    static int lobbyId = 0;
    return ++lobbyId;
}

void LobbyManager::startDeleteProcedure(int lobbyId) {
    std::thread deleteThread([this, lobbyId] {
        auto it = std::find_if(m_Lobbies.begin(), m_Lobbies.end(), [&lobbyId](const Lobby &l) {
            return l.getLobbyId() == lobbyId;
        });

        if (it != m_Lobbies.end()) {
            std::this_thread::sleep_for(std::chrono::seconds(WAIT_TIME_BEFORE_DELETE_LOBBY_SECONDS));
            m_Lobbies.erase(it);
        }
    });

    deleteThread.detach();
}
