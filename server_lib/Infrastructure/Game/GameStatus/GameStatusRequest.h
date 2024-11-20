#ifndef GAMESTATUSREQUEST_H
#define GAMESTATUSREQUEST_H



class GameStatusRequest {
public:
    GameStatusRequest(int gameId);

    int getGameId() const;
private:
    int m_GameId;
};



#endif //GAMESTATUSREQUEST_H
