#include "RollDiceCommand.h"
#include "GameManagement/Game/GameManager.h"

RollDiceCommand::RollDiceCommand(const crow::json::rvalue& request) :
    HttpCommand{ request },
    m_gameId{ m_request.getGameId() },
    m_username{ m_request.getUsername() }
{}

BaseResponsePtr RollDiceCommand::execute()
{
    GameManager::getInstance().rollDiceInGame(m_gameId);
    return std::make_unique<BaseResponse>(true);
}

BaseResponse RollDiceCommand::checkCanExecute() const
{
    RunningGame game = GameManager::getInstance().getRunningGame(m_gameId);
    if (game.getGameId() == 0)
        return BaseResponse("Game not found");

    if (game.getCurrentPlayer().getUsername() != m_username)
        return BaseResponse("It's not your turn");

    if (game.getDiceRolling())
        return BaseResponse("Dice is already rolling");

    return BaseResponse(true);
}
