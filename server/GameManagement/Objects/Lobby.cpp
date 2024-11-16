#include "Lobby.h"

Lobby::Lobby() : isNull(true), m_MapType{MapType::NONE}, m_iMaxPlayers{0} {
    // Null constructor. Used for error handling
}

Lobby::Lobby(int lobbyId, std::string strAdminPlayer, MapType mapType, int maxPlayers) : m_iLobbyId{lobbyId},
    m_strAdminPlayer{std::move(strAdminPlayer)}, m_MapType{mapType}, m_iMaxPlayers{maxPlayers} {
    m_Players.emplace_back(strAdminPlayer, PlayerColor::RED, true);
}

bool Lobby::addPlayer(const Player &player) {
    if(m_Players.size() == MAX_PLAYERS) {
        return false;
    }

    m_Players.push_back(player);
    return true;
}

bool Lobby::addPlayer(const std::string &strUsername, PlayerColor playerColor) {
    if(m_Players.size() == MAX_PLAYERS) {
        return false;
    }

    m_Players.emplace_back(strUsername, playerColor, false);
    return true;
}

bool Lobby::removePlayer(const std::string &strUsername) {
    auto it = std::find_if(m_Players.begin(), m_Players.end(), [&strUsername](const Player& player) {
        return player.getUsername() == strUsername;
    });

    if(it == m_Players.end()) {
        return false;
    }

    m_Players.erase(it);
    return true;
}

std::list<Player> Lobby::getPlayers() const {
    return m_Players;
}

std::string Lobby::getAdminPlayer() const {
    return m_strAdminPlayer;
}

MapType Lobby::getMapType() const {
    return m_MapType;
}

int Lobby::getMaxPlayers() const {
    return m_iMaxPlayers;
}

int Lobby::getLobbyId() const {
    return m_iLobbyId;
}
