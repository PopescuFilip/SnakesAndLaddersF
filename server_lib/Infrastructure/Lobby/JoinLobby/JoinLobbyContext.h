#ifndef JOINLOBBYCONTEXT_H
#define JOINLOBBYCONTEXT_H
#include "JoinLobbyRequest.h"
#include "JoinLobbyResponse.h"
#include "../../BaseContext.h"


class JoinLobbyContext : public BaseContext<JoinLobbyRequest, JoinLobbyResponse> {
public:
    virtual JoinLobbyResponse HandleRequest(const JoinLobbyRequest& request) override;
protected:
    virtual ValidationResponse ValidateRequest(const JoinLobbyRequest& request) override;
    virtual JoinLobbyResponse ApplyChanges(const JoinLobbyRequest& request) override;
};



#endif //JOINLOBBYCONTEXT_H
