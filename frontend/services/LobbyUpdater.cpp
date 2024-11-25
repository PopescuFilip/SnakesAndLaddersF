#include "LobbyUpdater.h"

const int TIMER_DELAY_SECONDS = 1;

LobbyUpdater::LobbyUpdater(QObject* parent)
    : QObject(parent), timer(nullptr), lobbyId(-1), lobbyService(new LobbyService()) {}

LobbyUpdater::~LobbyUpdater() {
    if (timer) {
        timer->stop();
        delete timer;
    }
    delete lobbyService;
}

void LobbyUpdater::start(int lobbyId) {
    this->lobbyId = lobbyId;

    if (!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &LobbyUpdater::fetchLobbyStatus);
    }

    if (!timer->isActive()) {
        timer->start(TIMER_DELAY_SECONDS * 1000);
    }
}

void LobbyUpdater::stop() {
    if (timer && timer->isActive()) {
        timer->stop();
    }
}

void LobbyUpdater::fetchLobbyStatus() {
    lobbyService->getLobbyStatusAsync(lobbyId, [this](bool success, const QString& errorMessage, const Lobby& lobby) {
        if (success) {
            emit lobbyUpdated(lobby);
        } else {
            emit errorOccurred(errorMessage);
        }
    });
}
