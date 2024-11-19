//
// Created by Alexandru Pestritu on 18.11.2024.
//
#include "BaseResponse.h"

BaseResponse::BaseResponse() : success(false), message("") {}
BaseResponse::BaseResponse(bool success, const std::string& message) : success(success), message(message) {}

bool BaseResponse::isSuccess() const { return success; }
void BaseResponse::setSuccess(bool value) { success = value; }

std::string BaseResponse::getMessage() const { return message; }
void BaseResponse::setMessage(const std::string& value) { message = value; }

void to_json(nlohmann::json& j, const BaseResponse& r) {
    j = nlohmann::json{{"success", r.success}, {"message", r.message}};
}

void from_json(const nlohmann::json& j, BaseResponse& r) {
    j.at("success").get_to(r.success);
    j.at("message").get_to(r.message);
}
