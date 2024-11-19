#ifndef UPDATESETTINGSRESPONSE_H
#define UPDATESETTINGSRESPONSE_H
#include "../../BaseResponse.h"


class UpdateSettingsResponse : public BaseResponse {
public:
    UpdateSettingsResponse(const std::string& message);
    UpdateSettingsResponse(bool isValid);
    crow::json::wvalue convertToJson() const override;
};


#endif //UPDATESETTINGSRESPONSE_H
