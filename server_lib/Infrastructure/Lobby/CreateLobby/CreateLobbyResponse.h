#ifndef CREATELOBBYRESPONSE_H
#define CREATELOBBYRESPONSE_H
#include "../../BaseResponse.h"


class CreateLobbyResponse : public BaseResponse {
public:
    CreateLobbyResponse(int iLobbyId);
    CreateLobbyResponse(const std::string& strContent);
    virtual int getLobbyId() const;

    crow::json::wvalue convertToJson() const override;
private:
    int m_iLobbyId;
};



#endif //CREATELOBBYRESPONSE_H
