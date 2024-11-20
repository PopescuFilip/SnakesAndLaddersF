#ifndef LOBBY_H
#define LOBBY_H

#include <list>

#include "MapTypeEnum.h"
#include "Player.h"

constexpr int MAX_PLAYERS = 4;

class Lobby {
public:
    Lobby();

    Lobby(int lobbyId, const std::string &strAdminPlayer, MapType mapType, int maxPlayers);

    bool addPlayer(const Player &player);

    bool addPlayer(const std::string &strUsername, PlayerColor playerColor);

    bool removePlayer(const std::string &strUsername);

    PlayerColor getNextAvailableColor() const;

    std::vector<Player> getPlayers() const;

    std::string getAdminPlayer() const;

    MapType getMapType() const;

    int getMaxPlayers() const;

    int getLobbyId() const;

    void setMapType(MapType mapType);

    void setMaxPlayers(int maxPlayers);

    void setGameId(int gameId);

    void setAdminPlayer(const std::string &strAdminPlayer);

    crow::json::wvalue convertToJson() const;

    bool isNull = false;

private:
    int m_iLobbyId;
    std::vector<Player> m_Players;
    std::string m_strAdminPlayer;
    MapType m_MapType;
    int m_iMaxPlayers;

    int m_iGameId = -1;

    void setNewAdmin();
};


#endif //LOBBY_H
