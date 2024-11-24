#ifndef LOBBYMANAGER_H
#define LOBBYMANAGER_H
#include "../Objects/Lobby.h"

constexpr int WAIT_TIME_BEFORE_DELETE_LOBBY_SECONDS = 3;

class LobbyManager {
public:
    static LobbyManager& getInstance();

    int createLobby(const std::string& strAdminPlayer, MapType mapType, int maxPlayers);
    int createLobby(const Lobby& lobby);
    void removeLobby(int lobbyId);
    void updateLobby(int lobbyId, const Lobby& newLobbyDetails);
    Lobby getLobby(int lobbyId) const;

private:
    std::vector<Lobby> m_Lobbies;

    static int GenerateLobbyId();
    void startDeleteProcedure(int lobbyId);
};



#endif //LOBBYMANAGER_H
