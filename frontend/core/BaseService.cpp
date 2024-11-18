//
// Created by Alexandru Pestritu on 18.11.2024.
//
#include "BaseService.h"

BaseService::BaseService() : lastErrorMessage("") {}
BaseService::~BaseService() {}

nlohmann::json BaseService::executeGet(const std::string& url, const nlohmann::json& body) {
    cpr::Response response = cpr::Get(
        cpr::Url{url},
        cpr::Body{body.dump()},
        cpr::Header{{"Content-Type", "application/json"}}
    );

    if (response.status_code != 200) {
        lastErrorMessage = "GET request failed with status code: " + std::to_string(response.status_code);
        throw std::runtime_error(lastErrorMessage);
    }

    return nlohmann::json::parse(response.text);
}

nlohmann::json BaseService::executePost(const std::string& url, const nlohmann::json& body) {
    cpr::Response response = cpr::Post(
        cpr::Url{url},
        cpr::Body{body.dump()},
        cpr::Header{{"Content-Type", "application/json"}}
    );

    if (response.status_code != 200) {
        lastErrorMessage = "POST request failed with status code: " + std::to_string(response.status_code);
        throw std::runtime_error(lastErrorMessage);
    }

    return nlohmann::json::parse(response.text);
}

BaseResponse BaseService::parseBaseResponse(const nlohmann::json& responseJson) {
    BaseResponse baseResponse;
    if (responseJson.contains("success") && responseJson.contains("message")) {
        baseResponse = responseJson.get<BaseResponse>();
    } else {
        lastErrorMessage = "Response does not contain expected BaseResponse fields.";
        throw std::runtime_error(lastErrorMessage);
    }
    return baseResponse;
}

void BaseService::ensureSuccess(const BaseResponse& response) {
    if (!response.isSuccess()) {
        lastErrorMessage = response.getMessage();
        throw std::runtime_error(lastErrorMessage);
    }
}

std::string BaseService::getLastErrorMessage() const {
    return lastErrorMessage;
}
