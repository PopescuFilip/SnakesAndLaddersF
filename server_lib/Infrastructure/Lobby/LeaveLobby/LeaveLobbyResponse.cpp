//
// Created by Tudor Andrei on 17.11.2024.
//

#include "LeaveLobbyResponse.h"

LeaveLobbyResponse::LeaveLobbyResponse(const std::string &message) : BaseResponse{message} {
}

LeaveLobbyResponse::LeaveLobbyResponse(const bool result) : BaseResponse{result} {
}

crow::json::wvalue LeaveLobbyResponse::convertToJson() const {
    crow::json::wvalue json;
    json["message"] = getMessage();
    json["result"] = getSuccess();
    return json;
}
