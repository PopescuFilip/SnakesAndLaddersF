//
// Created by Andrei on 11/28/2024.
//

#ifndef JOINLOBBYCONTEXTTEST_H
#define JOINLOBBYCONTEXTTEST_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "JoinLobbyRequestTest.h"
#include "Infrastructure/Lobby/JoinLobby/JoinLobbyContext.h"

class MockJoinLobbyContext: public JoinLobbyContext {
public:
    MOCK_METHOD(JoinLobbyResponse, HandleRequest, (const JoinLobbyRequest &), (override));
    MOCK_METHOD(ValidationResponse, ValidateRequest, (const JoinLobbyRequest &), (override));
    MOCK_METHOD(JoinLobbyResponse, ApplyChanges, (const JoinLobbyRequest &), (override));
};

TEST(JoinLobbyContextTest, HandleRequest) {
    MockJoinLobbyContext context;
    MockJoinLobbyRequest request{1,"Gigel"};
    Lobby lobby = {1,"Gicu",MapType::MAP_01,4};

    EXPECT_CALL(context,ValidateRequest(::testing::Ref(request))).WillOnce(::testing::Return(true));

    EXPECT_CALL(context,ApplyChanges(::testing::Ref(request))).WillOnce(::testing::Return(JoinLobbyResponse{lobby}));

    EXPECT_CALL(context, HandleRequest(::testing::Ref(request)))
    .WillOnce(::testing::Invoke([&context] (const JoinLobbyRequest &request) {
        if(ValidationResponse response = context.ValidateRequest(request) ; !response.isValid()) {
            return JoinLobbyResponse{response.getMessage()};
        }
        return context.ApplyChanges(request);
    }));

    JoinLobbyResponse response = context.HandleRequest(request);

    EXPECT_EQ(response.getMessage(), "");
}
#endif //JOINLOBBYCONTEXTTEST_H
