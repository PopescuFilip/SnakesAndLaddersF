#ifndef ROLLDICECONTEXT_H
#define ROLLDICECONTEXT_H
#include "RollDiceRequest.h"
#include "RollDiceResponse.h"
#include "Infrastructure/BaseContext.h"


class RollDiceContext : public BaseContext<RollDiceRequest, RollDiceResponse>{
public:
    RollDiceResponse HandleRequest(const RollDiceRequest &request) override;

protected:
    RollDiceResponse ApplyChanges(const RollDiceRequest &request) override;

    ValidationResponse ValidateRequest(const RollDiceRequest &request) override;
};



#endif //ROLLDICECONTEXT_H
