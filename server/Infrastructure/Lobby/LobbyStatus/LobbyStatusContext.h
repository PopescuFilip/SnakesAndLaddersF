#ifndef LOBBYSTATUSCONTEXT_H
#define LOBBYSTATUSCONTEXT_H
#include "LobbyStatusRequest.h"
#include "LobbyStatusResponse.h"
#include "../../BaseContext.h"


class LobbyStatusContext : BaseContext<LobbyStatusRequest, LobbyStatusResponse> {
public:
    LobbyStatusResponse HandleRequest(const LobbyStatusRequest &request) override;

protected:
    LobbyStatusResponse ApplyChanges(const LobbyStatusRequest &request) override;
    ValidationResponse ValidateRequest(const LobbyStatusRequest &request) override;
};



#endif //LOBBYSTATUSCONTEXT_H
