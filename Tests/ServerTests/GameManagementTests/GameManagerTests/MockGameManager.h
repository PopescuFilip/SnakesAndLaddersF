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
public:
    MOCK_METHOD(RunningGame,createGame,(const Lobby& lobby));
    MOCK_METHOD(bool,removeGame,(int gameId));

};
MATCHER_P(IsLobby, expectedLobby, "") {
    return arg.getLobbyId() == expectedLobby.getLobbyId() &&
           arg.getAdminPlayer() == expectedLobby.getAdminPlayer() &&
           arg.getMapType() == expectedLobby.getMapType() &&
           arg.getMaxPlayers() == expectedLobby.getMaxPlayers();
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

    ASSERT_FALSE(mockRunningGame.isNull);
    EXPECT_EQ(mockRunningGame.getGameId(),1);

}
TEST(GameManagerTest,GetRunningGame_Validation) {
    GameManager testGameManager;

    testGameManager.createGame({1,"Gigel",MapType::MAP_01,4});

    ASSERT_FALSE(testGameManager.getRunningGame(1).isNull);
}
TEST(GameManagerTest,RemoveGame_Validation) {
    MockGameManager mockGameManager;

    Lobby mockLobby = {1,"Gigel",MapType::MAP_01,4};
    RunningGame mockRunningGame{mockLobby};
    EXPECT_CALL(mockGameManager,removeGame(1)).WillOnce(::testing::Return(true));

    mockGameManager.removeGame(1);
}
TEST(GameManagerTest,UpdateGame_Validation) {
    GameManager testGameManager;

    RunningGame initialGame=testGameManager.createGame({1,"Gigel",MapType::MAP_01,4});
    RunningGame newGameDetails=testGameManager.createGame({9,"Gigel",MapType::MAP_01,4});

    ASSERT_TRUE(testGameManager.updateGame(1,newGameDetails));
    ASSERT_FALSE(testGameManager.updateGame(4,newGameDetails));

}

#endif //MOCKGAMEMANAGER_H
