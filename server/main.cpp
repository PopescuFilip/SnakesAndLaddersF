#include "crow.h"
#include "Routes/CreateLobbyRoute.h"
#include "Routes/JoinLobbyRoute.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/lobby/create").methods("POST"_method)([](const crow::request& req) {
        crow::json::rvalue jsonRequest = crow::json::load(req.body);
        crow::json::wvalue jsonResponse = CreateLobbyRoute(jsonRequest);
        return crow::response{jsonResponse};
    });

    CROW_ROUTE(app, "/lobby/join").methods("POST"_method)([](const crow::request& req) {
        crow::json::rvalue jsonRequest = crow::json::load(req.body);
        crow::json::wvalue jsonResponse = JoinLobbyRoute(jsonRequest);
        return crow::response{jsonResponse};
    });

    app.port(18080).multithreaded().run();
}
