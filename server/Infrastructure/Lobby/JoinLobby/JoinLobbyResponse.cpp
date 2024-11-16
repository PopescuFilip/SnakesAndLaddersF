#include "JoinLobbyResponse.h"

JoinLobbyResponse::JoinLobbyResponse(const std::string &message) : BaseResponse(message), m_lobbyId{-1}, m_mapType(MapType::NONE) {
    // Error constructor
}

JoinLobbyResponse::JoinLobbyResponse(const Lobby &lobby) : BaseResponse{true}, m_lobby{lobby} {
}

crow::json::wvalue JoinLobbyResponse::convertToJson() const {
    crow::json::wvalue jsonResponse;
    jsonResponse["success"] = getSuccess();
    jsonResponse["message"] = getMessage();
    jsonResponse["lobby"] = m_lobby.convertToJson();
    return jsonResponse;
}