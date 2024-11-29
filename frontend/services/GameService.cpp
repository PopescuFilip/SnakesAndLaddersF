//
// Created by Alexandru Pestritu on 27.11.2024.
//

#include "GameService.h"
#include <qcoreapplication.h>

GameService::GameService() {}
GameService::~GameService() {}

Game GameService::getGameStatus(int gameId) {
    try {
        nlohmann::json requestBody = {{"gameId", gameId}};
        nlohmann::json response = executeGet(ApiEndpoints::GET_GAME_STATUS, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

        Game game = response["game"].get<Game>();
        return game;
    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

void GameService::getGameStatusAsync(int gameId, std::function<void(bool, const QString&, const Game&)> callback) {
    std::thread([this, gameId, callback]() {
        try {
            Game game = getGameStatus(gameId);

            QMetaObject::invokeMethod(qApp, [callback, game]() {
                callback(true, QString(), game);
            });
        } catch (const std::exception& e) {
            QString errorMessage = QString::fromStdString(e.what());

            QMetaObject::invokeMethod(qApp, [callback, errorMessage]() {
                callback(false, errorMessage, Game());
            });
        }
    }).detach();
}

void GameService::leaveGame(int gameId, const std::string& playerUsername) {
    try {
        nlohmann::json requestBody = {
            {"gameId", gameId},
            {"playerUsername", playerUsername}
        };
        nlohmann::json response = executePost(ApiEndpoints::LEAVE_GAME, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);
    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

GameStats GameService::getGameStats(int gameId) {
    try {
        nlohmann::json requestBody = {{"gameId", gameId}};
        nlohmann::json response = executeGet(ApiEndpoints::GET_GAME_STATS, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);

        GameStats gameStats = response["gameData"].get<GameStats>();
        return gameStats;
    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

void GameService::rollDice(int gameId, const std::string& playerUsername) {
    try {
        nlohmann::json requestBody = {
            {"gameId", gameId},
            {"playerUsername", playerUsername}
        };
        nlohmann::json response = executePost(ApiEndpoints::GAME_ROLL_DICE, requestBody);

        BaseResponse baseResponse = parseBaseResponse(response);
        ensureSuccess(baseResponse);
    } catch (const std::exception& e) {
        lastErrorMessage = std::string(e.what());
        notifyFailure(lastErrorMessage);
        throw;
    }
}

