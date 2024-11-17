#ifndef API_H
#define API_H

#include "Routes/CreateLobbyRoute.h"
#include "Routes/JoinLobbyRoute.h"
#include "Routes/ChangeLobbySettingsRoute.h"
#include "Routes/LeaveLobbyRoute.h"
#include "Routes/StatusLobbyRoute.h"

#define GET_ROUTE(path, functionName) CROW_ROUTE(crowApplication, path).methods("GET"_method)([](const crow::request& req) { \
    crow::json::rvalue jsonRequest = crow::json::load(req.body); \
    crow::json::wvalue jsonResponse = functionName(jsonRequest); \
    return crow::response{jsonResponse}; \
})

#define POST_ROUTE(path, functionName) CROW_ROUTE(crowApplication, path).methods("POST"_method)([](const crow::request& req) { \
    crow::json::rvalue jsonRequest = crow::json::load(req.body); \
    crow::json::wvalue jsonResponse = functionName(jsonRequest); \
    return crow::response{jsonResponse}; \
})




inline void SetRoutes(crow::SimpleApp& crowApplication) {

    POST_ROUTE("/lobby/create", CreateLobbyRoute);
    POST_ROUTE("/lobby/join", JoinLobbyRoute);
    POST_ROUTE("/lobby/update", ChangeLobbySettingsRoute);
    POST_ROUTE("/lobby/leave", LeaveLobbyRoute);

    GET_ROUTE("/lobby/status", StatusLobbyRoute);
}

#endif //API_H
