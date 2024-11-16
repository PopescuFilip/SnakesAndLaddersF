#ifndef API_H
#define API_H

#include "Routes/CreateLobbyRoute.h"
#include "Routes/JoinLobbyRoute.h"
#include "Routes/ChangeLobbySettingsRoute.h"
#include "Routes/StatusLobbyRoute.h"

inline void SetRoutes(crow::SimpleApp& crowApplication) {

    CROW_ROUTE(crowApplication, "/lobby/create").methods("POST"_method)([](const crow::request& req) {
    crow::json::rvalue jsonRequest = crow::json::load(req.body);
    crow::json::wvalue jsonResponse = CreateLobbyRoute(jsonRequest);
    return crow::response{jsonResponse};
});

    CROW_ROUTE(crowApplication, "/lobby/join").methods("POST"_method)([](const crow::request& req) {
        crow::json::rvalue jsonRequest = crow::json::load(req.body);
        crow::json::wvalue jsonResponse = JoinLobbyRoute(jsonRequest);
        return crow::response{jsonResponse};
    });

    CROW_ROUTE(crowApplication, "/lobby/update").methods("POST"_method)([](const crow::request& req) {
        crow::json::rvalue jsonRequest = crow::json::load(req.body);
        crow::json::wvalue jsonResponse = ChangeLobbySettingsRoute(jsonRequest);
        return crow::response{jsonResponse};
    });

    CROW_ROUTE(crowApplication, "/lobby/status").methods("GET"_method)([](const crow::request& req) {
        crow::json::rvalue jsonRequest = crow::json::load(req.body);
        crow::json::wvalue jsonResponse = StatusLobbyRoute(jsonRequest);
        return crow::response{jsonResponse};
    });

}

#endif //API_H
