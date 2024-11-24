//
// Created by Tudor Andrei on 23.11.2024.
//

#ifndef LEAVEGAMERESPONSE_H
#define LEAVEGAMERESPONSE_H
#include "Infrastructure/BaseResponse.h"


class LeaveGameResponse : public BaseResponse {
public:
    explicit LeaveGameResponse(const std::string& message);
    LeaveGameResponse(bool bSuccess);
    crow::json::wvalue convertToJson() const override;
};



#endif //LEAVEGAMERESPONSE_H
