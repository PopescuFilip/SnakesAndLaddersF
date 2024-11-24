//
// Created by Tudor Andrei on 23.11.2024.
//

#ifndef GAMESTATISTICSROUTE_H
#define GAMESTATISTICSROUTE_H

#include <crow/json.h>
#include "Infrastructure/Game/GameStatistics/GameStatisticsContext.h"

inline crow::json::wvalue GameStatisticsRoute(const crow::json::rvalue& request) {
    const int gameId = request["gameId"].i();

    GameStatisticsContext context;
    GameStatisticsRequest gameStatisticsRequest{gameId};
    GameStatisticsResponse gameStatisticsResponse = context.HandleRequest(gameStatisticsRequest);

    return gameStatisticsResponse.convertToJson();
}

#endif //GAMESTATISTICSROUTE_H
