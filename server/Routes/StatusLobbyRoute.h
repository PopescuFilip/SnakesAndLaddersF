#ifndef STATUSLOBBYROUTE_H
#define STATUSLOBBYROUTE_H
#include <crow.h>

#include "Infrastructure/Lobby/LobbyStatus/LobbyStatusContext.h"

inline crow::json::wvalue StatusLobbyRoute(const crow::json::rvalue& request) {
    int lobbyId = request["lobbyId"].i();

    LobbyStatusRequest lobbyStatusRequest {lobbyId};
    LobbyStatusContext context;
    LobbyStatusResponse response = context.HandleRequest(lobbyStatusRequest);

    return response.convertToJson();
}

#endif //STATUSLOBBYROUTE_H
