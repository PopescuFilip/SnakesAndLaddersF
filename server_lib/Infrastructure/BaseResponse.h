#ifndef BASERESPONSE_H
#define BASERESPONSE_H

#include <string>
#include "../GameManagement/Objects/BaseObject.h"

class BaseResponse : public BaseObject
{
public:
    explicit BaseResponse(const std::string& strContent);
    explicit BaseResponse(bool bSuccess);
    
    explicit operator bool() const;

    bool getSuccess() const;
    const std::string& getMessage() const;
    crow::json::wvalue getBasicJson() const;

    virtual crow::json::wvalue convertToJson() const override;

    virtual ~BaseResponse() = default;
private:
    std::string m_strMessage;
    bool m_bSuccess;
};

#endif // BASERESPONSE_H
