#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include <crow/json.h>
#include "GameManagement/Objects/RunningGame.h"

class JsonSerializer
{
public:
	inline static void serializeSuccess(crow::json::wvalue& json, bool succes) { json["succes"] = succes; }
	inline static void serializeMessage(crow::json::wvalue& json, const std::string& message) { json["message"] = message; }
	inline static void serializeLobbyId(crow::json::wvalue& json, int lobbyId) { json["lobbyId"] = lobbyId; }
	inline static void serializeLobby(crow::json::wvalue& json, const Lobby& lobby) { json["lobby"] = lobby.convertToJson(); }
	inline static void serializeGame(crow::json::wvalue& json, const RunningGame& game) { json["game"] = game.convertToJson(); }
	static void serializeGameData(crow::json::wvalue& json, const std::vector<Player>& players, int gameDurationInSeconds);
};

#endif // JSONSERIALIZER_H