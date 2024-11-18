//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef BASERESPONSE_H
#define BASERESPONSE_H

#include <string>
#include <nlohmann/json.hpp>

class BaseResponse {
private:
    bool success;
    std::string message;

public:
    BaseResponse();
    BaseResponse(bool success, const std::string& message);

    bool isSuccess() const;
    void setSuccess(bool value);

    std::string getMessage() const;
    void setMessage(const std::string& value);

    friend void to_json(nlohmann::json& j, const BaseResponse& r);
    friend void from_json(const nlohmann::json& j, BaseResponse& r);
};

#endif //BASERESPONSE_H
