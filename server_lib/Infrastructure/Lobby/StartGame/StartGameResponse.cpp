#include "StartGameResponse.h"

StartGameResponse::StartGameResponse(bool isValid) : BaseResponse{isValid} {}

StartGameResponse::StartGameResponse(const std::string &strMessage) : BaseResponse{strMessage} {}

crow::json::wvalue StartGameResponse::convertToJson() const {
    crow::json::wvalue json;
    json["success"] = getSuccess();
    json["message"] = getMessage();

    return json;
}


