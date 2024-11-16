#ifndef CHANGELOBBYSETTINGSROUTE_H
#define CHANGELOBBYSETTINGSROUTE_H
#include <crow/json.h>
#include "../GameManagement/Objects/MapTypeEnum.h"
#include "../Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsContext.h"

inline crow::json::wvalue ChangeLobbySettingsRoute(const crow::json::rvalue& request) {
    int lobbyId = request["lobbyId"].i();
    std::string playerUsername = request["playerUsername"].s();
    int maxPlayers = request["maxPlayers"].i();
    auto mapType = static_cast<MapType>(request["mapType"].i());

    const UpdateSettingsRequest updateLobbySettingsRequest{lobbyId, playerUsername, mapType, maxPlayers};
    UpdateSettingsContext context;
    const UpdateSettingsResponse response = context.HandleRequest(updateLobbySettingsRequest);

    return response.convertToJson();
}

#endif //CHANGELOBBYSETTINGSROUTE_H
