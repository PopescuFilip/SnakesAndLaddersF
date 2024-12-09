#include "StartGameCommand.h"
#include "GameManagement/Game/GameManager.h"
#include "GameManagement/Lobby/LobbyManager.h"

StartGameCommand::StartGameCommand(const crow::json::rvalue& request) :
    HttpCommand{ request },
    m_lobbyId{ m_request.getLobbyId() },
    m_username{ m_request.getUsername() }
{}

BaseResponsePtr StartGameCommand::execute()
{
    Lobby lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
    RunningGame runningGame = GameManager::getInstance().createGame(lobby);

    lobby.setGameId(runningGame.getGameId());
    LobbyManager::getInstance().updateLobby(lobby.getLobbyId(), lobby);

    return std::make_unique<BaseResponse>(true);
}

BaseResponse StartGameCommand::checkCanExecute() const
{
    if (m_username.empty())
        return BaseResponse("Player username is empty");

    if (m_lobbyId < 0)
        return BaseResponse("Lobby id is invalid");

    try
    {
        const Lobby& lobby = LobbyManager::getInstance().getLobby(m_lobbyId);

        if (lobby.getAdminPlayer() != m_username)
            return BaseResponse("Player is not the admin of the lobby");

        if (lobby.getPlayers().size() == 1)
            return BaseResponse("Lobby has only one player");
    }
    catch (const std::runtime_error&)
    {
        return BaseResponse("Lobby does not exist");
    }

    return BaseResponse(true);
}