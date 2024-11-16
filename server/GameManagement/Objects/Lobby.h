#ifndef LOBBY_H
#define LOBBY_H

#define MAX_PLAYERS 4

#include <list>

#include "MapTypeEnum.h"
#include "Player.h"


class Lobby {
public:
    Lobby();
    Lobby(int lobbyId, std::string strAdminPlayer, MapType mapType, int maxPlayers);
    bool addPlayer(const Player& player);
    bool addPlayer(const std::string& strUsername, PlayerColor playerColor);
    bool removePlayer(const std::string& strUsername);

    std::list<Player> getPlayers() const;
    std::string getAdminPlayer() const;
    MapType getMapType() const;
    int getMaxPlayers() const;
    int getLobbyId() const;

    bool isNull = false;
private:
    int m_iLobbyId;
    std::list<Player> m_Players;
    std::string m_strAdminPlayer;
    MapType m_MapType;
    int m_iMaxPlayers;
};



#endif //LOBBY_H
