//
// Created by Tudor Andrei on 23.11.2024.
//

#ifndef LEAVEGAMEROUTE_H
#define LEAVEGAMEROUTE_H
#include <crow/json.h>

#include "Infrastructure/Game/LeaveGame/LeaveGameContext.h"

inline crow::json::wvalue LeaveGameRoute(const crow::json::rvalue& request) {
    const int gameId = request["gameId"].i();
    const std::string playerUsername = request["playerUsername"].s();

    LeaveGameContext context;
    LeaveGameRequest leaveGameRequest{gameId, playerUsername};
    LeaveGameResponse leaveGameResponse = context.HandleRequest(leaveGameRequest);

    return leaveGameResponse.convertToJson();
}

#endif //LEAVEGAMEROUTE_H
