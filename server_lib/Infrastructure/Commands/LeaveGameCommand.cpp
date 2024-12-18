#include "LeaveGameCommand.h"
#include "GameManagement/Game/GameManager.h"

LeaveGameCommand::LeaveGameCommand(const crow::json::rvalue& request) :
	HttpCommand{ request },
	m_gameId{ m_request.getGameId() },
	m_username{ m_request.getPlayerUsername() }
{}

BaseResponsePtr LeaveGameCommand::execute()
{
    RunningGame runningGame = GameManager::getInstance().getRunningGame(m_gameId);
    bool result = runningGame.removePlayer(m_username);

    if (!result)
        return std::make_unique<BaseResponse>("Failed to leave game", false);

    GameManager::getInstance().updateGame(m_gameId, runningGame);

    return std::make_unique<BaseResponse>(true);
}

BaseResponse LeaveGameCommand::checkCanExecute() const
{
    try
    {
        RunningGame game = GameManager::getInstance().getRunningGame(m_gameId);
    }
    catch (const std::runtime_error&)
    {
        return BaseResponse("Game does not exist", false);
    }

    return BaseResponse(true);
}
