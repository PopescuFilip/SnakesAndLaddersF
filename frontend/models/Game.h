//
// Created by Alexandru Pestritu on 27.11.2024.
//

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Player.h"
#include "TurnTime.h"
#include <nlohmann/json.hpp>

class Game {
private:
    int gameId;
    int playerTurnIndex;
    std::vector<Player> players;
    TurnTime turnTime;
    bool diceRolling;
    int latestDiceValue;
    bool shouldFinishGame;

public:
    Game();
    Game(int gameId, int playerTurnIndex, const std::vector<Player>& players, const TurnTime& turnTime,
         bool diceRolling, int latestDiceValue, bool shouldFinishGame);

    int getGameId() const;
    void setGameId(int value);

    int getPlayerTurnIndex() const;
    void setPlayerTurnIndex(int value);

    std::vector<Player> getPlayers() const;
    void setPlayers(const std::vector<Player>& value);

    TurnTime getTurnTime() const;
    void setTurnTime(const TurnTime& value);

    bool isDiceRolling() const;
    void setDiceRolling(bool value);

    int getLatestDiceValue() const;
    void setLatestDiceValue(int value);

    bool getShouldFinishGame() const;
    void setShouldFinishGame(bool value);

    friend void to_json(nlohmann::json& j, const Game& g);
    friend void from_json(const nlohmann::json& j, Game& g);
};

#endif //GAME_H
