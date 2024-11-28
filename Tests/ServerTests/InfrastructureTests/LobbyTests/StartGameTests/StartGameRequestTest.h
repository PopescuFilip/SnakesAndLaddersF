//
// Created by Andrei on 11/28/2024.
//

#ifndef STARTGAMEREQUESTTEST_H
#define STARTGAMEREQUESTTEST_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Infrastructure/Lobby/StartGame/StartGameRequest.h"

class MockStartGameRequest : public StartGameRequest {
    public:
    MockStartGameRequest(int id, const std::string& name) : StartGameRequest(id, name) {}
    MOCK_METHOD(int, GetLobbyId, (), (const, override));
    MOCK_METHOD(std::string, GetPlayerUsername, (), (const, override));
};

TEST(StartGameRequestTest, GetLobbyId) {
    MockStartGameRequest request(1, "Gigel");

    EXPECT_CALL(request, GetLobbyId()).WillOnce(::testing::Return(1));

    EXPECT_EQ(1, request.GetLobbyId());
}

TEST(StartGameRequestTest, GetPlayerUsername) {
    MockStartGameRequest request(1, "Gigel");

    EXPECT_CALL(request, GetPlayerUsername()).WillOnce(::testing::Return("Gigel"));

    EXPECT_EQ("Gigel", request.GetPlayerUsername());

}

#endif //STARTGAMEREQUESTTEST_H
