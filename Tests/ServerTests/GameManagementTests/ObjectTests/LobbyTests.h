//
// Created by Andrei on 11/21/2024.
//

#ifndef LOBBYTESTS_H
#define LOBBYTESTS_H
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "GameManagement/Objects/Lobby.h"

class LobbyForMock : public Lobby {
public:
    MOCK_METHOD(bool, addPlayer, (const Player &), (override));
    MOCK_METHOD(bool, addPlayer, (const std::string &, PlayerColor), (override));
    MOCK_METHOD(bool, removePlayer, (const std::string &), (override));
    MOCK_METHOD(PlayerColor, getNextAvailableColor, (), (const, override));
    MOCK_METHOD(std::vector<Player>, getPlayers, (), (const, override));
    MOCK_METHOD(std::string, getAdminPlayer, (), (const, override));
    MOCK_METHOD(MapType, getMapType, (), (const, override));
    MOCK_METHOD(int, getMaxPlayers, (), (const, override));
    MOCK_METHOD(int, getLobbyId, (), (const, override));
    MOCK_METHOD(void, setMapType, (MapType), (override));
    MOCK_METHOD(void, setMaxPlayers, (int), (override));
    MOCK_METHOD(void, setGameId, (int), (override));
    MOCK_METHOD(void, setAdminPlayer, (const std::string &), (override));
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));
};

TEST(LobbyTests, AddPlayerValidation) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,addPlayer("Gigel",PlayerColor::RED)).WillOnce(testing::Return(true));

    bool result = lobbyForMock.addPlayer("Gigel",PlayerColor::RED);

    ASSERT_TRUE(result);
}
TEST(LobbyTests, RemovePlayerValidation) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,addPlayer("Gigel",PlayerColor::RED)).WillOnce(testing::Return(true));

    ASSERT_TRUE(lobbyForMock.addPlayer("Gigel",PlayerColor::RED));

    EXPECT_CALL(lobbyForMock,removePlayer("Gigel")).WillOnce(testing::Return(true));

    bool result = lobbyForMock.removePlayer("Gigel");

    ASSERT_TRUE(result);
}

TEST(LobbyTests, GetNextColorValidation) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,getNextAvailableColor()).WillOnce(::testing::Return(PlayerColor::RED));

    EXPECT_EQ(PlayerColor::RED, lobbyForMock.getNextAvailableColor());
}
TEST(LobbyTests, GetAllPlayers) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,addPlayer("Gigel",PlayerColor::RED)).WillOnce(testing::Return(true));

    ASSERT_TRUE(lobbyForMock.addPlayer("Gigel",PlayerColor::RED));



    EXPECT_CALL(lobbyForMock,getPlayers()).WillOnce(::testing::Invoke([]() {
        std::vector<Player> players;
        players.emplace_back("Gigel",PlayerColor::RED,true);
        return players;
    }));

    ASSERT_TRUE(lobbyForMock.getPlayers().size());
}
TEST(LobbyTests, GetAdminPlayer) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,addPlayer("Gigel",PlayerColor::RED)).WillOnce(testing::Return(true));

    ASSERT_TRUE(lobbyForMock.addPlayer("Gigel",PlayerColor::RED));

    EXPECT_CALL(lobbyForMock,getAdminPlayer()).WillOnce(testing::Return("Gigel"));

    EXPECT_EQ("Gigel",lobbyForMock.getAdminPlayer());

}
TEST(LobbyTests,GetMapType) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,getMapType()).WillOnce(::testing::Return(MapType::MAP_01));
    EXPECT_EQ(MapType::MAP_01,lobbyForMock.getMapType());
}
TEST(LobbyTests,GetMaxPlayers) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,getMaxPlayers()).WillOnce(testing::Return(4));
    EXPECT_EQ(4, lobbyForMock.getMaxPlayers());
}
TEST(LobbyTests,GetLobbyId) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,getLobbyId()).WillOnce(testing::Return(1));
    EXPECT_EQ(1, lobbyForMock.getLobbyId());
}
TEST(LobbyTests,SetMapType) {
    LobbyForMock lobbyForMock;

    ON_CALL(lobbyForMock,setMapType(MapType::NONE)).WillByDefault([&lobbyForMock](MapType) {
        return lobbyForMock.Lobby::setMapType(MapType::NONE);
    });

    EXPECT_CALL(lobbyForMock,setMapType(MapType::NONE)).Times(1);

    lobbyForMock.setMapType(MapType::NONE);

    ON_CALL(lobbyForMock,getMapType()).WillByDefault([&lobbyForMock]() {
        return lobbyForMock.Lobby::getMapType();
    });

    EXPECT_EQ(MapType::NONE, lobbyForMock.getMapType());

}
TEST(LobbyTests,SetAdminPlayer) {
    LobbyForMock lobbyForMock;
    Lobby* lobby = &lobbyForMock;

    EXPECT_CALL(lobbyForMock,addPlayer("Gigel",PlayerColor::RED)).WillOnce(testing::Return(true));

    lobby->addPlayer("Gigel",PlayerColor::RED);

    EXPECT_CALL(lobbyForMock,setAdminPlayer("Gigel")).Times(1);

    lobby->setAdminPlayer("Gigel");
    EXPECT_CALL(lobbyForMock, getAdminPlayer()).WillOnce(testing::Return("Gigel"));
    EXPECT_EQ("Gigel",lobby->getAdminPlayer());
}

TEST(LobbyTests,SetMaxPlayers) {

    LobbyForMock lobbyForMock;

    ON_CALL(lobbyForMock,setMaxPlayers(4)).WillByDefault([&lobbyForMock](int) {
      return lobbyForMock.Lobby::setMaxPlayers(4);
  });

    EXPECT_CALL(lobbyForMock,setMaxPlayers(4)).Times(1);

    lobbyForMock.setMaxPlayers(4);

    EXPECT_CALL(lobbyForMock,getMaxPlayers()).WillOnce(::testing::Return(4));

    EXPECT_EQ(4, lobbyForMock.getMaxPlayers());
}

TEST(LobbyTests,SetGameId) {
    LobbyForMock lobbyForMock;

    EXPECT_CALL(lobbyForMock,setGameId(1)).Times(1);

    lobbyForMock.setGameId(1);
}

TEST(LobbyTests,ConvertToJson) {
    LobbyForMock lobbyForMock;
    EXPECT_CALL(lobbyForMock,convertToJson()).Times(1);

    crow::json::wvalue result=lobbyForMock.convertToJson();

    EXPECT_FALSE(result.dump().empty());

}



#endif //LOBBYTESTS_H
