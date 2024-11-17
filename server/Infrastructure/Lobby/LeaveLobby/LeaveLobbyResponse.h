#ifndef LEAVELOBBYRESPONSE_H
#define LEAVELOBBYRESPONSE_H
#include "../../BaseResponse.h"


class LeaveLobbyResponse final : public BaseResponse {
public:
    explicit LeaveLobbyResponse(const std::string& message);
    explicit LeaveLobbyResponse(bool result);
    crow::json::wvalue convertToJson() const override;
};



#endif //LEAVELOBBYRESPONSE_H
