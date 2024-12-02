//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef LOBBY_H
#define LOBBY_H

#include <string>
#include <vector>
#include "Player.h"
#include <nlohmann/json.hpp>
#include "MapType.h"

class Lobby {
private:
    int lobbyId;
    std::string adminUsername;
    MapType mapType;
    int maxPlayers;
    int gameId;
    std::vector<Player> players;

public:
    Lobby();
    Lobby(int lobbyId, const std::string& adminUsername, MapType mapType, int maxPlayers, int gameId, const std::vector<Player>& players);

    int getLobbyId() const;
    void setLobbyId(int value);

    std::string getAdminUsername() const;
    void setAdminUsername(const std::string& value);

    MapType getMapType() const;
    void setMapType(MapType value);

    int getMaxPlayers() const;
    void setMaxPlayers(int value);

    int getGameId() const;
    void setGameId(int value);

    std::vector<Player> getPlayers() const;
    void setPlayers(const std::vector<Player>& value);

    friend void to_json(nlohmann::json& j, const Lobby& l);
    friend void from_json(const nlohmann::json& j, Lobby& l);

    bool operator==(const Lobby& other) const;
    bool operator!=(const Lobby& other) const;
};

#endif //LOBBY_H
