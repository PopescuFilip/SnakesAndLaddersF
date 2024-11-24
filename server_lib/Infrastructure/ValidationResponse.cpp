#include "ValidationResponse.h"

ValidationResponse::ValidationResponse(const bool isValid, const std::string &message) :
    m_bIsValid{isValid}, m_strMessage{message} {}

ValidationResponse::ValidationResponse(bool isValid) : m_bIsValid{isValid}, m_strMessage{""} {
}

bool ValidationResponse::isValid() const {
    return m_bIsValid;
}

const std::string &ValidationResponse::getMessage() const {
    return m_strMessage;
}
