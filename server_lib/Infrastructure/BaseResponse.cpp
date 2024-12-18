#include "BaseResponse.h"
#include "JsonSerializer.h"

BaseResponse::BaseResponse(const bool bSuccess) : m_bSuccess{ bSuccess }
{}

BaseResponse::BaseResponse(const std::string& strContent, const bool bSucces) :
    m_strMessage{ strContent },
    m_bSuccess{ bSucces }
{}

BaseResponse::operator bool() const
{
    return m_bSuccess;
}

bool BaseResponse::getSuccess() const
{
    return m_bSuccess;
}

const std::string& BaseResponse::getMessage() const
{
    return m_strMessage;
}

crow::json::wvalue BaseResponse::convertToJson() const
{
    return getBasicJson();
}

crow::json::wvalue BaseResponse::getBasicJson() const
{
    crow::json::wvalue json;
    json["success"] = getSuccess();
    json["message"] = getMessage();

    return json;

}
