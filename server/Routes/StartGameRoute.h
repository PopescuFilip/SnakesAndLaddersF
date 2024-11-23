#ifndef STARTGAMEROUTE_H
#define STARTGAMEROUTE_H
#include <crow/json.h>

#include "Infrastructure/Lobby/StartGame/StartGameContext.h"

inline crow::json::wvalue StartGameRoute(const crow::json::rvalue& request) {
    int lobbyId = request["lobbyId"].i();
    std::string playerUsername = request["playerUsername"].s();

    StartGameContext context;
    StartGameRequest startGameRequest{lobbyId, playerUsername};
    StartGameResponse response = context.HandleRequest(startGameRequest);

    return response.convertToJson();
}

#endif //STARTGAMEROUTE_H
