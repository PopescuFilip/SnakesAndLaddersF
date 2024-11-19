//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef BASESERVICE_H
#define BASESERVICE_H

#include <string>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include "../Core/BaseResponse.h"

class BaseService {
public:
    BaseService();
    virtual ~BaseService();

protected:
    nlohmann::json executeGet(const std::string& url, const nlohmann::json& body = {});
    nlohmann::json executePost(const std::string& url, const nlohmann::json& body);
    BaseResponse parseBaseResponse(const nlohmann::json& responseJson);
    void ensureSuccess(const BaseResponse& response);
    std::string getLastErrorMessage() const;

private:
    std::string lastErrorMessage;
};

#endif //BASESERVICE_H
