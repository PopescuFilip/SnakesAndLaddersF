#ifndef LOBBYMANAGER_H
#define LOBBYMANAGER_H
#include "../Objects/Lobby.h"


class LobbyManager {
public:
    static LobbyManager getInstance();

    void createLobby(const std::string& strAdminPlayer, MapType mapType, int maxPlayers);
    void createLobby(const Lobby& lobby);
    void removeLobby(int lobbyId);
    void updateLobby(int lobbyId, const Lobby& newLobbyDetails);
    Lobby getLobby(int lobbyId) const;

private:
    std::list<Lobby> m_Lobbies;

    static int GenerateLobbyId();
};



#endif //LOBBYMANAGER_H
