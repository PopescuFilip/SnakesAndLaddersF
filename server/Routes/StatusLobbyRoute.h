#ifndef STATUSLOBBYROUTE_H
#define STATUSLOBBYROUTE_H
#include <crow.h>

#include "../Infrastructure/Lobby/LobbyStatus/LobbyStatusContext.h"

inline crow::json::wvalue StatusLobbyRoute(const crow::json::rvalue& request) {
    int lobbyId = request["lobbyId"].i();

    LobbyStatusRequest request {lobbyId};
    LobbyStatusContext context;
    LobbyStatusResponse response = context.HandleRequest(request);

    return response.convertToJson();
}

#endif //STATUSLOBBYROUTE_H
