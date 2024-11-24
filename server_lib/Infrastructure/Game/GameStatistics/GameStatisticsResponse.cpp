//
// Created by Tudor Andrei on 23.11.2024.
//

#include "GameStatisticsResponse.h"

GameStatisticsResponse::GameStatisticsResponse(const std::string &message) : BaseResponse{message} {
}

GameStatisticsResponse::GameStatisticsResponse(const std::vector<Player> &players, int gameDurationInSeconds) : BaseResponse{true}, m_Players{players}, m_GameDurationInSeconds{gameDurationInSeconds} {
}

int GameStatisticsResponse::getGameDurationInSeconds() const {
    return m_GameDurationInSeconds;
}

const std::vector<Player> &GameStatisticsResponse::getPlayers() const {
    return m_Players;
}

crow::json::wvalue GameStatisticsResponse::convertToJson() const {
    crow::json::wvalue jsonResponse;

    jsonResponse["success"] = getSuccess();
    jsonResponse["message"] = getMessage();
    jsonResponse["gameData"]["gameDurationInSeconds"] = m_GameDurationInSeconds;

    crow::json::wvalue::list playersJson;
    for (const Player& player : m_Players) {
        playersJson.push_back(player.convertToJson());
    }

    jsonResponse["gameData"]["players"] = std::move(playersJson);

    return jsonResponse;
}
