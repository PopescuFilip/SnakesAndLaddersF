//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef LOBBY_H
#define LOBBY_H

#include <string>
#include <vector>
#include "Player.h"
#include <nlohmann/json.hpp>

class Lobby {
private:
    int lobbyId;
    std::string adminUsername;
    int mapType;
    int maxPlayers;
    int gameId;
    std::vector<Player> players;

public:
    Lobby();
    Lobby(int lobbyId, const std::string& adminUsername, int mapType, int maxPlayers, int gameId, const std::vector<Player>& players);

    int getLobbyId() const;
    void setLobbyId(int value);

    std::string getAdminUsername() const;
    void setAdminUsername(const std::string& value);

    int getMapType() const;
    void setMapType(int value);

    int getMaxPlayers() const;
    void setMaxPlayers(int value);

    int getGameId() const;
    void setGameId(int value);

    std::vector<Player> getPlayers() const;
    void setPlayers(const std::vector<Player>& value);

    friend void to_json(nlohmann::json& j, const Lobby& l);
    friend void from_json(const nlohmann::json& j, Lobby& l);
};

#endif //LOBBY_H
