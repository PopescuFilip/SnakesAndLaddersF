//
// Created by Andrei on 11/21/2024.
//

#ifndef MOCKLOBBYMANAGER_H
#define MOCKLOBBYMANAGER_H
#include <gtest/gtest.h>
#include<gmock/gmock.h>

#include "GameManagement/Lobby/LobbyManager.h"

MATCHER_P(IsALobby, expectedLobby, "") {
    return arg.getLobbyId() == expectedLobby.getLobbyId() &&
           arg.getAdminPlayer() == expectedLobby.getAdminPlayer() &&
           arg.getMapType() == expectedLobby.getMapType() &&
           arg.getMaxPlayers() == expectedLobby.getMaxPlayers();
}


class MockLobbyManager : public LobbyManager {
private:
    std::pmr::unordered_map<int,Lobby> lobbies;
    Lobby newLobbyDetails = {1,"Gigel",MapType::NONE,3};
public:
    MOCK_METHOD(int, createLobby, (const std::string& strAdminPlayer, MapType mapType, int maxPlayers), (override));
    MOCK_METHOD(void, removeLobby, (int), (override));
    MOCK_METHOD(void, updateLobby, (int, const Lobby &), (override));
    MOCK_METHOD(Lobby, getLobby, (int), (const, override));

    MockLobbyManager() {
        ON_CALL(*this,createLobby("Gigel", MapType::MAP_01, 4)).WillByDefault([this](const std::string & strAdminPlayer, MapType mapType, int maxPlayers) {
            Lobby lobby = {1,"Gigel",mapType,maxPlayers};
            lobbies[1]=lobby;
            return 1;
        });

        ON_CALL(*this,updateLobby(1,IsALobby(newLobbyDetails))).WillByDefault([this](int, const Lobby &lobby) {

            lobbies[1]=newLobbyDetails;
        });
        ON_CALL(*this,getLobby(1)).WillByDefault([this](int) {
            return lobbies[1];
        });

    }

};



TEST(LobbyManagerTest,CreateLobby_Validation) {
    MockLobbyManager mockManager;


    EXPECT_CALL(mockManager,createLobby("Gigel",MapType::MAP_01,4)).WillOnce(::testing::Return(1));

    int response = mockManager.createLobby("Gigel",MapType::MAP_01,4);
    EXPECT_EQ(response, 1);


}


TEST(LobbyManagerTest,RemoveLobby_Validation) {

    MockLobbyManager mockManager;

    EXPECT_CALL(mockManager,createLobby("Gigel",MapType::MAP_01,4)).WillOnce(::testing::Return(1));

    int response = mockManager.createLobby("Gigel",MapType::MAP_01,4);
    EXPECT_EQ(response, 1);

    EXPECT_CALL(mockManager,removeLobby(1)).Times(1);

    mockManager.removeLobby(1);


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


    MockLobbyManager mockManager;

    EXPECT_CALL(mockManager,createLobby("Gigel",MapType::MAP_01,4)).WillOnce(::testing::Invoke([&mockManager](const std::string & strAdminPlayer, MapType mapType, int maxPlayers ) {
        return mockManager.LobbyManager::createLobby(strAdminPlayer,mapType,maxPlayers);
    }));

    int result = mockManager.createLobby("Gigel",MapType::MAP_01,4);



    EXPECT_EQ(result,1);

    EXPECT_CALL(mockManager,getLobby(1)).WillOnce(::testing::Invoke([&mockManager](int id ) {
        return mockManager.LobbyManager::getLobby(id);
    }));

    Lobby lobby = mockManager.getLobby(1);



    EXPECT_EQ(lobby.getLobbyId(),1);
    EXPECT_EQ(lobby.getAdminPlayer(),"Gigel");
    EXPECT_EQ(lobby.getMapType(),MapType::MAP_01);
    EXPECT_EQ(lobby.getMaxPlayers(),4);

    Lobby newLobbyDetails = {1,"Gigel",MapType::NONE,3};
    EXPECT_CALL(mockManager,updateLobby(1,IsALobby(newLobbyDetails))).WillOnce(::testing::Invoke([&mockManager](int id, const Lobby &lobby) {
        mockManager.LobbyManager::updateLobby(id,lobby);
    }));

    mockManager.updateLobby(1,newLobbyDetails);

    EXPECT_CALL(mockManager,getLobby(1)).WillOnce(::testing::Invoke([&mockManager](int id ) {
       return mockManager.LobbyManager::getLobby(id);
   }));

    Lobby updatedLobby = mockManager.getLobby(1);



    EXPECT_EQ(updatedLobby.getLobbyId(),1);
    EXPECT_EQ(updatedLobby.getAdminPlayer(),"Gigel");
    EXPECT_EQ(updatedLobby.getMapType(),MapType::NONE);
    EXPECT_EQ(updatedLobby.getMaxPlayers(),3);


}

#endif //MOCKLOBBYMANAGER_H
