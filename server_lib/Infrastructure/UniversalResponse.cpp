#include "UniversalResponse.h"
#include "JsonSerializer.h"

UniversalResponse::UniversalResponse(int lobbyId) :
	BaseResponse{ true },
	m_lobbyId{ lobbyId }
{}

crow::json::wvalue UniversalResponse::convertToJson() const
{
	auto json{ getBasicJson() };

	if (m_lobbyId.has_value())
		JsonSerializer::serializeLobbyId(json, *m_lobbyId);

	return json;
}
