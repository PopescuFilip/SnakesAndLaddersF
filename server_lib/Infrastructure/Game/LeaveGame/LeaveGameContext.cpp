//
// Created by Tudor Andrei on 23.11.2024.
//

#include "LeaveGameContext.h"

#include "GameManagement/Game/GameManager.h"
#include "GameManagement/Objects/RunningGame.h"

LeaveGameResponse LeaveGameContext::HandleRequest(const LeaveGameRequest &request) {
    if (const ValidationResponse validationResponse = ValidateRequest(request); !validationResponse.isValid()) {
        return LeaveGameResponse{validationResponse.getMessage()};
    }

    return ApplyChanges(request);
}

LeaveGameResponse LeaveGameContext::ApplyChanges(const LeaveGameRequest &request) {
    RunningGame runningGame = GameManager::getInstance().getRunningGame(request.getGameId());
    bool result = runningGame.removePlayer(request.getPlayerUsername());

    if (!result) {
        const std::string message = "Failed to leave game";
        return LeaveGameResponse(message);
    }

    GameManager::getInstance().updateGame(request.getGameId(), runningGame);

    return LeaveGameResponse{true};
}

ValidationResponse LeaveGameContext::ValidateRequest(const LeaveGameRequest &request) {
    RunningGame runningGame = GameManager::getInstance().getRunningGame(request.getGameId());

    if (runningGame.isNull) {
        return ValidationResponse{false, "Game does not exist"};
    }

    return ValidationResponse{true};
}
