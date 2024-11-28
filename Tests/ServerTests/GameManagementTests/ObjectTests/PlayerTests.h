//
// Created by Andrei on 11/21/2024.
//

#ifndef PLAYERTESTS_H
#define PLAYERTESTS_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "GameManagement/Objects/Player.h"

class PlayerForMock : public Player {
public:

    MOCK_METHOD(const std::string &, getUsername, (), (const, override));
    MOCK_METHOD(PlayerColor, getPlayerColor, (), (const, override));
    MOCK_METHOD(bool, isLobbyAdmin, (), (const, override));
    MOCK_METHOD(int, getCurrentBoardPosition, (), (const, override));
    MOCK_METHOD(void, setCurrentBoardPosition, (int), (override));
    MOCK_METHOD(void, setIsLobbyAdmin, (bool), (override));
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));
};

TEST(PlayerTests,GetPlayerColor) {
    PlayerForMock playerForMock;

    EXPECT_CALL(playerForMock, getPlayerColor()).WillOnce(::testing::Return(PlayerColor::RED));

    EXPECT_EQ(playerForMock.getPlayerColor(), PlayerColor::RED);

}
TEST(PlayerTests, IsLobbyAdmin) {
    PlayerForMock playerForMock;

    EXPECT_CALL(playerForMock,isLobbyAdmin()).WillOnce(::testing::Return(true));

    EXPECT_EQ(playerForMock.isLobbyAdmin(), true);
}
TEST(PlayerTests,GetCurrentBoardPosition) {
    PlayerForMock playerForMock;

    EXPECT_CALL(playerForMock, getCurrentBoardPosition()).WillOnce(::testing::Return(10));
    EXPECT_EQ(playerForMock.getCurrentBoardPosition(), 10);
}
TEST(PlayerTests,SetBoardPosition) {
    PlayerForMock playerForMock;

    EXPECT_CALL(playerForMock, setCurrentBoardPosition(15)).Times(1);
    playerForMock.setCurrentBoardPosition(15);

    EXPECT_CALL(playerForMock, getCurrentBoardPosition()).WillOnce(::testing::Return(15));
    EXPECT_EQ(playerForMock.getCurrentBoardPosition(), 15);
}

TEST(PlayerTests,SetIsAdmin) {
    PlayerForMock playerForMock;

    EXPECT_CALL(playerForMock,setIsLobbyAdmin(true)).Times(1);
    playerForMock.setIsLobbyAdmin(true);

    EXPECT_CALL(playerForMock, isLobbyAdmin()).WillOnce(::testing::Return(true));
    EXPECT_EQ(playerForMock.isLobbyAdmin(), true);
}

TEST(PlayerTests,ConvertToJson) {
    PlayerForMock playerForMock;
    EXPECT_CALL(playerForMock,convertToJson()).Times(1);

    crow::json::wvalue result=playerForMock.convertToJson();

    EXPECT_FALSE(result.dump().empty());
}
#endif //PLAYERTESTS_H
