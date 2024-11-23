//
// Created by Tudor Andrei on 23.11.2024.
//

#ifndef LEAVEGAMECONTEXT_H
#define LEAVEGAMECONTEXT_H
#include "LeaveGameRequest.h"
#include "LeaveGameResponse.h"
#include "Infrastructure/BaseContext.h"


class LeaveGameContext : public BaseContext<LeaveGameRequest, LeaveGameResponse>{
public:
    LeaveGameResponse HandleRequest(const LeaveGameRequest &request) override;

protected:
    LeaveGameResponse ApplyChanges(const LeaveGameRequest &request) override;

    ValidationResponse ValidateRequest(const LeaveGameRequest &request) override;
};



#endif //LEAVEGAMECONTEXT_H
