//
// Created by Andrei on 11/21/2024.
//

#ifndef MOCKGAMEMANAGER_H
#define MOCKGAMEMANAGER_H
#include "GameManagement/Game/GameManager.h"
#include "GameManagement/Lobby/LobbyManager.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>


class MockGameManager : public GameManager {
private:
    std::unordered_map<int, RunningGame> games;
public:
    MOCK_METHOD(RunningGame, getRunningGame, (int), (const, override));
    MOCK_METHOD(bool, updateGame, (int, const RunningGame &), (override));
    MOCK_METHOD(void, rollDiceInGame, (int), (override));

    MOCK_METHOD(RunningGame, createGame, (const Lobby& lobby));
    MOCK_METHOD(bool,removeGame,(int gameId));


};
MATCHER_P(IsLobby, expectedLobby, "") {
    return arg.getLobbyId() == expectedLobby.getLobbyId() &&
           arg.getAdminPlayer() == expectedLobby.getAdminPlayer() &&
           arg.getMapType() == expectedLobby.getMapType() &&
           arg.getMaxPlayers() == expectedLobby.getMaxPlayers();
}
MATCHER_P(IsGame, expected, "Checks if two RunningGame objects are equal") {
    return arg.getGameId() == expected.getGameId();
}




TEST(GameManagerTest,CreateGame_Validation) {
    MockGameManager mockGameManager;



    Lobby mockLobby={1,"Gigel",MapType::MAP_01,4};


    EXPECT_CALL(mockGameManager,createGame(IsLobby(mockLobby))).WillOnce(::testing::Invoke([](const Lobby& lobby)->RunningGame& {
        static RunningGame mockRunningGame{lobby};
        return mockRunningGame;
    }));;
    ;

    RunningGame mockRunningGame=mockGameManager.createGame(mockLobby);

    EXPECT_EQ(mockRunningGame.getGameId(),1);

}
TEST(GameManagerTest,GetRunningGame_Validation) {
    MockGameManager mockGameManager;

    Lobby mockLobby={1,"Gigel",MapType::MAP_01,4};


    EXPECT_CALL(mockGameManager,createGame(IsLobby(mockLobby))).WillOnce(::testing::Invoke([](const Lobby& lobby)->RunningGame& {
        static RunningGame mockRunningGame{lobby};
        return mockRunningGame;
    }));;
    ;

    RunningGame mockRunningGame=mockGameManager.createGame(mockLobby);

    EXPECT_CALL(mockGameManager,getRunningGame(1)).WillOnce(::testing::Return(mockRunningGame));
    ASSERT_NO_THROW(mockGameManager.getRunningGame(1));
}
TEST(GameManagerTest,RemoveGame_Validation) {
    MockGameManager mockGameManager;

    Lobby mockLobby = {1,"Gigel",MapType::MAP_01,4};
    RunningGame mockRunningGame{mockLobby};
    EXPECT_CALL(mockGameManager,removeGame(1)).WillOnce(::testing::Return(true));

    EXPECT_TRUE(mockGameManager.removeGame(1));
}
TEST(GameManagerTests, UpdateGame) {
    MockGameManager mockGameManager;

    // Initial lobby and new lobby details
    Lobby mockLobby = {1, "Gigel", MapType::MAP_01, 4};
    Lobby newInfoLobby = {2, "Gigel", MapType::NONE, 4};

    // Default behavior for createGame


    RunningGame initialRunningGame(mockLobby);

    // Setup the update behavior
    RunningGame newGameDetails(newInfoLobby);

    EXPECT_CALL(mockGameManager,updateGame(1,IsGame(newGameDetails))).WillOnce(::testing::Return(true));

    // Assertions
    EXPECT_TRUE(mockGameManager.updateGame(1, newGameDetails));

}



#endif //MOCKGAMEMANAGER_H
