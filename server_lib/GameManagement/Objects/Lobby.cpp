#include "Lobby.h"

Lobby::Lobby(int lobbyId, const std::string& strAdminPlayer, MapType mapType, int maxPlayers) :
    m_iLobbyId{ lobbyId },
    m_strAdminPlayer{ strAdminPlayer },
    m_MapType{ mapType },
    m_iMaxPlayers{ maxPlayers } {
    m_Players.push_back(Player{strAdminPlayer, PlayerColor::RED, true});
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

    if(m_Players.size() == 1) {
        m_Players.clear();
        return true;
    }

    if(it->isLobbyAdmin()) {
        setNewAdmin();
    }

    m_Players.erase(it);
    return true;
}

PlayerColor Lobby::getNextAvailableColor() const {
    // Read the colors of the players in the lobby and return the next available color
    std::vector<PlayerColor> colors = {PlayerColor::RED, PlayerColor::BLUE, PlayerColor::GREEN, PlayerColor::YELLOW};

    for(const Player& player : m_Players) {
        auto it = std::find(colors.begin(), colors.end(), player.getPlayerColor());
        if(it != colors.end()) {
            colors.erase(it);
        }
    }

    if(colors.empty()) {
        throw std::runtime_error("FATAL ERROR: No available colors in lobby. Please check Lobby.cpp line 64");
    }

    return colors[0];
}

std::vector<Player> Lobby::getPlayers() const {
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

void Lobby::setMapType(MapType mapType) {
    this->m_MapType = mapType;
}

void Lobby::setMaxPlayers(int maxPlayers) {
    this->m_iMaxPlayers = maxPlayers;
}

void Lobby::setGameId(int gameId) {
    m_iGameId = gameId;
}

void Lobby::setAdminPlayer(const std::string &strAdminPlayer) {

    for(Player& p : m_Players) {
        if(p.getUsername() == strAdminPlayer) {
            p.setIsLobbyAdmin(true);
        }
    }

    m_strAdminPlayer = strAdminPlayer;
}

crow::json::wvalue Lobby::convertToJson() const {
    crow::json::wvalue json;
    json["lobbyId"] = m_iLobbyId;
    json["adminUsername"] = m_strAdminPlayer;
    json["mapType"] = static_cast<int>(m_MapType);
    json["maxPlayers"] = m_iMaxPlayers;
    json["gameId"] = m_iGameId;

    crow::json::wvalue::list playersJson;
    for (const Player& player : m_Players) {
        playersJson.push_back(player.convertToJson());
    }

    json["players"] = std::move(playersJson);

    return json;
}

void Lobby::setNewAdmin() {
    for(const Player& player : m_Players) {
        if(player.getUsername() != m_strAdminPlayer) {
            setAdminPlayer(player.getUsername());
        }
    }
}


