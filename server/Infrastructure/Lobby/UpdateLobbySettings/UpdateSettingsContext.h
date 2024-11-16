#ifndef UPDATESETTINGSCONTEXT_H
#define UPDATESETTINGSCONTEXT_H
#include "UpdateSettingsRequest.h"
#include "UpdateSettingsResponse.h"
#include "../../BaseContext.h"


class UpdateSettingsContext : public BaseContext<UpdateSettingsRequest, UpdateSettingsResponse> {
public:
    UpdateSettingsResponse HandleRequest(const UpdateSettingsRequest &request) override;
private:
    ValidationResponse ValidateRequest(const UpdateSettingsRequest &request) override;
    UpdateSettingsResponse ApplyChanges(const UpdateSettingsRequest &request) override;
};



#endif //UPDATESETTINGSCONTEXT_H
