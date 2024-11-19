#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "../Objects/Lobby.h"
#include "../Objects/RunningGame.h"


class GameManager {
public:
    static GameManager& getInstance();

    RunningGame createGame(const Lobby& lobby);
    RunningGame getRunningGame(int gameId) const;

    bool removeGame(int gameId);
    bool updateGame(int gameId, const RunningGame& newGameDetails);
private:
    std::vector<RunningGame> m_Games;
};



#endif //GAMEMANAGER_H
