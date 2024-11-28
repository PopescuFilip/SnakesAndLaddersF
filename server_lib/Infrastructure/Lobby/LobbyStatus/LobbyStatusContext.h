#ifndef LOBBYSTATUSCONTEXT_H
#define LOBBYSTATUSCONTEXT_H
#include "LobbyStatusRequest.h"
#include "LobbyStatusResponse.h"
#include "../../BaseContext.h"


class LobbyStatusContext : BaseContext<LobbyStatusRequest, LobbyStatusResponse> {
public:
    virtual LobbyStatusResponse HandleRequest(const LobbyStatusRequest &request) override;

protected:
    virtual LobbyStatusResponse ApplyChanges(const LobbyStatusRequest &request) override;
    virtual ValidationResponse ValidateRequest(const LobbyStatusRequest &request) override;
};



#endif //LOBBYSTATUSCONTEXT_H
