#ifndef RUNNINGGAME_H
#define RUNNINGGAME_H
#include "BaseObject.h"
#include "Lobby.h"

constexpr int DICE_ROLL_TIME_SECONDS = 2;
constexpr int MAX_SECONDS_PER_TURN = 30;

class RunningGame : public BaseObject {
public:
    RunningGame();
    explicit RunningGame(const Lobby& baseLobby);
    void updatePlayerPosition(const std::string& strUsername, int iPosition);

    void startNewTurn();
    int getCurrentTurnTime() const;

    MapType getMapType() const;

    void triggerDiceRolling();
    void resetTriggerDiceRolling();
    bool getDiceRolling() const;

    void setLatestDiceValue(int iDiceValue);
    int getLatestDiceValue() const;

    void setPlayerTurn(const std::string& strPlayerName);
    Player& getCurrentPlayer();

    void setShouldFinishGame(bool bShouldFinishGame);
    bool getShouldFinishGame() const;

    int getGameId() const;

    crow::json::wvalue convertToJson() const override;

    bool isNull = false;

private:
    int m_GameId;

    std::chrono::system_clock::time_point m_GameStartTime;
    std::chrono::system_clock::time_point m_DiceRollStartTime;
    std::chrono::system_clock::time_point m_TurnStartTime;

    int m_iCurrentPlayerIndex;
    MapType m_MapType;
    std::vector <Player> m_Players;
    bool m_bShouldFinishGame;

    int m_iLatestDiceValue;
};



#endif //RUNNINGGAME_H
