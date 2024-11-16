#include "UpdateSettingsResponse.h"

UpdateSettingsResponse::UpdateSettingsResponse(const std::string &message) : BaseResponse(message) {
}

UpdateSettingsResponse::UpdateSettingsResponse(bool isValid) : BaseResponse(isValid) {
}

crow::json::wvalue UpdateSettingsResponse::convertToJson() const {
    crow::json::wvalue jsonResponse;
    jsonResponse["success"] = getSuccess();
    jsonResponse["message"] = getMessage();

    return jsonResponse;
}
