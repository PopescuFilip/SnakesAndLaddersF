#include "LobbyStatusResponse.h"

LobbyStatusResponse::LobbyStatusResponse(const std::string &message) : BaseResponse{message} {
}

LobbyStatusResponse::LobbyStatusResponse(const Lobby &lobby) : BaseResponse{true}, m_lobby{lobby} {
}

crow::json::wvalue LobbyStatusResponse::convertToJson() const {
    crow::json::wvalue json;
    json["success"] = getSuccess();
    json["message"] = getMessage();
    json["lobby"] = m_lobby.convertToJson();

    return json;
}

