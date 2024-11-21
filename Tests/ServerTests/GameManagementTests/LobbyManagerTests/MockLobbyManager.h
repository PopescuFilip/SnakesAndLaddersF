//
// Created by Andrei on 11/21/2024.
//

#ifndef MOCKLOBBYMANAGER_H
#define MOCKLOBBYMANAGER_H
#include <gtest/gtest.h>
#include<gmock/gmock.h>

#include "GameManagement/Lobby/LobbyManager.h"

class MockLobbyManager : public LobbyManager {
public:
    MOCK_METHOD(int,createLobby,(const std::string& strAdminPlayer, MapType mapType, int maxPlayers));
    MOCK_METHOD(Lobby, getLobby, (int lobbyId));
};

TEST(LobbyManagerTest,CreateLobby_Validation) {
    MockLobbyManager mockManager;


    EXPECT_CALL(mockManager,createLobby("Gigel",MapType::MAP_01,4)).WillOnce(::testing::Return(1));

    int response = mockManager.createLobby("Gigel",MapType::MAP_01,4);
    EXPECT_EQ(response, 1);


}


TEST(LobbyManagerTest,RemoveLobby_Validation) {

    LobbyManager mockManager;

    mockManager.createLobby("Gigel",MapType::MAP_01,4);


    ASSERT_TRUE(mockManager.getLobby(1).getAdminPlayer() == "Gigel");

    mockManager.removeLobby(1);

    ASSERT_FALSE(mockManager.getLobby(1).getAdminPlayer() == "Gigel");

}



TEST(LobbyManagerTest, GetLobby_Validation) {

    MockLobbyManager mockManager;

    EXPECT_CALL(mockManager,getLobby(1)).WillOnce(::testing::Invoke([](int) {
        static Lobby mockLobby{1,"Gigel",MapType::MAP_01,4};
        return mockLobby;
    }));

    Lobby response={1,"Gigel",MapType::MAP_01,4};
    Lobby mockLobby=mockManager.getLobby(1);

    EXPECT_EQ(response.getLobbyId(),mockLobby.getLobbyId());
    EXPECT_EQ(response.getAdminPlayer(),mockLobby.getAdminPlayer());
    EXPECT_EQ(response.getMapType(),mockLobby.getMapType());
    EXPECT_EQ(response.getMaxPlayers(),mockLobby.getMaxPlayers());

}

TEST(LobbyManagerTest, UpdateLobby_Validation) {


    LobbyManager testManager;

    testManager.createLobby("Gigel",MapType::MAP_01,4);


    ASSERT_TRUE(testManager.getLobby(2).getAdminPlayer() == "Gigel");

    testManager.updateLobby(2,{1,"Gicu",MapType::MAP_01,2});

    EXPECT_EQ(testManager.getLobby(1).getAdminPlayer(),"Gicu");
    EXPECT_EQ(testManager.getLobby(1).getMapType(),MapType::MAP_01);
    EXPECT_EQ(testManager.getLobby(1).getMaxPlayers(),2);


}

#endif //MOCKLOBBYMANAGER_H
