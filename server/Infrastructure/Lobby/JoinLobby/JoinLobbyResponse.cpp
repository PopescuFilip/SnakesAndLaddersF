#include "JoinLobbyResponse.h"

JoinLobbyResponse::JoinLobbyResponse(const std::string &message) : BaseResponse(message), m_lobbyId{-1}, m_mapType(MapType::NONE) {
    // Error constructor
}

JoinLobbyResponse::JoinLobbyResponse(int lobbyId, const std::string &strAdminUsername, const std::list<Player> &players, MapType mapType) :
    BaseResponse(true), m_lobbyId{lobbyId}, m_strAdminUsername{strAdminUsername}, m_players{players}, m_mapType{mapType}
{
    // Success constructor
}

crow::json::wvalue JoinLobbyResponse::convertToJson() const {
    crow::json::wvalue jsonResponse;
    jsonResponse["success"] = getSuccess();
    jsonResponse["message"] = getMessage();
    jsonResponse["lobbyId"] = m_lobbyId;
    jsonResponse["adminUsername"] = m_strAdminUsername;
    jsonResponse["mapType"] = static_cast<int>(m_mapType);

    std::vector<std::string> playersJson;
    for(const Player& player : m_players) {
        playersJson.push_back(player.getJsonValue().dump());
    }

    jsonResponse["players"] = playersJson;

    return jsonResponse;
}