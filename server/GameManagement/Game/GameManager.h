#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "../Objects/Lobby.h"
#include "../Objects/RunningGame.h"


class GameManager {
public:
    static GameManager getInstance();

    void createGame(const Lobby& lobby);
    void removeGame(int gameId);
    RunningGame getRunningGame(int gameId) const;
private:
    std::list<RunningGame> m_Games;
};



#endif //GAMEMANAGER_H
