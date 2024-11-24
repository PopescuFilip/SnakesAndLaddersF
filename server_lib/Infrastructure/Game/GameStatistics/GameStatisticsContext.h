#ifndef GAMESTATISTICSCONTEXT_H
#define GAMESTATISTICSCONTEXT_H
#include "GameStatisticsRequest.h"
#include "GameStatisticsResponse.h"
#include "Infrastructure/BaseContext.h"


class GameStatisticsContext : public BaseContext<GameStatisticsRequest, GameStatisticsResponse> {
public:
    GameStatisticsResponse HandleRequest(const GameStatisticsRequest &request) override;

protected:
    GameStatisticsResponse ApplyChanges(const GameStatisticsRequest &request) override;

    ValidationResponse ValidateRequest(const GameStatisticsRequest &request) override;
};



#endif //GAMESTATISTICSCONTEXT_H
