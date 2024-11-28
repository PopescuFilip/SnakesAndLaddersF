//
// Created by Andrei on 11/28/2024.
//

#ifndef UPDATELOBBYSETTINGSREQUESTTESTS_H
#define UPDATELOBBYSETTINGSREQUESTTESTS_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsRequest.h"

class MockUpdateSettingsRequest : public UpdateSettingsRequest {
    public:
    MockUpdateSettingsRequest(int id, const std::string& username, MapType mapType, int maxPlayers)
    : UpdateSettingsRequest(id, username, mapType, maxPlayers) {}
    MOCK_METHOD(int, getLobbyId, (), (const, override));
    MOCK_METHOD(std::string, getPlayerUsername, (), (const, override));
    MOCK_METHOD(MapType, getMapType, (), (const, override));
    MOCK_METHOD(int, getMaxPlayers, (), (const, override));
};

TEST(UpdateSettingsRequestTests, getLobbyId) {
    MockUpdateSettingsRequest mockRequest{1,"Gigel",MapType::MAP_01,4};
    EXPECT_CALL(mockRequest, getLobbyId()).WillOnce(::testing::Return(1));

    EXPECT_EQ(mockRequest.getLobbyId(), 1);
}
TEST(UpdateSettingsRequestTests, getPlayerUsername) {
    MockUpdateSettingsRequest mockRequest{1,"Gigel",MapType::MAP_01,4};
    EXPECT_CALL(mockRequest, getPlayerUsername()).WillOnce(::testing::Return("Gigel"));

    EXPECT_EQ(mockRequest.getPlayerUsername(),"Gigel");
}
TEST(UpdateSettingsRequestTests, getMapType) {
    MockUpdateSettingsRequest mockRequest{1,"Gigel",MapType::MAP_01,4};
    EXPECT_CALL(mockRequest, getMapType()).WillOnce(::testing::Return(MapType::MAP_01));

    EXPECT_EQ(mockRequest.getMapType(), MapType::MAP_01);
}

TEST(UpdateSettingsRequestTests, getMaxPlayers) {
    MockUpdateSettingsRequest mockRequest{1,"Gigel",MapType::MAP_01,4};
    EXPECT_CALL(mockRequest, getMaxPlayers()).WillOnce(::testing::Return(4));

    EXPECT_EQ(mockRequest.getMaxPlayers(), 4);
}
#endif //UPDATELOBBYSETTINGSREQUESTTESTS_H
