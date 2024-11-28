#ifndef RUNNINGGAME_H
#define RUNNINGGAME_H
#include "BaseObject.h"
#include "Lobby.h"

#include <unordered_map>

constexpr int DICE_ROLL_TIME_SECONDS = 2;
constexpr int MAX_SECONDS_PER_TURN = 30;

constexpr int MAX_BOARD_POSITION = 100;

class RunningGame : public BaseObject {
public:
    RunningGame();
    explicit RunningGame(const Lobby& baseLobby);

    virtual void updatePlayerPosition(const std::string& strUsername, int iPosition);

    virtual void startNewTurn();
    virtual int getCurrentTurnTime() const;

    virtual int getNewTeleportPosition(int currentPlayerPosition) const;

    virtual void triggerDiceRolling();
    virtual void resetTriggerDiceRolling();
    virtual bool getDiceRolling() const;

    virtual void setLatestDiceValue(int iDiceValue);
    virtual int getLatestDiceValue() const;

    virtual void setPlayerTurn(const std::string& strPlayerName);
    virtual Player& getCurrentPlayer();

    virtual void setShouldFinishGame(bool bShouldFinishGame);
    virtual bool getShouldFinishGame() const;

    virtual int getGameId() const;
    virtual void readTeleportPositions(const MapType& mapType);

    virtual bool removePlayer(const std::string& strUsername);

    virtual const std::vector<Player>& getPlayers() const;
    virtual int getTotalTime() const;

    crow::json::wvalue convertToJson() const override;

    bool isNull = false;

private:
    int m_GameId;

    std::chrono::system_clock::time_point m_GameStartTime;
    std::chrono::system_clock::time_point m_DiceRollStartTime;
    std::chrono::system_clock::time_point m_TurnStartTime;

    int m_iCurrentPlayerIndex;
    std::unordered_map<int, int> m_TeleportPositions;
    std::vector <Player> m_Players;
    bool m_bShouldFinishGame;

    int m_iLatestDiceValue;
    int m_iTotalGameTime;

    void initializePlayerPositions();
};



#endif //RUNNINGGAME_H
