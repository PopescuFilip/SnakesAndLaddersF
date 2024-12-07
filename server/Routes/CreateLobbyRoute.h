#ifndef CREATELOBBYROUTE_H
#define CREATELOBBYROUTE_H

#include <crow.h>

#include "Infrastructure/Lobby/CreateLobby/CreateLobbyContext.h"
#include "Infrastructure/Commands/CreateLobbyCommand.h"

inline crow::json::wvalue CreateLobbyRoute(const crow::json::rvalue& jsonRequest) {
    std::string strAdminUsername = jsonRequest["adminUsername"].s();
    int iMaxPlayers = jsonRequest["maxPlayers"].i();
    auto mapType = static_cast<MapType>(jsonRequest["mapType"].i());

    CreateLobbyRequest request{mapType, iMaxPlayers, strAdminUsername};
    CreateLobbyContext context;
    CreateLobbyResponse response = context.HandleRequest(request);

    return response.convertToJson();
}

inline crow::json::wvalue CreateLobbyRouteNew(const crow::json::rvalue& jsonRequest) {

    CreateLobbyCommand command(jsonRequest);

    return command.executeWithCheck().convertToJson();
}

#endif //CREATELOBBYROUTE_H
