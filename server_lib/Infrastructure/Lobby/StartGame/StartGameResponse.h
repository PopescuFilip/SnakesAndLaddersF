#ifndef STARTGAMERESPONSE_H
#define STARTGAMERESPONSE_H
#include "Infrastructure/BaseResponse.h"


class StartGameResponse : public BaseResponse {
public:
    explicit StartGameResponse(bool isValid);
    explicit StartGameResponse(const std::string& strMessage);
    crow::json::wvalue convertToJson() const override;
};



#endif //STARTGAMERESPONSE_H
