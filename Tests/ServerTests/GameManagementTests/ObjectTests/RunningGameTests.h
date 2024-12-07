//
// Created by Andrei on 11/21/2024.
//

#ifndef RUNNINGGAMETESTS_H
#define RUNNINGGAMETESTS_H
#include <gtest/gtest.h>
#include <GameManagement/Objects/RunningGame.h>

TEST(RunningGameTests, UpdatePlayerPosition) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    RunningGame game(lobby);

    game.updatePlayerPosition("Flavius", 42);

    EXPECT_EQ(game.getCurrentPlayer().getCurrentBoardPosition(), 42);
}

TEST(RunningGameTests, StartNewTurn) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    RunningGame game(lobby);

    game.startNewTurn();

    EXPECT_TRUE(game.getCurrentTurnTime() <= 1);
    EXPECT_EQ(game.getLatestDiceValue(), 0);
}

TEST(RunningGameTests,TriggerDiceRolling) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    RunningGame game(lobby);

    game.triggerDiceRolling();

    ASSERT_TRUE(game.getDiceRolling());
}

TEST(RunningGameTests,SetDiceValue) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    RunningGame game(lobby);

    game.setLatestDiceValue(6);

    EXPECT_EQ(game.getLatestDiceValue(), 6);
}

TEST(RunningGameTests, SetPlayerTurn) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    Player addedPlayer{ "Gigel", PlayerColor::BLUE, false };
    lobby.addPlayer(addedPlayer);
    RunningGame game(lobby);

    game.setPlayerTurn("Gigel");
    Player& currentPlayer = game.getCurrentPlayer();

    EXPECT_EQ(addedPlayer.getUsername(), currentPlayer.getUsername());
    EXPECT_EQ(addedPlayer.getPlayerColor(), currentPlayer.getPlayerColor());
}

TEST(RunningGameTests, GetShouldFinishGame) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    RunningGame game(lobby);

    game.setShouldFinishGame(true);

    ASSERT_TRUE(game.getShouldFinishGame());
}

TEST(RunningGameTESTS,GetGameId) {
    Lobby lobby(12, "Flavius", MapType::MAP_01, 2);
    RunningGame game(lobby);

    EXPECT_EQ(game.getGameId(), 12);
}


TEST(RunningGameTests,GetPlayers) {

    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    Player addedPlayer{ "Gigel", PlayerColor::BLUE, false };
    lobby.addPlayer(addedPlayer);
    RunningGame game(lobby);

    auto& players = game.getPlayers();

    EXPECT_EQ(players.size(), 2);
    EXPECT_EQ(players[0].getUsername(), "Flavius");
    EXPECT_EQ(players[1].getUsername(), "Gigel");
}

TEST(RunningGameTests, RemovePlayer) {
    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    Player addedPlayer{ "Gigel", PlayerColor::BLUE, false };
    lobby.addPlayer(addedPlayer);
    RunningGame game(lobby);

    int response{ game.removePlayer("Flavius") };

    EXPECT_TRUE(response);
}


TEST(RunningGameTESTS,ConvertToJson) {

    Lobby lobby(1, "Flavius", MapType::MAP_01, 2);
    RunningGame game(lobby);

    crow::json::wvalue result{ game.convertToJson() };

    EXPECT_FALSE(result.dump().empty());
}





#endif //RUNNINGGAMETESTS_H
