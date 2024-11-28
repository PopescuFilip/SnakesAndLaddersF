//
// Created by Andrei on 11/28/2024.
//

#ifndef JOINLOBBYREQUESTTEST_H
#define JOINLOBBYREQUESTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Infrastructure/Lobby/JoinLobby/JoinLobbyRequest.h"

class MockJoinLobbyRequest : public JoinLobbyRequest {
    public:
    MockJoinLobbyRequest(int id, const std::string& username) : JoinLobbyRequest(id, username) {}
    MOCK_METHOD(int, getLobbyId, (), (const, override));
    MOCK_METHOD(const std::string &, getUsername, (), (const, override));
};

TEST(JoinLobbyRequestTests, getLobbyId) {
    MockJoinLobbyRequest lobbyRequest(1, "Gigel");

    EXPECT_CALL(lobbyRequest, getLobbyId()).WillOnce(::testing::Return(1));

    EXPECT_EQ(1, lobbyRequest.getLobbyId());
}

TEST(JoinLobbyRequestTests, getUsername) {
    MockJoinLobbyRequest lobbyRequest(2, "Gigel");

    std::string username = "Gigel";

    EXPECT_CALL(lobbyRequest, getUsername()).WillOnce(::testing::ReturnRef(username));

    EXPECT_EQ("Gigel", lobbyRequest.getUsername());
}
#endif //JOINLOBBYREQUESTTEST_H
