#ifndef CREATELOBBYROUTE_H
#define CREATELOBBYROUTE_H

#include <crow.h>

#include "../Infrastructure/Lobby/CreateLobby/CreateLobbyContext.h"
#include "../Infrastructure/Lobby/CreateLobby/CreateLobbyRequest.h"

inline crow::json::wvalue CreateLobbyRoute(const crow::json::rvalue& jsonRequest) {
    std::string strAdminUsername = jsonRequest["adminUsername"].s();
    int iMaxPlayers = jsonRequest["maxPlayers"].i();
    auto mapType = static_cast<MapType>(jsonRequest["mapType"].i());

    CreateLobbyRequest request{mapType, iMaxPlayers, strAdminUsername};
    CreateLobbyContext context;
    CreateLobbyResponse response = context.HandleRequest(request);

    return response.convertToJson();
}

#endif //CREATELOBBYROUTE_H
