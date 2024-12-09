#ifndef API_H
#define API_H

#include <iostream>

#include "Infrastructure/Commands/CreateLobbyCommand.h"
#include "Infrastructure/Commands/JoinLobbyCommand.h"
#include "Infrastructure/Commands/ChangeLobbySettingsCommand.h"
#include "Infrastructure/Commands/LeaveLobbyCommand.h"
#include "Infrastructure/Commands/StartGameCommand.h"
#include "Infrastructure/Commands/StatusLobbyCommand.h"
#include "Infrastructure/Commands/GameStatusCommand.h"
#include "Infrastructure/Commands/GameStatisticsCommand.h"
#include "Infrastructure/Commands/LeaveGameCommand.h"
#include "Infrastructure/Commands/RollDiceCommand.h"

template <typename CommandType>
crow::json::wvalue ExecuteCommand(const crow::json::rvalue& request) {
    CommandType command{ request };
    return command.executeWithCheck()->convertToJson();
}

//template crow::json::wvalue ExecuteCommand<CreateLobbyCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<JoinLobbyCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<ChangeLobbySettingsCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<LeaveLobbyCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<StartGameCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<StatusLobbyCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<GameStatusCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<GameStatisticsCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<LeaveGameCommand>(const crow::json::rvalue&);
//template crow::json::wvalue ExecuteCommand<RollDiceCommand>(const crow::json::rvalue&);


#define GET_ROUTE(path, CommandType) CROW_ROUTE(crowApplication, path).methods("GET"_method)([](const crow::request& req) { \
    crow::json::rvalue jsonRequest = crow::json::load(req.body); \
    crow::json::wvalue jsonResponse = ExecuteCommand<CommandType>(jsonRequest); \
    return crow::response{jsonResponse}; \
}); \
std::cout << "[GET] Register: " << path << "\n"

#define POST_ROUTE(path, CommandType) CROW_ROUTE(crowApplication, path).methods("POST"_method)([](const crow::request& req) { \
    crow::json::rvalue jsonRequest = crow::json::load(req.body); \
    crow::json::wvalue jsonResponse = ExecuteCommand<CommandType>(jsonRequest); \
    return crow::response{jsonResponse}; \
}); \
std::cout << "[POST] Register: " << path << "\n"


inline void SetLobbyRoutes(crow::SimpleApp& crowApplication) {
    POST_ROUTE("/lobby/create", CreateLobbyCommand);
    POST_ROUTE("/lobby/join", JoinLobbyCommand);
    POST_ROUTE("/lobby/update", ChangeLobbySettingsCommand);
    POST_ROUTE("/lobby/leave", LeaveLobbyCommand);
    POST_ROUTE("/lobby/start-game", StartGameCommand);

    GET_ROUTE("/lobby/status", StatusLobbyCommand);
}

inline void SetGameRoutes(crow::SimpleApp& crowApplication) {
    GET_ROUTE("/game/status", GameStatusCommand);
    GET_ROUTE("/game/stats", GameStatisticsCommand);
    POST_ROUTE("/game/leave", LeaveGameCommand);
    POST_ROUTE("/game/roll-dice", RollDiceCommand);
}


#endif //API_H
