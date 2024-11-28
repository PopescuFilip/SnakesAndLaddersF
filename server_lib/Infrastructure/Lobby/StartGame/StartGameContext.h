#ifndef STARTGAMECONTEXT_H
#define STARTGAMECONTEXT_H
#include "StartGameRequest.h"
#include "StartGameResponse.h"
#include "Infrastructure/BaseContext.h"


class StartGameContext : public BaseContext<StartGameRequest, StartGameResponse> {
public:
    virtual StartGameResponse HandleRequest(const StartGameRequest &request) override;

protected:
    virtual StartGameResponse ApplyChanges(const StartGameRequest &request) override;

    virtual ValidationResponse ValidateRequest(const StartGameRequest &request) override;
};



#endif //STARTGAMECONTEXT_H
