#include "BaseService.h"
#include <stdexcept>
#include <iostream>

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
        notifyFailure(lastErrorMessage);
        throw std::runtime_error(lastErrorMessage);
    }

    try {
        return nlohmann::json::parse(response.text);
    } catch (const std::exception& e) {
        lastErrorMessage = "Failed to parse GET response: " + std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

nlohmann::json BaseService::executePost(const std::string& url, const nlohmann::json& body) {
    cpr::Response response = cpr::Post(
        cpr::Url{url},
        cpr::Body{body.dump()},
        cpr::Header{{"Content-Type", "application/json"}}
    );

    if (response.status_code != 200) {
        lastErrorMessage = "POST request failed with status code: " + std::to_string(response.status_code);
        notifyFailure(lastErrorMessage);
        throw std::runtime_error(lastErrorMessage);
    }

    try {
        return nlohmann::json::parse(response.text);
    } catch (const std::exception& e) {
        lastErrorMessage = "Failed to parse POST response: " + std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

BaseResponse BaseService::parseBaseResponse(const nlohmann::json& responseJson) {
    BaseResponse baseResponse;
    if (responseJson.contains("success") && responseJson.contains("message")) {
        baseResponse = responseJson.get<BaseResponse>();
    } else {
        lastErrorMessage = "Response does not contain expected BaseResponse fields.";
        notifyFailure(lastErrorMessage);
        throw std::runtime_error(lastErrorMessage);
    }
    return baseResponse;
}

void BaseService::ensureSuccess(const BaseResponse& response) {
    if (!response.isSuccess()) {
        lastErrorMessage = response.getMessage();
        notifyFailure(lastErrorMessage);
        throw std::runtime_error(lastErrorMessage);
    }
}

std::string BaseService::getLastErrorMessage() const {
    return lastErrorMessage;
}

void BaseService::notifySuccess(const std::string& message) {
    notifyObservers("SUCCESS - " + message);
}

void BaseService::notifyFailure(const std::string& errorMessage) {
    notifyObservers("ERROR - " + errorMessage);
}
