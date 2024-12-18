#ifndef BASERESPONSE_H
#define BASERESPONSE_H

#include <string>
#include "GameManagement/Objects/BaseObject.h"

class BaseResponse : public BaseObject
{
public:
    explicit BaseResponse(const std::string& strContent, bool bSucces);
    explicit BaseResponse(bool bSuccess);

    inline static BaseResponse Succes() { return BaseResponse(true); }
    inline static BaseResponse Failure(const std::string& strContent) { return BaseResponse(strContent, false); }

    explicit operator bool() const;

    bool getSuccess() const;
    const std::string& getMessage() const;

    virtual crow::json::wvalue convertToJson() const override;

    virtual ~BaseResponse() = default;
protected:
    crow::json::wvalue getBasicJson() const;

private:
    std::string m_strMessage;
    bool m_bSuccess;
};

#endif // BASERESPONSE_H
