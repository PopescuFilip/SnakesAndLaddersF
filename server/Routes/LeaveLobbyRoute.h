#ifndef LEAVELOBBYROUTE_H
#define LEAVELOBBYROUTE_H
#include <crow/json.h>

#include "Infrastructure/Lobby/LeaveLobby/LeaveLobbyContext.h"

inline crow::json::wvalue LeaveLobbyRoute(const crow::json::rvalue& request) {

    int lobbyId = request["lobbyId"].i();
    std::string playerusername = request["playerUsername"].s();

    LeaveLobbyRequest leaveLobbyRequest{lobbyId, playerusername};
    LeaveLobbyContext context;
    LeaveLobbyResponse response = context.HandleRequest(leaveLobbyRequest);

    return response.convertToJson();

}

#endif //LEAVELOBBYROUTE_H
