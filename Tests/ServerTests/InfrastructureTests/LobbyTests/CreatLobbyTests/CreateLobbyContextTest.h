//
// Created by Andrei on 11/28/2024.
//

#ifndef CREATELOBBYCONTEXTTEST_H
#define CREATELOBBYCONTEXTTEST_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "CreateLobbyRequestTest.h"
#include "Infrastructure/Lobby/CreateLobby/CreateLobbyContext.h"

class MockCreateLobbyContext : public CreateLobbyContext {
public:
    MOCK_METHOD(CreateLobbyResponse, HandleRequest, (const CreateLobbyRequest &), (override));
    MOCK_METHOD(CreateLobbyResponse, ApplyChanges, (const CreateLobbyRequest &), (override));
    MOCK_METHOD(ValidationResponse, ValidateRequest, (const CreateLobbyRequest &), (override));
};

TEST(CreateLobbyContext, HandleRequest) {
    MockCreateLobbyContext mockContext;
    MockCreateLobbyRequest mockRequest{MapType::MAP_01,4,"Gigel"};


    EXPECT_CALL(mockContext, ValidateRequest(::testing::Ref(mockRequest)))
        .WillOnce(::testing::Return(ValidationResponse{true}));


    EXPECT_CALL(mockContext, ApplyChanges(::testing::Ref(mockRequest)))
        .WillOnce(::testing::Return(CreateLobbyResponse{1}));


    EXPECT_CALL(mockContext, HandleRequest(::testing::Ref(mockRequest)))
        .WillOnce(::testing::Invoke([&mockContext](const CreateLobbyRequest& request) {
            if (ValidationResponse response = mockContext.ValidateRequest(request); !response.isValid()) {
                return CreateLobbyResponse{response.getMessage()};
            }
            return mockContext.ApplyChanges(request);
        }));

    CreateLobbyResponse response = mockContext.HandleRequest(mockRequest);


    EXPECT_EQ(response.getLobbyId(), 1);

}

#endif CREATELOBBYCONTEXTTEST_H
