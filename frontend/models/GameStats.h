//
// Created by Alexandru Pestritu on 29.11.2024.
//

#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <string>
#include <vector>
#include "Player.h"
#include <nlohmann/json.hpp>

class GameStats {
private:
    int gameDurationInSeconds;
    std::vector<Player> players;

public:
    GameStats();
    GameStats(int gameDurationInSeconds, const std::vector<Player>& players);

    int getGameDurationInSeconds() const;
    void setGameDurationInSeconds(int value);

    std::vector<Player> getPlayers() const;
    void setPlayers(const std::vector<Player>& value);

    std::string getFormattedGameDuration() const;

    friend void to_json(nlohmann::json& j, const GameStats& gs);
    friend void from_json(const nlohmann::json& j, GameStats& gs);
};




#endif //GAMESTATS_H
