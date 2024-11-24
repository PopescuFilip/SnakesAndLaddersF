#ifndef JOINLOBBYROUTE_H
#define JOINLOBBYROUTE_H

#include <crow.h>

#include "Infrastructure/Lobby/JoinLobby/JoinLobbyContext.h"

inline crow::json::wvalue JoinLobbyRoute(const crow::json::rvalue& jsonRequest) {
    std::string strUsername = jsonRequest["username"].s();
    int iLobbyId = jsonRequest["lobbyId"].i();

    JoinLobbyRequest request{iLobbyId, strUsername};
    JoinLobbyContext context;
    JoinLobbyResponse response = context.HandleRequest(request);

    return response.convertToJson();
}

#endif //JOINLOBBYROUTE_H
