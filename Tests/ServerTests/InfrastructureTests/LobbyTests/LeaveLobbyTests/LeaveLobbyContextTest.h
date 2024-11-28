//
// Created by Andrei on 11/28/2024.
//

#ifndef LEAVELOBBYCONTEXTTEST_H
#define LEAVELOBBYCONTEXTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "LeaveLobbyRequestTest.h"
#include "Infrastructure/Lobby/LeaveLobby/LeaveLobbyContext.h"

class MockLeaveLobbyContext : LeaveLobbyContext {
public:
    MOCK_METHOD(LeaveLobbyResponse, HandleRequest, (const LeaveLobbyRequest &), (override));
    MOCK_METHOD(LeaveLobbyResponse, ApplyChanges, (const LeaveLobbyRequest &), (override));
    MOCK_METHOD(ValidationResponse, ValidateRequest, (const LeaveLobbyRequest &), (override));
};


TEST(LeaveLobbyContextTest, HandleRequest) {
    MockLeaveLobbyContext context;
    MockLeaveLobbyRequest request{1,"Gigel"};

    EXPECT_CALL(context,ValidateRequest(::testing::Ref(request))).WillOnce(::testing::Return(true));

    EXPECT_CALL(context,ApplyChanges(::testing::Ref(request))).WillOnce(::testing::Return(LeaveLobbyResponse{true}));

    EXPECT_CALL(context, HandleRequest(::testing::Ref(request)))
    .WillOnce(::testing::Invoke([&context] (const LeaveLobbyRequest &request) {
        if(ValidationResponse response = context.ValidateRequest(request) ; !response.isValid()) {
            return LeaveLobbyResponse{response.getMessage()};
        }
        return context.ApplyChanges(request);
    }));

    LeaveLobbyResponse response = context.HandleRequest(request);

    ASSERT_TRUE(response.getSuccess());
}
#endif //LEAVELOBBYCONTEXTTEST_H
