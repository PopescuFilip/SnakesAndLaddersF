#ifndef LOBBYSTATUSRESPONSE_H
#define LOBBYSTATUSRESPONSE_H

#include <optional>

#include "../../BaseResponse.h"
#include "../../../GameManagement/Objects/Lobby.h"

class LobbyStatusResponse : public BaseResponse {
public:
    LobbyStatusResponse(const std::string& message);
    LobbyStatusResponse(const Lobby& lobby);
    crow::json::wvalue convertToJson() const override;

private:
    std::optional<Lobby> m_lobby;
};



#endif //LOBBYSTATUSRESPONSE_H
