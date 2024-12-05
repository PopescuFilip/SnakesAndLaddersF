//
// Created by Andrei on 11/21/2024.
//

#ifndef LOBBYTESTS_H
#define LOBBYTESTS_H

#include <gtest/gtest.h>
#include "GameManagement/Objects/Lobby.h"

TEST(LobbyTests, AddPlayerValidation) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);

    bool result = lobby.addPlayer("Gigel",PlayerColor::RED);

    ASSERT_TRUE(result);
}

TEST(LobbyTests, RemovePlayerValidation) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);

    bool addResult = lobby.addPlayer("Gigel", PlayerColor::RED);
    bool removeResult = lobby.removePlayer("Gigel");

    ASSERT_TRUE(addResult);
    ASSERT_TRUE(removeResult);
}

TEST(LobbyTests, GetNextColorValidation) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);

    EXPECT_EQ(PlayerColor::BLUE, lobby.getNextAvailableColor());
}

TEST(LobbyTests, GetAllPlayers) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    lobby.addPlayer("Gigel",PlayerColor::BLUE);

    auto players = lobby.getPlayers();

    EXPECT_EQ(players.size(), 2);
    EXPECT_EQ(players[0].getPlayerColor(), PlayerColor::RED);
    EXPECT_EQ(players[0].getUsername(), "Flavius");
    EXPECT_EQ(players[1].getPlayerColor(), PlayerColor::BLUE);
    EXPECT_EQ(players[1].getUsername(), "Gigel");
}

TEST(LobbyTests, CheckConstructor) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);

    EXPECT_EQ("Flavius", lobby.getAdminPlayer());
    EXPECT_EQ(MapType::MAP_01, lobby.getMapType());
    EXPECT_EQ(2, lobby.getMaxPlayers());
    EXPECT_EQ(1, lobby.getLobbyId());
}

TEST(LobbyTests,SetMapType) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);

    lobby.setMapType(MapType::NONE);

    EXPECT_EQ(MapType::NONE, lobby.getMapType());

}

TEST(LobbyTests,SetAdminPlayer) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);


    lobby.addPlayer("Gigel",PlayerColor::BLUE);
    lobby.setAdminPlayer("Gigel");

    EXPECT_EQ("Gigel",lobby.getAdminPlayer());
}

TEST(LobbyTests,SetMaxPlayers) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);

    lobby.setMaxPlayers(4);

    EXPECT_EQ(4, lobby.getMaxPlayers());
}

TEST(LobbyTests,ConvertToJson) {
    Lobby lobby(2, "Flavius", MapType::MAP_01, 2);

    crow::json::wvalue result=lobby.convertToJson();

    EXPECT_FALSE(result.dump().empty());
}

#endif //LOBBYTESTS_H
