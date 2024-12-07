#include "UniversalResponse.h"
#include "JsonSerializer.h"

UniversalResponse::UniversalResponse(int lobbyId) :
	BaseResponse{ true },
	m_lobbyId{ lobbyId }
{}

UniversalResponse::UniversalResponse(const Lobby& lobby) :
	BaseResponse{ true },
	m_lobby{ lobby }
{}

UniversalResponse::UniversalResponse(const RunningGame& game) :
	BaseResponse{ true },
	m_game{ game }
{}

UniversalResponse::UniversalResponse(const std::vector<Player>& players, int gameDurationInSeconds) :
	BaseResponse{ true },
	m_players{ players },
	m_gameDurationInSeconds{ gameDurationInSeconds }
{}

crow::json::wvalue UniversalResponse::convertToJson() const
{
	auto json{ getBasicJson() };

	if (m_lobbyId.has_value())
		JsonSerializer::serializeLobbyId(json, *m_lobbyId);

	if (m_lobby.has_value())
		JsonSerializer::serializeLobby(json, *m_lobby);

	if (m_game.has_value())
		JsonSerializer::serializeGame(json, *m_game);

	if (m_players.has_value() && m_gameDurationInSeconds.has_value())
		JsonSerializer::serializeGameData(json, *m_players, *m_gameDurationInSeconds);

	return json;
}
