#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "../Objects/Lobby.h"
#include "../Objects/RunningGame.h"

constexpr int DICE_ROLL_MIN = 1;
constexpr int DICE_ROLL_MAX = 6;

constexpr int MAX_WAIT_UNTIL_GAME_FINISH_SECONDS = 5;


class GameManager {
public:
    static GameManager& getInstance();

    RunningGame createGame(const Lobby& lobby);
    RunningGame getRunningGame(int gameId) const;

    bool removeGame(int gameId);
    bool updateGame(int gameId, const RunningGame& newGameDetails);

    void rollDiceInGame(int gameId);
private:
    std::vector<RunningGame> m_Games;

    static void createGameThread(int gameId);

    static int generateRandomNumber(int min, int max);

    RunningGame &getRunningGamePtr(int gameId) const;
};

#endif //GAMEMANAGER_H
