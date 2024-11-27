//
// Created by Alexandru Pestritu on 27.11.2024.
//

#ifndef GAMEUPDATER_H
#define GAMEUPDATER_H

#include <QObject>
#include <QTimer>
#include "../services/GameService.h"
#include "../models/Game.h"

class GameUpdater : public QObject {
    Q_OBJECT

public:
    explicit GameUpdater(QObject* parent = nullptr);
    ~GameUpdater();

    void start(int gameId);
    void stop();

    signals:
        void gameUpdated(const Game& game);
    void errorOccurred(const QString& errorMessage);

    private slots:
        void fetchGameStatus();

private:
    QTimer* timer;
    int gameId;
    GameService* gameService;
};

#endif //GAMEUPDATER_H
