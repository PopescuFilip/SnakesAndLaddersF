#ifndef LOBBY_H
#define LOBBY_H

#include <list>

#include "MapTypeEnum.h"
#include "Player.h"

constexpr int MAX_PLAYERS = 4;

class Lobby : public BaseObject{
public:
    Lobby();

    Lobby(int lobbyId, const std::string &strAdminPlayer, MapType mapType, int maxPlayers);

    virtual bool addPlayer(const Player &player);

    virtual bool addPlayer(const std::string &strUsername, PlayerColor playerColor);

    virtual bool removePlayer(const std::string &strUsername);

    virtual PlayerColor getNextAvailableColor() const;

    virtual std::vector<Player> getPlayers() const;

    virtual std::string getAdminPlayer() const;

    virtual MapType getMapType() const;

    virtual int getMaxPlayers() const;

    virtual int getLobbyId() const;

    virtual void setMapType(MapType mapType);

    virtual void setMaxPlayers(int maxPlayers);

    virtual void setGameId(int gameId);

    virtual void setAdminPlayer(const std::string &strAdminPlayer);

    crow::json::wvalue convertToJson() const override;

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
