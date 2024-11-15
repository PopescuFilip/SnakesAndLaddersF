#ifndef BASERESPONSE_H
#define BASERESPONSE_H

#include <string>
#include <crow/json.h>

class BaseResponse {
public:
    virtual ~BaseResponse() = default;
    explicit operator bool() const;
    crow::json::wvalue convertToJson() const;
protected:
    explicit BaseResponse(std::string strContent);
    explicit BaseResponse(bool bSuccess);
private:
    std::string m_strMessage;
    bool m_bSuccess;
};

#endif // BASERESPONSE_H
