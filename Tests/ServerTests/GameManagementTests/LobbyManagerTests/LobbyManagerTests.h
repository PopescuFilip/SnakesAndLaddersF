//
// Created by Andrei on 11/21/2024.
//

#ifndef MOCKLOBBYMANAGER_H
#define MOCKLOBBYMANAGER_H
#include <gtest/gtest.h>

#include "GameManagement/Lobby/LobbyManager.h"


TEST(LobbyManagerTest, CreateLobby_Validation) {
    auto& lobbyManager = LobbyManager::getInstance();

    int response = lobbyManager.createLobby("Gigel",MapType::MAP_01,4);
    EXPECT_EQ(response, 1);
}

TEST(LobbyManagerTest, GetLobby_Validation) {
    auto& lobbyManager = LobbyManager::getInstance();
    int id = lobbyManager.createLobby("Gigel", MapType::MAP_01, 4);
    
    Lobby lobbyFromManager = lobbyManager.getLobby(id);

    EXPECT_EQ(id, lobbyFromManager.getLobbyId());
    EXPECT_EQ("Gigel", lobbyFromManager.getAdminPlayer());
    EXPECT_EQ(MapType::MAP_01, lobbyFromManager.getMapType());
    EXPECT_EQ(4, lobbyFromManager.getMaxPlayers());

}

TEST(LobbyManagerTest, UpdateLobby_Validation) {
    auto& lobbyManager = LobbyManager::getInstance();

    int id = lobbyManager.createLobby("Gigel", MapType::MAP_01, 4);
    Lobby newLobbyDetails{ id, "Gigel", MapType::NONE, 3 };

    lobbyManager.updateLobby(id, newLobbyDetails);
    Lobby updatedLobby = lobbyManager.getLobby(id);

    EXPECT_EQ(updatedLobby.getLobbyId(), id);
    EXPECT_EQ(updatedLobby.getAdminPlayer(),"Gigel");
    EXPECT_EQ(updatedLobby.getMapType(),MapType::NONE);
    EXPECT_EQ(updatedLobby.getMaxPlayers(),3);
}

#endif //MOCKLOBBYMANAGER_H
