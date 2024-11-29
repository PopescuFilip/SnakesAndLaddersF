//
// Created by Alexandru Pestritu on 29.11.2024.
//

#include "GameStats.h"
#include <sstream>

GameStats::GameStats() : gameDurationInSeconds(0) {}

GameStats::GameStats(int gameDurationInSeconds, const std::vector<Player>& players)
        : gameDurationInSeconds(gameDurationInSeconds), players(players) {}

int GameStats::getGameDurationInSeconds() const { return gameDurationInSeconds; }
void GameStats::setGameDurationInSeconds(int value) { gameDurationInSeconds = value; }

std::vector<Player> GameStats::getPlayers() const { return players; }
void GameStats::setPlayers(const std::vector<Player>& value) { players = value; }

std::string GameStats::getFormattedGameDuration() const {
    int minutes = gameDurationInSeconds / 60;
    int seconds = gameDurationInSeconds % 60;

    std::ostringstream formattedDuration;
    formattedDuration << minutes << "m " << seconds << "s";

    return formattedDuration.str();
}

void to_json(nlohmann::json& j, const GameStats& gs) {
    j = nlohmann::json{
                {"gameDurationInSeconds", gs.gameDurationInSeconds},
                {"players", gs.players}
    };
}

void from_json(const nlohmann::json& j, GameStats& gs) {
    j.at("gameDurationInSeconds").get_to(gs.gameDurationInSeconds);
    j.at("players").get_to(gs.players);
}

