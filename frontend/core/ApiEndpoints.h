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
}

#endif //APIENDPOINTS_H
