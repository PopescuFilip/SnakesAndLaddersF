#ifndef LEAVELOBBYCONTEXT_H
#define LEAVELOBBYCONTEXT_H
#include "LeaveLobbyRequest.h"
#include "LeaveLobbyResponse.h"
#include "../../BaseContext.h"


class LeaveLobbyContext : public BaseContext<LeaveLobbyRequest, LeaveLobbyResponse> {
public:
    virtual LeaveLobbyResponse HandleRequest(const LeaveLobbyRequest &request) override;

protected:
    virtual LeaveLobbyResponse ApplyChanges(const LeaveLobbyRequest &request) override;
    virtual ValidationResponse ValidateRequest(const LeaveLobbyRequest &request) override;
};



#endif //LEAVELOBBYCONTEXT_H
