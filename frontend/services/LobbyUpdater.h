//
// Created by Alexandru Pestritu on 24.11.2024.
//

#ifndef LOBBYUPDATER_H
#define LOBBYUPDATER_H

#include <QObject>
#include <QTimer>
#include "../services/LobbyService.h"
#include "../models/Lobby.h"

class LobbyUpdater : public QObject {
    Q_OBJECT

public:
    explicit LobbyUpdater(QObject* parent = nullptr);
    ~LobbyUpdater();

    void start(int lobbyId);
    void stop();

signals:
    void lobbyUpdated(const Lobby& lobby);
    void errorOccurred(const QString& errorMessage);

private slots:
        void fetchLobbyStatus();

private:
    QTimer* timer;
    int lobbyId;
    LobbyService* lobbyService;
};

#endif //LOBBYUPDATER_H
