//
// Created by Tudor Andrei on 23.11.2024.
//

#include "LeaveGameResponse.h"

LeaveGameResponse::LeaveGameResponse(const std::string &message) : BaseResponse{message} {}

LeaveGameResponse::LeaveGameResponse(bool bSuccess) : BaseResponse{bSuccess} {}

crow::json::wvalue LeaveGameResponse::convertToJson() const {
    crow::json::wvalue jsonResponse;
    jsonResponse["success"] = getSuccess();
    jsonResponse["message"] = getMessage();
    return jsonResponse;
}
