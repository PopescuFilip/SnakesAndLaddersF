#ifndef RUNNINGGAME_H
#define RUNNINGGAME_H
#include "Lobby.h"


class RunningGame {
public:
    RunningGame();
    RunningGame(const Lobby& baseLobby);
    void updatePlayerPosition(const std::string& strUsername, int iPosition);
    int getGameId() const;
    bool isNull = false;
private:
    int gameId; // Unique identifier for the game
    std::vector <Player> m_Players;
};



#endif //RUNNINGGAME_H
