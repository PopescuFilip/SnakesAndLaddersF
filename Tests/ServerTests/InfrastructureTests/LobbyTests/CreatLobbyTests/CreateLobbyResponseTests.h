//
// Created by Andrei on 11/28/2024.
//

#ifndef CREATELOBBYRESPONSETESTS_H
#define CREATELOBBYRESPONSETESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Infrastructure/Lobby/CreateLobby/CreateLobbyResponse.h"

class MockCreateLobbyResponse : public CreateLobbyResponse {
public:

    MockCreateLobbyResponse(int lobbyId): CreateLobbyResponse(lobbyId) {};

    MOCK_METHOD(int, getLobbyId, (), (const, override));
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));
};

TEST(CreateLobbyResponseTests, getLobbyId) {

    MockCreateLobbyResponse mockResponse{1};

    EXPECT_CALL(mockResponse, getLobbyId()).WillOnce(::testing::Return(1));

    EXPECT_EQ(1, mockResponse.getLobbyId());
}

TEST(CreateLobbyResponseTests, convertToJson) {
    MockCreateLobbyResponse mockResponse{1};

    EXPECT_CALL(mockResponse, convertToJson).Times(1);

    crow::json::wvalue response = mockResponse.convertToJson();

    EXPECT_FALSE(response.dump().empty());
}

#endif //CREATELOBBYRESPONSETESTS_H
