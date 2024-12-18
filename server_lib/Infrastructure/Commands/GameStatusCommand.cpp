#include "GameStatusCommand.h"
#include "GameManagement/Game/GameManager.h"
#include "Infrastructure/UniversalResponse.h"

GameStatusCommand::GameStatusCommand(const crow::json::rvalue& request) :
    HttpCommand{ request },
    m_gameId{ m_request.getGameId() }
{}

BaseResponsePtr GameStatusCommand::execute()
{
    RunningGame game = GameManager::getInstance().getRunningGame(m_gameId);
    return std::make_unique<UniversalResponse>(game);
}

BaseResponse GameStatusCommand::checkCanExecute() const
{
    try
    {
        RunningGame game = GameManager::getInstance().getRunningGame(m_gameId);
    }
    catch (const std::runtime_error&)
    {
        return BaseResponse("Game not found", false);
    }

    return BaseResponse(true);
}
