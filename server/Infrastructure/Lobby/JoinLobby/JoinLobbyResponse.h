#ifndef JOINLOBBYRESPONSE_H
#define JOINLOBBYRESPONSE_H
#include <list>

#include "../../BaseResponse.h"
#include "../../../GameManagement/Objects/MapTypeEnum.h"
#include "../../../GameManagement/Objects/Player.h"


class JoinLobbyResponse : public BaseResponse {
public:
    JoinLobbyResponse(const std::string& message);
    JoinLobbyResponse(int lobbyId, const std::string& strAdminUsername, const std::list<Player>& players, MapType mapType);
    crow::json::wvalue convertToJson() const override;

private:
    int m_lobbyId;
    std::string m_strAdminUsername;
    std::list<Player> m_players;
    MapType m_mapType;
};



#endif //JOINLOBBYRESPONSE_H
