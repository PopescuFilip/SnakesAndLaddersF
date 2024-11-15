#include "BaseResponse.h"

BaseResponse::BaseResponse(const bool bSuccess) : m_bSuccess{bSuccess}
{
    // Empty constructor
}
BaseResponse::BaseResponse(std::string strContent) :
                m_strMessage{std::move(strContent)}, m_bSuccess{false}
{
    // Empty constructor
}

BaseResponse::operator bool() const {
    return m_bSuccess;
}

crow::json::wvalue BaseResponse::convertToJson() const {
    crow::json::wvalue json;
    json["success"] = m_bSuccess;
    json["message"] = m_strMessage;

    return crow::json::wvalue(json);
}
