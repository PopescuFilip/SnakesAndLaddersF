#include "JsonSerializer.h"

void JsonSerializer::serializeGameData(crow::json::wvalue& json, const std::vector<Player>& players, int gameDurationInSeconds)
{
    json["gameData"]["gameDurationInSeconds"] = gameDurationInSeconds;

    crow::json::wvalue::list playersJson;
    for (const Player& player : players)
    {
        playersJson.push_back(player.convertToJson());
    }

    json["gameData"]["players"] = std::move(playersJson);
}