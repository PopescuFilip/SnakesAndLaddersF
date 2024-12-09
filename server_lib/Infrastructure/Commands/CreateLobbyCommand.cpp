#include "CreateLobbyCommand.h"
#include "GameManagement/Lobby/LobbyManager.h"
#include "Infrastructure/UniversalResponse.h"

CreateLobbyCommand::CreateLobbyCommand(const crow::json::rvalue& request) :
    HttpCommand{ request },
    m_strAdminUsername{ m_request.getAdminUsername() },
    m_iMaxPlayers{ m_request.getMaxPlayers() },
    m_mapType{ m_request.getMapType() }
{}

BaseResponsePtr CreateLobbyCommand::execute()
{
    int id = LobbyManager::getInstance().createLobby(m_strAdminUsername, m_mapType, m_iMaxPlayers);
    return std::make_unique<UniversalResponse>(id);
}

BaseResponse CreateLobbyCommand::checkCanExecute() const
{
    if (m_iMaxPlayers < 2 || m_iMaxPlayers > 4)
    {
        return BaseResponse("Max players must be between 2 and 4");
    }

    return BaseResponse(true);
}
