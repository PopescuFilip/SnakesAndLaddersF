#ifndef VALIDATIONRESPONSE_H
#define VALIDATIONRESPONSE_H
#include <string>

class ValidationResponse {
public:
    ValidationResponse(bool isValid, const std::string& message);
    ValidationResponse(bool isValid);

    bool isValid() const;
    const std::string& getMessage() const;
private:
    bool m_bIsValid;
    std::string m_strMessage;
};



#endif //VALIDATIONRESPONSE_H
