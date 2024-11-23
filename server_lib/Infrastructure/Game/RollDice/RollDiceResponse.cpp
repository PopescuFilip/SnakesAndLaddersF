#include "RollDiceResponse.h"

RollDiceResponse::RollDiceResponse(bool success) : BaseResponse{success} {
}

RollDiceResponse::RollDiceResponse(const std::string &message) : BaseResponse{message} {
}

crow::json::wvalue RollDiceResponse::convertToJson() const {
    crow::json::wvalue json;
    json["success"] = getSuccess();
    json["message"] = getMessage();
    return json;
}