#ifndef UPDATESETTINGSCONTEXT_H
#define UPDATESETTINGSCONTEXT_H
#include "UpdateSettingsRequest.h"
#include "UpdateSettingsResponse.h"
#include "../../BaseContext.h"


class UpdateSettingsContext : public BaseContext<UpdateSettingsRequest, UpdateSettingsResponse> {
public:
    virtual UpdateSettingsResponse HandleRequest(const UpdateSettingsRequest &request) override;
private:
    virtual ValidationResponse ValidateRequest(const UpdateSettingsRequest &request) override;
    virtual UpdateSettingsResponse ApplyChanges(const UpdateSettingsRequest &request) override;
};



#endif //UPDATESETTINGSCONTEXT_H
