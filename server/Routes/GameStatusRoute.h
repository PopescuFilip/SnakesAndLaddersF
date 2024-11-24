#ifndef GAMESTATUSROUTE_H
#define GAMESTATUSROUTE_H
#include <crow/json.h>

#include "Infrastructure/Game/GameStatus/GameStatusContext.h"

inline crow::json::wvalue GameStatusRoute(const crow::json::rvalue& request) {
    int gameId = request["gameId"].i();

    GameStatusContext context;
    GameStatusRequest gameStatusRequest{gameId};
    GameStatusResponse gameStatusResponse = context.HandleRequest(gameStatusRequest);

    return gameStatusResponse.convertToJson();
}

#endif //GAMESTATUSROUTE_H
