#ifndef API_H
#define API_H

#include <iostream>

#include "Routes/CreateLobbyRoute.h"
#include "Routes/JoinLobbyRoute.h"
#include "Routes/ChangeLobbySettingsRoute.h"
#include "Routes/LeaveLobbyRoute.h"
#include "Routes/StatusLobbyRoute.h"
#include "Routes/StartGameRoute.h"
#include "Routes/GameStatusRoute.h"
#include "Routes/LeaveGameRoute.h"
#include "Routes/GameStatisticsRoute.h"

#define GET_ROUTE(path, functionName) CROW_ROUTE(crowApplication, path).methods("GET"_method)([](const crow::request& req) { \
    crow::json::rvalue jsonRequest = crow::json::load(req.body); \
    crow::json::wvalue jsonResponse = functionName(jsonRequest); \
    return crow::response{jsonResponse}; \
}); \
std::cout << "[GET] Register: " << path << "\n"

#define POST_ROUTE(path, functionName) CROW_ROUTE(crowApplication, path).methods("POST"_method)([](const crow::request& req) { \
    crow::json::rvalue jsonRequest = crow::json::load(req.body); \
    crow::json::wvalue jsonResponse = functionName(jsonRequest); \
    return crow::response{jsonResponse}; \
}); \
std::cout << "[POST] Register: " << path << "\n"

inline void SetLobbyRoutes(crow::SimpleApp& crowApplication) {

    POST_ROUTE("/lobby/create", CreateLobbyRoute);
    POST_ROUTE("/lobby/join", JoinLobbyRoute);
    POST_ROUTE("/lobby/update", ChangeLobbySettingsRoute);
    POST_ROUTE("/lobby/leave", LeaveLobbyRoute);
    POST_ROUTE("/lobby/start-game", StartGameRoute);

    GET_ROUTE("/lobby/status", StatusLobbyRoute);
}

inline void SetGameRoutes(crow::SimpleApp& crowApplication) {
    GET_ROUTE("/game/status", GameStatusRoute);
    GET_ROUTE("/game/stats", GameStatisticsRoute);
    POST_ROUTE("/game/leave", LeaveGameRoute);
}

#endif //API_H
