//
// Created by Tudor Andrei on 20.11.2024.
//

#include "GameStatusContext.h"

#include "GameManagement/Game/GameManager.h"

GameStatusResponse GameStatusContext::HandleRequest(const GameStatusRequest &request) {
    ValidationResponse validationResponse = ValidateRequest(request);
    if (!validationResponse.isValid()) {
        return GameStatusResponse{validationResponse.getMessage()};
    }

    return ApplyChanges(request);
}

GameStatusResponse GameStatusContext::ApplyChanges(const GameStatusRequest &request) {
    RunningGame game = GameManager::getInstance().getRunningGame(request.getGameId());
    return GameStatusResponse{ game };
}

ValidationResponse GameStatusContext::ValidateRequest(const GameStatusRequest &request) {

    try
    {
        RunningGame game = GameManager::getInstance().getRunningGame(request.getGameId());
    }
    catch (const std::runtime_error&)
    {
        return ValidationResponse{ false, "Game not found" };
    }

    return ValidationResponse{true};
}
