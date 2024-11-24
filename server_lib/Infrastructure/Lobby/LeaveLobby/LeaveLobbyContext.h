#ifndef LEAVELOBBYCONTEXT_H
#define LEAVELOBBYCONTEXT_H
#include "LeaveLobbyRequest.h"
#include "LeaveLobbyResponse.h"
#include "../../BaseContext.h"


class LeaveLobbyContext final : public BaseContext<LeaveLobbyRequest, LeaveLobbyResponse> {
public:
    LeaveLobbyResponse HandleRequest(const LeaveLobbyRequest &request) override;

protected:
    LeaveLobbyResponse ApplyChanges(const LeaveLobbyRequest &request) override;
    ValidationResponse ValidateRequest(const LeaveLobbyRequest &request) override;
};



#endif //LEAVELOBBYCONTEXT_H
