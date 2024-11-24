//
// Created by Alexandru Pestritu on 19.11.2024.
//

#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <memory>

#include <qpoint.h>
#include "../views/homeView/homeview.h"
#include "../views/createGameView/creategameview.h"
#include "../views/joinGameView/joingameview.h"
#include "../views/lobbyView/lobbyview.h"
#include "../views/gameView/gameview.h"

class Lobby;

class ViewManager : public QObject {
    Q_OBJECT

public:
    ViewManager(QObject* parent = nullptr);
    ~ViewManager() = default;

    public slots:
    void showHomeView();
    void showCreateGameView();
    void showJoinGameView();
    void showLobbyView();
    void showGameView();
    void onWindowHidden(const QPoint& position);

private:
    std::unique_ptr<HomeView> m_homeView;
    std::unique_ptr<CreateGameView> m_createGameView;
    std::unique_ptr<JoinGameView> m_joinGameView;
    std::unique_ptr<LobbyView> m_lobbyView;
    std::unique_ptr<GameView> m_gameView;
    void setupConnections();

    QPoint lastWindowPosition;
    void setWindowPosition(QWidget* window);
};


#endif //VIEWMANAGER_H
