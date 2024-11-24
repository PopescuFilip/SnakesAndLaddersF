//
// Created by Alexandru Pestritu on 21.11.2024.
//

#ifndef LOBBYSTATE_H
#define LOBBYSTATE_H

#include "../models/Lobby.h"
#include <mutex>

class LobbyState {
public:
    static LobbyState& getInstance();

    void setLobby(const Lobby& lobby);
    Lobby getLobby() const;

    LobbyState(const LobbyState&) = delete;
    LobbyState& operator=(const LobbyState&) = delete;

private:
    LobbyState();
    mutable std::mutex m_lobbyStateMutex;
    Lobby m_lobby;
};

#endif //LOBBYSTATE_H
