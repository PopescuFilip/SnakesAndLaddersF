#include "JoinLobbyCommand.h"
#include "GameManagement/Lobby/LobbyManager.h"
#include "Infrastructure/UniversalResponse.h"

JoinLobbyCommand::JoinLobbyCommand(const crow::json::rvalue& request) :
	HttpCommand{ request },
	m_lobbyId{ m_request.getLobbyId() },
	m_username{ m_request.getUsername() }
{}

BaseResponsePtr JoinLobbyCommand::execute()
{
    Lobby lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
    const PlayerColor color = lobby.getNextAvailableColor();
    bool playerAdded = lobby.addPlayer(m_username, color);
    if (!playerAdded)
        return std::make_unique<BaseResponse>("Lobby is full", false);

    LobbyManager::getInstance().updateLobby(m_lobbyId, lobby);

    return std::make_unique<UniversalResponse>(lobby);
}

BaseResponse JoinLobbyCommand::checkCanExecute() const
{
    if (m_username.empty())
        return BaseResponse("Username cannot be empty", false);

    const LobbyManager& lobbyManager = LobbyManager::getInstance();

    try
    {
        const Lobby lobby = lobbyManager.getLobby(m_lobbyId);

        if (lobby.getPlayers().size() == lobby.getMaxPlayers())
            return BaseResponse("Lobby is full", false);

        for (const Player& player : lobby.getPlayers())
        {
            if (player.getUsername() == m_username)
                return BaseResponse("Player already exists in lobby", false);
        }
    }
    catch (const std::exception&)
    {
        return BaseResponse("Lobby does not exist", false);
    }

    return BaseResponse(true);
}
