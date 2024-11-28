//
// Created by Andrei on 11/28/2024.
//

#ifndef CREATELOBBYREQUESTTEST_H
#define CREATELOBBYREQUESTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Infrastructure/Lobby/CreateLobby/CreateLobbyRequest.h"


class MockCreateLobbyRequest : public CreateLobbyRequest {
public:
    MockCreateLobbyRequest(MapType mapType,int maxPlayer, const std::string& userName)
       : CreateLobbyRequest(mapType,maxPlayer,userName) {}

    MOCK_METHOD(MapType, getMapType, (), (const, override));
    MOCK_METHOD(int, getMaxPlayers, (), (const, override));
    MOCK_METHOD(const std::string &, getAdminUsername, (), (const, override));
};

TEST(CreateLobbyRequestTests, getMapType) {

    MockCreateLobbyRequest mockRequest{MapType::MAP_01,4,"Gigel"};

    EXPECT_CALL(mockRequest, getMapType()).WillOnce(::testing::Return(MapType::MAP_01));

    MapType mapType = mockRequest.getMapType();

    EXPECT_EQ(MapType::MAP_01, mapType);

}
TEST(CreateLobbyRequestTests, getMaxPlayers) {

    MockCreateLobbyRequest mockRequest{MapType::MAP_01,4,"Gigel"};
    EXPECT_CALL(mockRequest, getMaxPlayers()).WillOnce(::testing::Return(4));

    EXPECT_EQ(4, mockRequest.getMaxPlayers());
}

TEST(CreateLobbyRequestTests, getAdminPlayer) {

    MockCreateLobbyRequest mockRequest{MapType::MAP_01,4,"Gigel"};
    std::string adminUsername = "Gigel";


    EXPECT_CALL(mockRequest, getAdminUsername())
        .WillOnce(::testing::ReturnRef(adminUsername));


    const std::string& result = mockRequest.getAdminUsername();


    EXPECT_EQ(result, "Gigel");
}
#endif //CREATELOBBYREQUESTTEST_H
