//
// Created by Alexandru Pestritu on 24.11.2024.
//
#include "LobbyUpdater.h"

LobbyUpdater::LobbyUpdater(QObject* parent)
    : QObject(parent), timer(nullptr), lobbyId(-1), lobbyService(new LobbyService()) {}

LobbyUpdater::~LobbyUpdater() {
    delete timer;
    delete lobbyService;
}

void LobbyUpdater::start(int lobbyId) {
    this->lobbyId = lobbyId;

    if (!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &LobbyUpdater::fetchLobbyStatus);
    }

    if (!timer->isActive()) {
        timer->start(1000);
    }
}

void LobbyUpdater::stop() {
    if (timer && timer->isActive()) {
        timer->stop();
    }
}

void LobbyUpdater::fetchLobbyStatus() {
    try {
        Lobby lobby = lobbyService->getLobbyStatus(lobbyId);
        emit lobbyUpdated(lobby);
    } catch (const std::exception& e) {
        emit errorOccurred(QString::fromStdString(e.what()));
    }
}
