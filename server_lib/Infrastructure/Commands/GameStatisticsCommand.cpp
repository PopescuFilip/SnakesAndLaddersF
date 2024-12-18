#include "GameStatisticsCommand.h"
#include "GameManagement/Game/GameManager.h"
#include "Infrastructure/UniversalResponse.h"

GameStatisticsCommand::GameStatisticsCommand(const crow::json::rvalue& request) :
	HttpCommand{ request },
	m_gameId{ m_request.getGameId() }
{}

BaseResponsePtr GameStatisticsCommand::execute()
{
    RunningGame runningGame = GameManager::getInstance().getRunningGame(m_gameId);

    return std::make_unique<UniversalResponse>(runningGame.getPlayers(), runningGame.getTotalTime());
}

BaseResponse GameStatisticsCommand::checkCanExecute() const
{
    try
    {
        RunningGame runningGame = GameManager::getInstance().getRunningGame(m_gameId);

        if (!runningGame.getShouldFinishGame()) {
            return BaseResponse("Game is not finished", false);
        }
    }
    catch (const std::runtime_error&)
    {
        return BaseResponse("Game does not exist", false);
    }

    return BaseResponse(true);
}
