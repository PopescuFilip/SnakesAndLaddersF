//
// Created by Andrei on 11/28/2024.
//

#ifndef LOBBYSTATUSREQUESTTEST_H
#define LOBBYSTATUSREQUESTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Infrastructure/Lobby/LobbyStatus/LobbyStatusRequest.h"

class MockLobbyStatusRequest : public LobbyStatusRequest {
    public:
    MockLobbyStatusRequest(int id) : LobbyStatusRequest(id) {}
    MOCK_METHOD(int, GetLobbyId, (), (const, override));
};

TEST(LobbyStatusRequestTest, GetLobbyId) {
    MockLobbyStatusRequest mockLobbyStatusRequest(1);

    EXPECT_CALL(mockLobbyStatusRequest, GetLobbyId()).WillOnce(::testing::Return(1));

    EXPECT_EQ(1, mockLobbyStatusRequest.GetLobbyId());
}

#endif //LOBBYSTATUSREQUESTTEST_H
