#ifndef JOINLOBBYCONTEXT_H
#define JOINLOBBYCONTEXT_H
#include "JoinLobbyRequest.h"
#include "JoinLobbyResponse.h"
#include "../../BaseContext.h"


class JoinLobbyContext final : public BaseContext<JoinLobbyRequest, JoinLobbyResponse> {
public:
    JoinLobbyResponse HandleRequest(const JoinLobbyRequest& request) override;
protected:
    ValidationResponse ValidateRequest(const JoinLobbyRequest& request) override;
    JoinLobbyResponse ApplyChanges(const JoinLobbyRequest& request) override;
};



#endif //JOINLOBBYCONTEXT_H
