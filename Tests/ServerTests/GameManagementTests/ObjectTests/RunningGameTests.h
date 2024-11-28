//
// Created by Andrei on 11/21/2024.
//

#ifndef RUNNINGGAMETESTS_H
#define RUNNINGGAMETESTS_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <GameManagement/Objects/RunningGame.h>

class MockRunningGame : public RunningGame {
public:
    MOCK_METHOD(void, updatePlayerPosition, (const std::string &, int), (override));
    MOCK_METHOD(void, startNewTurn, (), (override));
    MOCK_METHOD(int, getCurrentTurnTime, (), (const, override));
    MOCK_METHOD(int, getNewTeleportPosition, (int), (const, override));
    MOCK_METHOD(void, triggerDiceRolling, (), (override));
    MOCK_METHOD(void, resetTriggerDiceRolling, (), (override));
    MOCK_METHOD(bool, getDiceRolling, (), (const, override));
    MOCK_METHOD(void, setLatestDiceValue, (int), (override));
    MOCK_METHOD(int, getLatestDiceValue, (), (const, override));
    MOCK_METHOD(void, setPlayerTurn, (const std::string &), (override));
    MOCK_METHOD(Player &, getCurrentPlayer, (), (override));
    MOCK_METHOD(void, setShouldFinishGame, (bool), (override));
    MOCK_METHOD(bool, getShouldFinishGame, (), (const, override));
    MOCK_METHOD(int, getGameId, (), (const, override));
    MOCK_METHOD(void, readTeleportPositions, (const MapType &), (override));
    MOCK_METHOD(bool, removePlayer, (const std::string &), (override));
    MOCK_METHOD(const std::vector<Player> &, getPlayers, (), (const, override));
    MOCK_METHOD(int, getTotalTime, (), (const, override));
    MOCK_METHOD(crow::json::wvalue, convertToJson, (), (const, override));
};


TEST(RunningGameTests, UpdatePlayerPosition) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, updatePlayerPosition("Gigel", 42))
       .Times(1);

    mockGame.updatePlayerPosition("Gigel", 42);
}

TEST(RunningGameTests, StartNewTurn) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, startNewTurn())
       .Times(1);

    mockGame.startNewTurn();
}

TEST(RunningGameTests,GetCurrentTurnTime) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, getCurrentTurnTime()).WillOnce(::testing::Return(30));

    EXPECT_EQ(30, mockGame.getCurrentTurnTime());
}

TEST(RunningGameTests,GetNewTeleportPosition) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, getNewTeleportPosition(5))
        .WillOnce(::testing::Return(10));

    EXPECT_EQ(mockGame.getNewTeleportPosition(5), 10);
}

TEST(RunningGameTests,TriggerDiceRolling) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, triggerDiceRolling())
     .Times(1);

    mockGame.triggerDiceRolling();
}


TEST(RunningGameTests, ResetTriggerDiceRolling) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, resetTriggerDiceRolling())
     .Times(1);

    mockGame.resetTriggerDiceRolling();
}


TEST(RunningGameTests,GetDiceRolling) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, getDiceRolling())
     .WillOnce(::testing::Return(true));

    EXPECT_TRUE(mockGame.getDiceRolling());
}

TEST(RunningGameTests,SetDiceValue) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, setLatestDiceValue(6))
        .Times(1);

    mockGame.setLatestDiceValue(6);
}

TEST(RunningGameTests,GetDiceValue) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, getLatestDiceValue())
        .WillOnce(::testing::Return(6));

    EXPECT_EQ(mockGame.getLatestDiceValue(),6);
}

TEST(RunningGameTests, SetPlayerTurn) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, setPlayerTurn("Gigel"))
        .Times(1);

    mockGame.setPlayerTurn("Gigel");
}

TEST(RunningGameTests, GetCurrentPlayer) {

    MockRunningGame mockGame;

    Player mockPlayer;

    EXPECT_CALL(mockGame, getCurrentPlayer())
        .WillOnce(::testing::ReturnRef(mockPlayer));

    Player& playerRef = mockGame.getCurrentPlayer();
    EXPECT_EQ(&playerRef, &mockPlayer);
}

TEST(RunningGameTests, SetShouldFinishGame) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, setShouldFinishGame(true))
        .Times(1);

    mockGame.setShouldFinishGame(true);
}

TEST(RunningGameTests, GetShouldFinishGame) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, getShouldFinishGame())
       .WillOnce(::testing::Return(true));

    EXPECT_TRUE(mockGame.getShouldFinishGame());
}

TEST(RunningGameTESTS,GetGameId) {
    MockRunningGame mockGame;


    EXPECT_CALL(mockGame, getGameId())
        .WillOnce(::testing::Return(1));

    EXPECT_EQ(mockGame.getGameId(), 1);
}

TEST(RunningGameTests, ReadTeleportPositions) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, readTeleportPositions(MapType::MAP_01))
        .Times(1);

    mockGame.readTeleportPositions(MapType::MAP_01);
}

TEST(RunningGameTests,GetPlayers) {

    MockRunningGame mockGame;

    std::vector<Player> mockPlayers;

    EXPECT_CALL(mockGame, getPlayers())
        .WillOnce(::testing::ReturnRef(mockPlayers));

    const std::vector<Player>& playersRef = mockGame.getPlayers();
    EXPECT_EQ(&playersRef, &mockPlayers);
}

TEST(RuningGameTests, GetTotalTime) {
    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, getTotalTime())
       .WillOnce(::testing::Return(120));

    EXPECT_EQ(mockGame.getTotalTime(), 120);
}

TEST(RunningGameTests, RemovePlayer) {
    MockRunningGame mockGame;
    EXPECT_CALL(mockGame, removePlayer("Gigel"))
       .WillOnce(::testing::Return(true));

    EXPECT_TRUE(mockGame.removePlayer("Gigel"));
}


TEST(RunningGameTESTS,ConvertToJson) {

    MockRunningGame mockGame;

    EXPECT_CALL(mockGame, convertToJson()).Times(1);

    crow::json::wvalue result=mockGame.convertToJson();

    EXPECT_FALSE(result.dump().empty());
}





#endif //RUNNINGGAMETESTS_H
