#ifndef RUNNINGGAME_H
#define RUNNINGGAME_H
#include "Lobby.h"

class RunningGame {
public:
    RunningGame();
    explicit RunningGame(const Lobby& baseLobby);
    void updatePlayerPosition(const std::string& strUsername, int iPosition);
    int getGameId() const;
    bool isNull = false;

private:
    int gameId;
    std::chrono::system_clock m_StartTime;
    bool m_bIsDiceRolling;
    int m_iDiceRollValue;
    int m_iCurrentPlayerIndex;

    std::vector <Player> m_Players;
    bool m_bShouldFinishGame;
};



#endif //RUNNINGGAME_H
