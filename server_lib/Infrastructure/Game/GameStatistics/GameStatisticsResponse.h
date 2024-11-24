#ifndef GAMESTATISTICSRESPONSE_H
#define GAMESTATISTICSRESPONSE_H
#include <vector>

#include "Infrastructure/BaseResponse.h"
#include "GameManagement/Objects/Player.h"

class GameStatisticsResponse final: public BaseResponse {
public:
    GameStatisticsResponse(const std::string& message);
    GameStatisticsResponse(const std::vector<Player> &players, int gameDurationInSeconds);

    int getGameDurationInSeconds() const;
    const std::vector<Player>& getPlayers() const;

    crow::json::wvalue convertToJson() const override;

private:
    int m_GameDurationInSeconds;
    std::vector<Player> m_Players;
};



#endif //GAMESTATISTICSRESPONSE_H
