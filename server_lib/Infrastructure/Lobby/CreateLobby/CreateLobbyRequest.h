#ifndef CREATELOBBYREQUEST_H
#define CREATELOBBYREQUEST_H
#include <string>
#include "../../../GameManagement/Objects/MapTypeEnum.h"

class CreateLobbyRequest{
public:
    CreateLobbyRequest(MapType mapType, int iMaxPlayers, const std::string& strAdminUsername);
    virtual MapType getMapType() const;
    virtual int getMaxPlayers() const;
    virtual const std::string& getAdminUsername() const;
private:
    MapType m_MapType;
    int m_iMaxPlayers;
    std::string m_strAdminUsername;
};



#endif //CREATELOBBYREQUEST_H
