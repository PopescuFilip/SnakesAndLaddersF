#include "LeaveLobbyCommand.h"
#include "GameManagement/Lobby/LobbyManager.h"

LeaveLobbyCommand::LeaveLobbyCommand(const crow::json::rvalue& request) :
    HttpCommand{ request },
    m_lobbyId{ m_request.getLobbyId() },
    m_username{ m_request.getPlayerUsername() }
{
}

BaseResponsePtr LeaveLobbyCommand::execute()
{
    Lobby lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
    const bool result = lobby.removePlayer(m_username);

    if (!result)
        return std::make_unique<BaseResponse>("Player not found in lobby");

    if (lobby.getPlayers().empty())
    {
        LobbyManager::getInstance().removeLobby(lobby.getLobbyId());
        return std::make_unique<BaseResponse>(true);
    }

    LobbyManager::getInstance().updateLobby(lobby.getLobbyId(), lobby);
    return std::make_unique<BaseResponse>(true);
}

BaseResponse LeaveLobbyCommand::checkCanExecute() const
{
    try
    {
        const auto& lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
    }
    catch (const std::runtime_error&)
    {
        return BaseResponse("Lobby does not exist");
    }

    return BaseResponse(true);
}
