#ifndef UPDATESETTINGSREQUEST_H
#define UPDATESETTINGSREQUEST_H
#include <string>

#include "../../../GameManagement/Objects/MapTypeEnum.h"


class UpdateSettingsRequest {
public:
    UpdateSettingsRequest(int lobbyId, const std::string& strPlayerUsername, MapType mapType, int maxPlayers);
    int getLobbyId() const;
    std::string getPlayerUsername() const;
    MapType getMapType() const;
    int getMaxPlayers() const;

private:
    int m_iLobbyId;
    std::string m_strPlayerUsername;
    MapType m_MapType;
    int m_iMaxPlayers;
};



#endif //UPDATESETTINGSREQUEST_H
