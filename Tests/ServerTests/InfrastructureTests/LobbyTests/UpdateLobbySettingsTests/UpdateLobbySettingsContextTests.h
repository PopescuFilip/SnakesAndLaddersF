//
// Created by Andrei on 11/28/2024.
//

#ifndef UPDATELOBBYSETTINGSCONTEXTTESTS_H
#define UPDATELOBBYSETTINGSCONTEXTTESTS_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "UpdateLobbySettingsRequestTests.h"
#include "Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsContext.h"

class MockUpdateSettingsContext : public UpdateSettingsContext {
public:
    MOCK_METHOD(UpdateSettingsResponse, HandleRequest, (const UpdateSettingsRequest &), (override));
    MOCK_METHOD(ValidationResponse, ValidateRequest, (const UpdateSettingsRequest &), (override));
    MOCK_METHOD(UpdateSettingsResponse, ApplyChanges, (const UpdateSettingsRequest &), (override));
};

TEST(UpdateSettingsContextTest, HandleRequest) {
    MockUpdateSettingsContext context;
    MockUpdateSettingsRequest request{1,"Gigel",MapType::MAP_01,4};

    EXPECT_CALL(context,ValidateRequest(::testing::Ref(request))).WillOnce(::testing::Return(true));

    EXPECT_CALL(context,ApplyChanges(::testing::Ref(request))).WillOnce(::testing::Return(UpdateSettingsResponse{true}));

    EXPECT_CALL(context, HandleRequest(::testing::Ref(request)))
    .WillOnce(::testing::Invoke([&context] (const UpdateSettingsRequest &request) {
        if(ValidationResponse response = context.ValidateRequest(request) ; !response.isValid()) {
            return UpdateSettingsResponse{response.getMessage()};
        }
        return context.ApplyChanges(request);
    }));

    UpdateSettingsResponse response = context.HandleRequest(request);

    EXPECT_TRUE(response.getSuccess());
}
#endif //UPDATELOBBYSETTINGSCONTEXTTESTS_H
