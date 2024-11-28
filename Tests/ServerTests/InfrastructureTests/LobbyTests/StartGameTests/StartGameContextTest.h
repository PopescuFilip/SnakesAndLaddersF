//
// Created by Andrei on 11/28/2024.
//

#ifndef STARTGAMECONTEXTTEST_H
#define STARTGAMECONTEXTTEST_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "StartGameRequestTest.h"
#include "Infrastructure/Lobby/StartGame/StartGameContext.h"

class MockStartGameContext : public StartGameContext {
public:
    MOCK_METHOD(StartGameResponse, HandleRequest, (const StartGameRequest &), (override));
    MOCK_METHOD(StartGameResponse, ApplyChanges, (const StartGameRequest &), (override));
    MOCK_METHOD(ValidationResponse, ValidateRequest, (const StartGameRequest &), (override));
};

TEST(StartGameContextTest, HandleRequest) {
    MockStartGameContext context;
    MockStartGameRequest request{1,"Gigel"};

    EXPECT_CALL(context,ValidateRequest(::testing::Ref(request))).WillOnce(::testing::Return(true));

    EXPECT_CALL(context,ApplyChanges(::testing::Ref(request))).WillOnce(::testing::Return(StartGameResponse{true}));

    EXPECT_CALL(context, HandleRequest(::testing::Ref(request)))
    .WillOnce(::testing::Invoke([&context] (const StartGameRequest &request) {
        if(ValidationResponse response = context.ValidateRequest(request) ; !response.isValid()) {
            return StartGameResponse{response.getMessage()};
        }
        return context.ApplyChanges(request);
    }));

    StartGameResponse response = context.HandleRequest(request);

    EXPECT_TRUE(response.getSuccess());
}
#endif //STARTGAMECONTEXTTEST_H
