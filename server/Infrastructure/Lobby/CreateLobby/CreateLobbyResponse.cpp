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