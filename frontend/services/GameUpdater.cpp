//
// Created by Alexandru Pestritu on 27.11.2024.
//

#include "GameUpdater.h"
#include "../state/GameState.h"

const int TIMER_DELAY_SECONDS = 1;

GameUpdater::GameUpdater(QObject* parent)
    : QObject(parent), timer(nullptr), gameId(-1), gameService(new GameService()) {}

GameUpdater::~GameUpdater() {
    if (timer) {
        timer->stop();
        delete timer;
    }
    delete gameService;
}

void GameUpdater::start(int gameId) {
    this->gameId = gameId;

    if (!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &GameUpdater::fetchGameStatus);
    }

    if (!timer->isActive()) {
        timer->start(TIMER_DELAY_SECONDS * 1000);
    }
}

void GameUpdater::stop() {
    if (timer && timer->isActive()) {
        timer->stop();
    }
}

void GameUpdater::fetchGameStatus() {
    gameService->getGameStatusAsync(gameId, [this](bool success, const QString& errorMessage, const Game& newGame) {
        if (success) {
			const auto& game = GameState::getInstance().getGame();
            if (game != newGame) {
                emit gameUpdated(newGame);
            }
        } else {
            emit errorOccurred(errorMessage);
        }
    });
}
