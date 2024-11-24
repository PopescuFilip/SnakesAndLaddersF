//
// Created by Alexandru Pestritu on 20.11.2024.
//
#include "LobbyService.h"

LobbyService::LobbyService() {}
LobbyService::~LobbyService() {}

Lobby LobbyService::getLobbyStatus(int lobbyId) {
    try {
        nlohmann::json requestBody = {{"lobbyId", lobbyId}};
        nlohmann::json response = executeGet(ApiEndpoints::GET_LOBBY_STATUS, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

        Lobby lobby = response["lobby"].get<Lobby>();
        return lobby;
    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

int LobbyService::createLobby(const std::string& adminUsername, int mapType, int maxPlayers) {
    try {
        nlohmann::json requestBody = {
            {"adminUsername", adminUsername},
            {"mapType", mapType},
            {"maxPlayers", maxPlayers}
        };
        nlohmann::json response = executePost(ApiEndpoints::CREATE_LOBBY, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

        int lobbyId = response["lobbyId"];
        return lobbyId;
    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

Lobby LobbyService::joinLobby(int lobbyId, const std::string& username) {
    try {
        nlohmann::json requestBody = {
            {"lobbyId", lobbyId},
            {"username", username}
        };
        nlohmann::json response = executePost(ApiEndpoints::JOIN_LOBBY, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

        Lobby lobby = response["lobby"].get<Lobby>();
        return lobby;
    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

void LobbyService::leaveLobby(int lobbyId, const std::string& username) {
    try {
        nlohmann::json requestBody = {
            {"lobbyId", lobbyId},
            {"playerUsername", username}
        };
        nlohmann::json response = executePost(ApiEndpoints::LEAVE_LOBBY, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

void LobbyService::updateLobby(int lobbyId, const std::string& adminUsername, int mapType, int maxPlayers) {
    try {
        nlohmann::json requestBody = {
            {"lobbyId", lobbyId},
            {"playerUsername", adminUsername},
            {"mapType", mapType},
            {"maxPlayers", maxPlayers}
        };
        nlohmann::json response = executePost(ApiEndpoints::UPDATE_LOBBY, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

void LobbyService::startGame(int lobbyId, const std::string &username) {
    try {
        nlohmann::json requestBody = {
            {"lobbyId", lobbyId},
            {"playerUsername", username}
        };
        nlohmann::json response = executePost(ApiEndpoints::START_GAME, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}
