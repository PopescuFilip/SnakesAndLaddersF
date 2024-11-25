//
// Created by Alexandru Pestritu on 20.11.2024.
//

#ifndef LOBBYSERVICE_H
#define LOBBYSERVICE_H

#include <qstring.h>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "../Models/Player.h"
#include "../Core/BaseResponse.h"
#include "../core/BaseService.h"
#include "../core/ApiEndpoints.h"
#include "../models/Lobby.h"

class LobbyService : public BaseService {
public:
    LobbyService();
    ~LobbyService();

    Lobby getLobbyStatus(int lobbyId);
    void getLobbyStatusAsync(int lobbyId, std::function<void(bool, const QString&, const Lobby&)> callback);
    int createLobby(const std::string& adminUsername, int mapType, int maxPlayers);
    Lobby joinLobby(int lobbyId, const std::string& username);
    void leaveLobby(int lobbyId, const std::string& username);
    void updateLobby(int lobbyId, const std::string& adminUsername, int mapType, int maxPlayers);
    void startGame(int lobbyId, const std::string& username);
};

#endif //LOBBYSERVICE_H
