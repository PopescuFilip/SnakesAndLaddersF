//
// Created by Andrei on 11/21/2024.
//

#ifndef PLAYERTESTS_H
#define PLAYERTESTS_H
#include <gtest/gtest.h>
#include "GameManagement/Objects/Player.h"


TEST(PlayerTest,GetUsername_Validation) {
    Player player=Player("gigel",PlayerColor::RED,false);
    ASSERT_EQ(player.getUsername(),"gigel");

}

TEST(PlayerTest,GetPlayerColor_Validation) {
    Player player=Player("gigel",PlayerColor::RED,false);
    ASSERT_EQ(player.getPlayerColor(),PlayerColor::RED);

}

TEST(PlayerTest,IsLobbyAdmin_Validation) {
    Player player1=Player("gigel",PlayerColor::RED,false);
    Player player2=Player("gigel",PlayerColor::RED,true);
    ASSERT_TRUE(player2.isLobbyAdmin());
    ASSERT_FALSE(player1.isLobbyAdmin());

}
TEST(PlayerTest,SetIsLobbyAdmin_Validation) {
    Player player1=Player("gigel",PlayerColor::RED,false);

    ASSERT_FALSE(player1.isLobbyAdmin());

    player1.setIsLobbyAdmin(true);

    ASSERT_TRUE(player1.isLobbyAdmin());

}
TEST(PlayerTest,GetCurrentBoardPossition_Validation) {
    Player player=Player("gigel",PlayerColor::RED,false);

    ASSERT_EQ(player.getCurrentBoardPosition(),0);

}
TEST(PlayerTest,SetCurrentBoardPossition_Validation) {
    Player player=Player("gigel",PlayerColor::RED,false);
    player.setCurrentBoardPosition(12);

    ASSERT_EQ(player.getCurrentBoardPosition(),12);

}
TEST(PlayerTest,GetJsonValue_Validation) {
    Player player=Player("gigel",PlayerColor::RED,false);

    crow::json::wvalue json=player.getJsonValue();
    ASSERT_FALSE(json.dump().empty());

}

#endif //PLAYERTESTS_H
