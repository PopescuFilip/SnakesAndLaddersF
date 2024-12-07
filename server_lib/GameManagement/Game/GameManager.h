#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "../Objects/Lobby.h"
#include "../Objects/RunningGame.h"

constexpr int MAX_WAIT_UNTIL_GAME_FINISH_SECONDS = 5;

class GameManager {
public:
    static GameManager& getInstance();

    virtual RunningGame createGame(const Lobby& lobby);
    virtual RunningGame getRunningGame(int gameId) const;

    virtual bool removeGame(int gameId);
    virtual bool updateGame(int gameId, const RunningGame& newGameDetails);

    virtual void rollDiceInGame(int gameId);
private:
    std::vector<RunningGame> m_Games;

    static void createGameThread(int gameId);

    RunningGame &getRunningGamePtr(int gameId) const;
};

#endif //GAMEMANAGER_H
