//
// Created by Andrei on 11/28/2024.
//

#ifndef LOBBYSTATUSCONTEXTTEST_H
#define LOBBYSTATUSCONTEXTTEST_H
#include<gtest/gtest.h>
#include <gmock/gmock.h>

#include "LobbyStatusRequestTest.h"
#include "Infrastructure/Lobby/LobbyStatus/LobbyStatusContext.h"


class MockLobbyStatusContext : public LobbyStatusContext {
public:
    MOCK_METHOD(LobbyStatusResponse, HandleRequest, (const LobbyStatusRequest &), (override));
    MOCK_METHOD(LobbyStatusResponse, ApplyChanges, (const LobbyStatusRequest &), (override));
    MOCK_METHOD(ValidationResponse, ValidateRequest, (const LobbyStatusRequest &), (override));
};

TEST(LobbyStatusContext, HandleRequest) {
    MockLobbyStatusContext context;
    MockLobbyStatusRequest request{1};

    Lobby lobby = {1,"Gigel",MapType::MAP_01,4};

    EXPECT_CALL(context,ValidateRequest(::testing::Ref(request))).WillOnce(::testing::Return(true));

    EXPECT_CALL(context,ApplyChanges(::testing::Ref(request))).WillOnce(::testing::Return(LobbyStatusResponse{lobby}));

    EXPECT_CALL(context, HandleRequest(::testing::Ref(request)))
    .WillOnce(::testing::Invoke([&context] (const LobbyStatusRequest &request) {
        if(ValidationResponse response = context.ValidateRequest(request) ; !response.isValid()) {
            return LobbyStatusResponse{response.getMessage()};
        }
        return context.ApplyChanges(request);
    }));

    LobbyStatusResponse response = context.HandleRequest(request);

    ASSERT_TRUE(response.getSuccess());
}

#endif //LOBBYSTATUSCONTEXTTEST_H
