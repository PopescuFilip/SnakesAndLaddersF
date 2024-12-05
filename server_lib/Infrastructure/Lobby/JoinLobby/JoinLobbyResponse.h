#ifndef JOINLOBBYRESPONSE_H
#define JOINLOBBYRESPONSE_H

#include <list>
#include <optional>

#include "../../BaseResponse.h"
#include "../../../GameManagement/Objects/Lobby.h"
#include "../../../GameManagement/Objects/MapTypeEnum.h"
#include "../../../GameManagement/Objects/Player.h"


class JoinLobbyResponse : public BaseResponse {
public:
    JoinLobbyResponse(const std::string& message);
    JoinLobbyResponse(const Lobby& lobby);
    crow::json::wvalue convertToJson() const override;

private:
    std::optional<Lobby> m_lobby;
};



#endif //JOINLOBBYRESPONSE_H
