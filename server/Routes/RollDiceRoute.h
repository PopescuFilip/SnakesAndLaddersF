//
// Created by Tudor Andrei on 27.11.2024.
//

#ifndef ROLLDICEROUTE_H
#define ROLLDICEROUTE_H
#include <crow/json.h>

#include "Infrastructure/Game/RollDice/RollDiceContext.h"

inline crow::json::wvalue RollDiceRoute(const crow::json::rvalue& request) {
    const int gameId = request["gameId"].i();
    const std::string playerUsername = request["playerUsername"].s();

    RollDiceContext context;
    const RollDiceRequest rollDiceRequest{gameId, playerUsername};
    const RollDiceResponse rollDiceResponse = context.HandleRequest(rollDiceRequest);

    return rollDiceResponse.convertToJson();

}
#endif //ROLLDICEROUTE_H
