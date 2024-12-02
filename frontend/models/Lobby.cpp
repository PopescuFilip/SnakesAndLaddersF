//
// Created by Alexandru Pestritu on 18.11.2024.
//
#include "Lobby.h"

Lobby::Lobby() : lobbyId(0), adminUsername(""), mapType(MapType::NONE), maxPlayers(0), gameId(-1) {}
Lobby::Lobby(int lobbyId, const std::string& adminUsername, MapType mapType, int maxPlayers, int gameId, const std::vector<Player>& players)
    : lobbyId(lobbyId), adminUsername(adminUsername), mapType(mapType), maxPlayers(maxPlayers), gameId(gameId), players(players) {}

int Lobby::getLobbyId() const { return lobbyId; }
void Lobby::setLobbyId(int value) { lobbyId = value; }

std::string Lobby::getAdminUsername() const { return adminUsername; }
void Lobby::setAdminUsername(const std::string& value) { adminUsername = value; }

MapType Lobby::getMapType() const { return mapType; }
void Lobby::setMapType(MapType value) { mapType = value; }

int Lobby::getMaxPlayers() const { return maxPlayers; }
void Lobby::setMaxPlayers(int value) { maxPlayers = value; }

int Lobby::getGameId() const { return gameId; }
void Lobby::setGameId(int value) { gameId = value; }

std::vector<Player> Lobby::getPlayers() const { return players; }
void Lobby::setPlayers(const std::vector<Player>& value) { players = value; }

void to_json(nlohmann::json& j, const Lobby& l) {
    j = nlohmann::json{
            {"lobbyId", l.lobbyId},
            {"adminUsername", l.adminUsername},
            {"mapType", l.mapType},
            {"maxPlayers", l.maxPlayers},
            {"gameId", l.gameId},
            {"players", l.players}
    };
}

void from_json(const nlohmann::json& j, Lobby& l) {
    j.at("lobbyId").get_to(l.lobbyId);
    j.at("adminUsername").get_to(l.adminUsername);
    j.at("mapType").get_to(l.mapType);
    j.at("maxPlayers").get_to(l.maxPlayers);
    j.at("gameId").get_to(l.gameId);
    j.at("players").get_to(l.players);
}
