#ifndef COMMANDTESTS_H
#define COMMANDTESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Infrastructure/Commands/CreateLobbyCommand.h"
#include "Infrastructure/Commands/JoinLobbyCommand.h"
#include "Infrastructure/Commands/ChangeLobbySettingsCommand.h"
#include "Infrastructure/Commands/LeaveLobbyCommand.h"
#include "Infrastructure/Commands/StartGameCommand.h"
#include "Infrastructure/Commands/StatusLobbyCommand.h"
#include "Infrastructure/Commands/GameStatusCommand.h"
#include "Infrastructure/Commands/GameStatisticsCommand.h"
#include "Infrastructure/Commands/LeaveGameCommand.h"
#include "Infrastructure/Commands/RollDiceCommand.h"

#include "GameManagement/Lobby/LobbyManager.h"

int createLobby()
{
	std::string admin("Gigel");
	int maxPlayers = 2;
	return LobbyManager::getInstance().createLobby(admin, MapType::MAP_01, 2);
}

int createGame()
{
	int lobbyId = createLobby();

	Lobby lobby = LobbyManager::getInstance().getLobby(lobbyId);
	RunningGame runningGame = GameManager::getInstance().createGame(lobby);

	int gameId = runningGame.getGameId();

	lobby.setGameId(gameId);
	LobbyManager::getInstance().updateLobby(lobby.getLobbyId(), lobby);

	return gameId;
}

TEST(CommandTest, CreateLobbyCommandTest)
{
	crow::json::wvalue myJson;
	myJson["adminUsername"] = "Gigel";
	myJson["maxPlayers"] = 2;
	myJson["mapType"] = static_cast<int>(MapType::MAP_01);
	crow::json::rvalue request = crow::json::load(myJson.dump());
	CreateLobbyCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, JoinLobbyCommandTest)
{
	int id = createLobby();
	crow::json::wvalue myJson;
	myJson["lobbyId"] = id;
	myJson["username"] = "Flavius";
	crow::json::rvalue request = crow::json::load(myJson.dump());
	JoinLobbyCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, ChangeLobbySettingsCommandTest)
{
	int id = createLobby();
	crow::json::wvalue myJson;
	myJson["lobbyId"] = id;
	myJson["maxPlayers"] = 2;
	myJson["playerUsername"] = "Gigel";
	myJson["mapType"] = static_cast<int>(MapType::MAP_01);
	crow::json::rvalue request = crow::json::load(myJson.dump());
	ChangeLobbySettingsCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, LeaveLobbyCommandTest)
{
	int id = createLobby();
	crow::json::wvalue myJson;
	myJson["lobbyId"] = id;
	myJson["playerUsername"] = "Gigel";
	crow::json::rvalue request = crow::json::load(myJson.dump());
	LeaveLobbyCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, StartGameCommandTest)
{
	int id = createLobby();
	crow::json::wvalue myJson;
	myJson["lobbyId"] = id;
	myJson["playerUsername"] = "Gigel";
	crow::json::rvalue request = crow::json::load(myJson.dump());
	StartGameCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, StatusLobbyCommandTest)
{
	int id = createLobby();
	crow::json::wvalue myJson;
	myJson["lobbyId"] = id;
	crow::json::rvalue request = crow::json::load(myJson.dump());
	StatusLobbyCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, GameStatusCommandTest)
{
	int id = createGame();
	crow::json::wvalue myJson;
	myJson["gameId"] = id;
	crow::json::rvalue request = crow::json::load(myJson.dump());
	GameStatusCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, GameStatisticsCommandTest)
{
	int id = createGame();
	crow::json::wvalue myJson;
	myJson["gameId"] = id;
	crow::json::rvalue request = crow::json::load(myJson.dump());
	GameStatisticsCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, LeaveGameCommandTest)
{
	int id = createGame();
	crow::json::wvalue myJson;
	myJson["gameId"] = id;
	myJson["playerUsername"] = "Gigel";
	crow::json::rvalue request = crow::json::load(myJson.dump());
	LeaveGameCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

TEST(CommandTest, RollDiceCommandTest)
{
	int id = createGame();
	crow::json::wvalue myJson;
	myJson["gameId"] = id;
	myJson["playerUsername"] = "Gigel";
	crow::json::rvalue request = crow::json::load(myJson.dump());
	RollDiceCommand command{ request };

	BaseResponsePtr response = command.executeWithCheck();

	ASSERT_TRUE(response->getMessage().empty());
	ASSERT_TRUE(response);
}

#endif // !COMMANDTESTS_H
