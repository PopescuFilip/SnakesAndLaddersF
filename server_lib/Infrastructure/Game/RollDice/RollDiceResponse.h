#ifndef ROLLDICERESPONSE_H
#define ROLLDICERESPONSE_H
#include "Infrastructure/BaseResponse.h"


class RollDiceResponse : public BaseResponse{
public:
    explicit RollDiceResponse(bool success);
    explicit RollDiceResponse(const std::string& message);
    crow::json::wvalue convertToJson() const override;
};



#endif //ROLLDICERESPONSE_H
