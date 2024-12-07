#ifndef UNIVERSALRESPONSE_H
#define UNIVERSALRESPONSE_H

#include <optional>
#include "BaseResponse.h"
#include "GameManagement/Objects/RunningGame.h"

class UniversalResponse : public BaseResponse
{
public:
	UniversalResponse(int lobbyId);
	UniversalResponse(const Lobby& lobby);
	UniversalResponse(const RunningGame& game);
	UniversalResponse(const std::vector<Player>& players, int gameDurationInSeconds);

	virtual crow::json::wvalue convertToJson() const override;
private:
	std::optional<int> m_lobbyId;
	std::optional<int> m_gameDurationInSeconds;
	std::optional<Lobby> m_lobby;
	std::optional<RunningGame> m_game;
	std::optional<std::vector<Player>> m_players;
};

#endif // UNIVERSALRESPONSE_H
