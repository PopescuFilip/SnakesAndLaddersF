#ifndef GAMESTATISTICSREQUEST_H
#define GAMESTATISTICSREQUEST_H



class GameStatisticsRequest {
public:
    GameStatisticsRequest(int gameId);
    int getGameId() const;

private:
    int m_GameId;
};



#endif //GAMESTATISTICSREQUEST_H
