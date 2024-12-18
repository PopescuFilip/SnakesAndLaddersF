#include "StatusLobbyCommand.h"
#include "GameManagement/Lobby/LobbyManager.h"
#include "Infrastructure/UniversalResponse.h"

StatusLobbyCommand::StatusLobbyCommand(const crow::json::rvalue& request) :
    HttpCommand{ request },
    m_lobbyId{ m_request.getLobbyId() }
{}

BaseResponsePtr StatusLobbyCommand::execute()
{
    Lobby lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
    return std::make_unique<UniversalResponse>(lobby);
}

BaseResponse StatusLobbyCommand::checkCanExecute() const
{
    try
    {
        Lobby lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
    }
    catch (const std::runtime_error&)
    {
        return BaseResponse("Lobby does not exist", false);
    }

    return BaseResponse(true);
}
