//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef BASESERVICE_H
#define BASESERVICE_H

#include <string>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include "../Core/BaseResponse.h"
#include "../Observers/Subject.h"

class BaseService : public Subject {
public:
    BaseService();
    virtual ~BaseService();

protected:
    nlohmann::json executeGet(const std::string& url, const nlohmann::json& body = {});
    nlohmann::json executePost(const std::string& url, const nlohmann::json& body);

    BaseResponse parseBaseResponse(const nlohmann::json& responseJson);
    void ensureSuccess(const BaseResponse& response);

    std::string getLastErrorMessage() const;
    std::string lastErrorMessage;

    void notifySuccess(const std::string& message);
    void notifyFailure(const std::string& errorMessage);
};

#endif //BASESERVICE_H
