//
// Created by Alexandru Pestritu on 27.11.2024.
//

#include "Game.h"

Game::Game() : gameId(0), playerTurnIndex(0), diceRolling(false), latestDiceValue(0), shouldFinishGame(false) {}

Game::Game(int gameId, int playerTurnIndex, const std::vector<Player>& players, const TurnTime& turnTime,
           bool diceRolling, int latestDiceValue, bool shouldFinishGame)
        : gameId(gameId), playerTurnIndex(playerTurnIndex), players(players), turnTime(turnTime),
          diceRolling(diceRolling), latestDiceValue(latestDiceValue), shouldFinishGame(shouldFinishGame) {}

int Game::getGameId() const { return gameId; }
void Game::setGameId(int value) { gameId = value; }

int Game::getPlayerTurnIndex() const { return playerTurnIndex; }
void Game::setPlayerTurnIndex(int value) { playerTurnIndex = value; }

std::vector<Player> Game::getPlayers() const { return players; }
void Game::setPlayers(const std::vector<Player>& value) { players = value; }

TurnTime Game::getTurnTime() const { return turnTime; }
void Game::setTurnTime(const TurnTime& value) { turnTime = value; }

bool Game::isDiceRolling() const { return diceRolling; }
void Game::setDiceRolling(bool value) { diceRolling = value; }

int Game::getLatestDiceValue() const { return latestDiceValue; }
void Game::setLatestDiceValue(int value) { latestDiceValue = value; }

bool Game::getShouldFinishGame() const { return shouldFinishGame; }
void Game::setShouldFinishGame(bool value) { shouldFinishGame = value; }

void to_json(nlohmann::json& j, const Game& g) {
    j = nlohmann::json{
            {"gameId", g.gameId},
            {"playerTurnIndex", g.playerTurnIndex},
            {"players", g.players},
            {"turnTime", g.turnTime},
            {"diceRolling", g.diceRolling},
            {"latestDiceValue", g.latestDiceValue},
            {"shouldFinishGame", g.shouldFinishGame}
    };
}

void from_json(const nlohmann::json& j, Game& g) {
    j.at("gameId").get_to(g.gameId);
    j.at("playerTurnIndex").get_to(g.playerTurnIndex);
    j.at("players").get_to(g.players);
    j.at("turnTime").get_to(g.turnTime);
    j.at("diceRolling").get_to(g.diceRolling);
    j.at("latestDiceValue").get_to(g.latestDiceValue);
    j.at("shouldFinishGame").get_to(g.shouldFinishGame);
}