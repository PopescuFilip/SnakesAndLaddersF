//
// Created by Alexandru Pestritu on 20.11.2024.
//

#ifndef LOBBYSERVICE_H
#define LOBBYSERVICE_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "../Models/Player.h"
#include "../Core/BaseResponse.h"
#include "../core/BaseService.h"
#include "../core/ApiEndpoints.h"

class LobbyService : public BaseService {
public:
    LobbyService();
    ~LobbyService();

    nlohmann::json getLobbyStatus(int lobbyId);
    int createLobby(const std::string& adminUsername, int mapType, int maxPlayers);
    nlohmann::json joinLobby(int lobbyId, const std::string& username);
    void leaveLobby(int lobbyId, const std::string& username);
    void updateLobby(int lobbyId, const std::string& adminUsername, int mapType, int maxPlayers);
};

#endif //LOBBYSERVICE_H
