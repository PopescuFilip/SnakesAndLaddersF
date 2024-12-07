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

    try
    {
        RunningGame runningGame = GameManager::getInstance().getRunningGame(request.getGameId());

        if (!runningGame.getShouldFinishGame()) {
            return ValidationResponse{ false, "Game is not finished" };
        }
    }
    catch (const std::runtime_error&)
    {
        return ValidationResponse{ false, "Game does not exist" };
    }

    return ValidationResponse{true};
}
