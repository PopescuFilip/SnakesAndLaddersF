#ifndef CREATELOBBYCONTEXT_H
#define CREATELOBBYCONTEXT_H
#include "CreateLobbyRequest.h"
#include "CreateLobbyResponse.h"
#include "../../BaseContext.h"


class CreateLobbyContext : public BaseContext<CreateLobbyRequest, CreateLobbyResponse>{
public:
    CreateLobbyResponse HandleRequest(const CreateLobbyRequest& request) override;
protected:
    CreateLobbyResponse ApplyChanges(const CreateLobbyRequest& request) override;
    CreateLobbyResponse ValidateRequest(const CreateLobbyRequest& request) override;
};



#endif //CREATELOBBYCONTEXT_H
