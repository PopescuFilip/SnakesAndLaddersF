#include "ChangeLobbySettingsCommand.h"
#include "GameManagement/Lobby/LobbyManager.h"


ChangeLobbySettingsCommand::ChangeLobbySettingsCommand(const crow::json::rvalue& request) :
	HttpCommand{ request },
    m_lobbyId{ m_request.getLobbyId() },
	m_maxPlayers{ m_request.getMaxPlayers() },
	m_playerUsername{ m_request.getUsername() },
	m_mapType{ m_request.getMapType() }
{}

BaseResponsePtr ChangeLobbySettingsCommand::execute()
{
    Lobby lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
    lobby.setMapType(m_mapType);
    lobby.setMaxPlayers(m_maxPlayers);
    LobbyManager::getInstance().updateLobby(m_lobbyId, lobby);

    return std::make_unique<BaseResponse>(true);
}

BaseResponse ChangeLobbySettingsCommand::checkCanExecute() const
{
    if (m_playerUsername.empty())
        return BaseResponse("Username cannot be empty");

    try
    {
        Lobby lobby = LobbyManager::getInstance().getLobby(m_lobbyId);
        if (lobby.getAdminPlayer() != m_playerUsername)
            return BaseResponse("Player is not the admin");

        if (lobby.getPlayers().size() > m_maxPlayers)
            return BaseResponse("Max players cannot be less than current players");
    }
    catch (const std::runtime_error&)
    {
        return BaseResponse("Lobby does not exist");
    }

    return BaseResponse(true);
}
