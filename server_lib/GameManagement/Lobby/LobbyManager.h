#ifndef LOBBYMANAGER_H
#define LOBBYMANAGER_H
#include "../Objects/Lobby.h"

constexpr int WAIT_TIME_BEFORE_DELETE_LOBBY_SECONDS = 3;

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
    void startDeleteProcedure(int lobbyId);
};



#endif //LOBBYMANAGER_H
