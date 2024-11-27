//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef APIENDPOINTS_H
#define APIENDPOINTS_H

#include <string>

namespace ApiEndpoints {
    const std::string BASE_ADDRESS = "http://localhost";
    const std::string BASE_PORT = "18080";
    const std::string BASE_URL = BASE_ADDRESS + ":" + BASE_PORT;
    const std::string GET_LOBBY_STATUS = BASE_URL + "/lobby/status";
    const std::string CREATE_LOBBY = BASE_URL + "/lobby/create";
    const std::string JOIN_LOBBY = BASE_URL + "/lobby/join";
    const std::string UPDATE_LOBBY = BASE_URL + "/lobby/update";
    const std::string LEAVE_LOBBY = BASE_URL + "/lobby/leave";
    const std::string START_GAME = BASE_URL + "/lobby/start-game";
    const std::string GET_GAME_STATUS = BASE_URL + "/game/status";
    const std::string LEAVE_GAME = BASE_URL + "/game/leave";
    const std::string GET_GAME_STATS = BASE_URL + "/game/stats";
    const std::string GAME_ROLL_DICE = BASE_URL + "/game/roll-dice";
}

#endif //APIENDPOINTS_H
