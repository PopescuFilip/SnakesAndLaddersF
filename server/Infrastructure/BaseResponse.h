#ifndef BASERESPONSE_H
#define BASERESPONSE_H

#include <string>
#include <crow/json.h>

class BaseResponse {
public:
    virtual ~BaseResponse() = default;
    explicit operator bool() const;
    virtual crow::json::wvalue convertToJson() const = 0;

    bool getSuccess() const;
    const std::string& getMessage() const;

    explicit BaseResponse(const std::string& strContent);
    explicit BaseResponse(bool bSuccess);
private:
    std::string m_strMessage;
    bool m_bSuccess;
};

#endif // BASERESPONSE_H
