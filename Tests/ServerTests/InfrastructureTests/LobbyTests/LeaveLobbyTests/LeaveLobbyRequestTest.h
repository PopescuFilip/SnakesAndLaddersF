//
// Created by Andrei on 11/28/2024.
//

#ifndef LEAVELOBBYREQUESTTEST_H
#define LEAVELOBBYREQUESTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include  "Infrastructure/Lobby/LeaveLobby/LeaveLobbyRequest.h"

class MockLeaveLobbyRequest : public LeaveLobbyRequest {
    public:
    MockLeaveLobbyRequest(int id, const std::string& username) : LeaveLobbyRequest(id, username) {}
    MOCK_METHOD(int, getLobbyId, (), (const, override));
    MOCK_METHOD(std::string, getPlayerUsername, (), (const, override));
};

TEST(LeaveLobbyRequestTests, getLobbyId) {
    MockLeaveLobbyRequest leaveLobbyRequest(1, "Gigel");

    EXPECT_CALL(leaveLobbyRequest, getLobbyId()).WillOnce(::testing::Return(1));

    ASSERT_EQ(1, leaveLobbyRequest.getLobbyId());
}

TEST(LeaveLobbyRequestTests, getPlayerUsername) {
    MockLeaveLobbyRequest leaveLobbyRequest(1, "Gigel");

    EXPECT_CALL(leaveLobbyRequest,getPlayerUsername()).WillOnce(::testing::Return("Gigel"));

    ASSERT_EQ("Gigel", leaveLobbyRequest.getPlayerUsername());
}

#endif //LEAVELOBBYREQUESTTEST_H
