#ifndef LOBBYMANAGER_H
#define LOBBYMANAGER_H
#include "../Objects/Lobby.h"


class LobbyManager {
public:
    static LobbyManager& getInstance();

    virtual int createLobby(const std::string& strAdminPlayer, MapType mapType, int maxPlayers);
    virtual int createLobby(const Lobby& lobby);
    virtual void removeLobby(int lobbyId);
    virtual void updateLobby(int lobbyId, const Lobby& newLobbyDetails);
    virtual Lobby getLobby(int lobbyId) const;

private:
    std::vector<Lobby> m_Lobbies;

    static int GenerateLobbyId();
};



#endif //LOBBYMANAGER_H
