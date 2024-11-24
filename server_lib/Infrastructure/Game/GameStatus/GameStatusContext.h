#ifndef GAMESTATUSCONTEXT_H
#define GAMESTATUSCONTEXT_H
#include "Infrastructure/BaseContext.h"
#include "GameStatusRequest.h"
#include "GameStatusResponse.h"

class GameStatusContext : public BaseContext<GameStatusRequest, GameStatusResponse>{
public:
    GameStatusResponse HandleRequest(const GameStatusRequest &request) override;

protected:
    GameStatusResponse ApplyChanges(const GameStatusRequest &request) override;

    ValidationResponse ValidateRequest(const GameStatusRequest &request) override;
};



#endif //GAMESTATUSCONTEXT_H
