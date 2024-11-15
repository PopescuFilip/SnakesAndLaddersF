#ifndef CREATELOBBYRESPONSE_H
#define CREATELOBBYRESPONSE_H
#include "../../BaseResponse.h"


class CreateLobbyResponse : protected BaseResponse {
public:
    CreateLobbyResponse(int iLobbyId);
    CreateLobbyResponse(const std::string& strContent);
    int getLobbyId() const;
private:
    int m_iLobbyId;
};



#endif //CREATELOBBYRESPONSE_H
