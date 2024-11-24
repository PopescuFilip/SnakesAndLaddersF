#include "RollDiceContext.h"

#include "GameManagement/Game/GameManager.h"
#include "GameManagement/Objects/RunningGame.h"

RollDiceResponse RollDiceContext::HandleRequest(const RollDiceRequest &request) {
    ValidationResponse validationResponse = ValidateRequest(request);
    if(!validationResponse.isValid()) {
        return RollDiceResponse(validationResponse.getMessage());
    }

    return ApplyChanges(request);
}

RollDiceResponse RollDiceContext::ApplyChanges(const RollDiceRequest &request) {
    GameManager::getInstance().rollDiceInGame(request.getGameId());
    return RollDiceResponse(true);
}

ValidationResponse RollDiceContext::ValidateRequest(const RollDiceRequest &request) {
    RunningGame game = GameManager::getInstance().getRunningGame(request.getGameId());
    if(game.getGameId() == 0) {
        return ValidationResponse(false, "Game not found");
    }

    if (game.getCurrentPlayer().getUsername() != request.getPlayerName()) {
        return ValidationResponse(false, "It's not your turn");
    }
    return ValidationResponse(true);
}
