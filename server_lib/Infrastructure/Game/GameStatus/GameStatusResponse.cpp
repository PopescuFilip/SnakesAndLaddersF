//
// Created by Tudor Andrei on 20.11.2024.
//

#include "GameStatusResponse.h"

GameStatusResponse::GameStatusResponse(const RunningGame &game) : BaseResponse(true), m_Game{ game }
{}

GameStatusResponse::GameStatusResponse(const std::string &message) : BaseResponse(message)
{}

RunningGame GameStatusResponse::getGame() const {
    return *m_Game;
}

crow::json::wvalue GameStatusResponse::convertToJson() const {
    crow::json::wvalue json;
    json["success"] = getSuccess();
    json["message"] = getMessage();
    json["game"] = m_Game->convertToJson();
    return json;
}
