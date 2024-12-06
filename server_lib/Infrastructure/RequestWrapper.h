#ifndef REQUESTWRAPPER_H
#define REQUESTWRAPPER_H

#include <crow.h>
#include "GameManagement/Objects/MapTypeEnum.h"

class RequestWrapper
{
public:
	RequestWrapper(const crow::json::rvalue& request);

	inline std::string getUsername() const { return m_request["playerUsername"].s(); }
	inline int getLobbyId() const { return m_request["lobbyId"].i(); }
	inline int getGameId() const { return  m_request["gameId"].i(); }
	inline int getMaxPlayers() const { return m_request["maxPlayers"].i(); }
	inline MapType getMapType() const { return static_cast<MapType>(m_request["mapType"].i()); }
	inline std::string getAdminUsername() const { return m_request["adminUsername"].s(); }

private:
	crow::json::rvalue m_request;
};

#endif // REQUESTWRAPPER_H

