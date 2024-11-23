//
// Created by Tudor Andrei on 23.11.2024.
//

#include "GameStatisticsContext.h"

#include "GameManagement/Game/GameManager.h"
#include "GameManagement/Objects/RunningGame.h"

GameStatisticsResponse GameStatisticsContext::HandleRequest(const GameStatisticsRequest &request) {
    if (const ValidationResponse validationResponse = ValidateRequest(request); !validationResponse.isValid()) {
        return GameStatisticsResponse{validationResponse.getMessage()};
    }

    return ApplyChanges(request);
}

GameStatisticsResponse GameStatisticsContext::ApplyChanges(const GameStatisticsRequest &request) {
    RunningGame runningGame = GameManager::getInstance().getRunningGame(request.getGameId());
    GameStatisticsResponse response {runningGame.getPlayers(), runningGame.getTotalTime()};

    return response;
}

ValidationResponse GameStatisticsContext::ValidateRequest(const GameStatisticsRequest &request) {
    RunningGame runningGame = GameManager::getInstance().getRunningGame(request.getGameId());
    if (runningGame.isNull) {
        return ValidationResponse{false, "Game does not exist"};
    }

    if (!runningGame.getShouldFinishGame()) {
        return ValidationResponse{false, "Game is not finished"};
    }

    return ValidationResponse{true};
}
