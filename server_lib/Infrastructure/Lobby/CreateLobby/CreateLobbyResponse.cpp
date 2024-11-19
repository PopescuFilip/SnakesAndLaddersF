#include "CreateLobbyResponse.h"

CreateLobbyResponse::CreateLobbyResponse(int iLobbyId) : BaseResponse{true}, m_iLobbyId{iLobbyId}
{
    // Empty constructor
}

CreateLobbyResponse::CreateLobbyResponse(const std::string &strContent) : BaseResponse{strContent}, m_iLobbyId{-1}
{
    // Empty constructor
}

int CreateLobbyResponse::getLobbyId() const
{
    return m_iLobbyId;
}

crow::json::wvalue CreateLobbyResponse::convertToJson() const {

    crow::json::wvalue jsonResponse;
    jsonResponse["success"] = getSuccess();
    jsonResponse["message"] = getMessage();
    jsonResponse["lobbyId"] = m_iLobbyId;

    return jsonResponse;
}


