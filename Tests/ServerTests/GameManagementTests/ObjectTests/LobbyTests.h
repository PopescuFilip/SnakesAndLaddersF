//
// Created by Andrei on 11/21/2024.
//

#ifndef LOBBYTESTS_H
#define LOBBYTESTS_H
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "GameManagement/Objects/Lobby.h"

TEST(LobbyTests,AddPlayer_Validation) {
    Lobby* lobby = new Lobby();

    Player player={"gigel",PlayerColor::RED,false};
    lobby->addPlayer(player);

    ASSERT_EQ(lobby->getPlayers().size(),1);
}
TEST(LobbyTests,AddPlayer2_Validation) {
    Lobby* lobby = new Lobby();


    lobby->addPlayer("gigel",PlayerColor::BLUE);

    ASSERT_EQ(lobby->getPlayers().size(),1);
}

TEST(LobbyTests,RemovePlayer_Validation) {
    Lobby* lobby = new Lobby();


    lobby->addPlayer("gigel",PlayerColor::BLUE);
    lobby->addPlayer("gicu",PlayerColor::RED);
    lobby->removePlayer("gigel");

    ASSERT_EQ(lobby->getPlayers().size(),1);
}
TEST(LobbyTests,GetNextAvailableColor_Validation) {
    Lobby* lobby = new Lobby();


    ASSERT_EQ(lobby->getNextAvailableColor()==PlayerColor::RED,true);
    Player player={"gigel",lobby->getNextAvailableColor(),false};
    lobby->addPlayer(player);
    ASSERT_EQ(lobby->getNextAvailableColor()==PlayerColor::BLUE,true);

}
TEST(LobbyTests,GetPlayers_Validation) {
    Lobby* lobby = new Lobby();

    Player player={"gigel",PlayerColor::RED,false};
    lobby->addPlayer(player);
    std::vector<Player> players={player};
    ASSERT_TRUE(players[0].getUsername()==lobby->getPlayers()[0].getUsername());
}

TEST(LobbyTests,GetAdminPlayer_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    ASSERT_EQ(lobby->getAdminPlayer(),"gigel");
}
TEST(LobbyTests,GetMapType_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    ASSERT_EQ(lobby->getMapType(),MapType::MAP_01);
}

TEST(LobbyTests,GetMaxPlayers_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    ASSERT_EQ(lobby->getMaxPlayers(),4);
}
TEST(LobbyTests,GetLobbyId_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    ASSERT_EQ(lobby->getLobbyId(),1);
}
TEST(LobbyTests,SetAdminPlayer_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    lobby->addPlayer("gicu",PlayerColor::BLUE);
    lobby->setAdminPlayer("gicu");
    ASSERT_EQ(lobby->getAdminPlayer(),"gicu");
}
TEST(LobbyTests,SetMapType_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    lobby->setMapType(MapType::NONE);
    ASSERT_EQ(lobby->getMapType(),MapType::NONE);
}

TEST(LobbyTests,SetMaxPlayers_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    lobby->setMaxPlayers(3);
    ASSERT_EQ(lobby->getMaxPlayers(),3);
}
TEST(LobbyTests,ConvertToJson_Validation) {
    Lobby* lobby = new Lobby(1,"gigel",MapType::MAP_01,4);
    crow::json::wvalue json = lobby->convertToJson();


    ASSERT_FALSE(json.dump().empty());
}





#endif //LOBBYTESTS_H
