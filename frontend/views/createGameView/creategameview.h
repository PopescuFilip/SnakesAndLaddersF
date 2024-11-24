#ifndef CREATEGAMEVIEW_H
#define CREATEGAMEVIEW_H

#include <QMainWindow>
#include "../../observers/ViewObserver.h"
#include "../../services/LobbyService.h"
#include <QMessageBox>

namespace Ui {
    class CreateGameView;
}

class CreateGameView : public QMainWindow, public ViewObserver
{
    Q_OBJECT

public:
    explicit CreateGameView(QWidget *parent = nullptr);
    ~CreateGameView();

private:
    Ui::CreateGameView *ui;
    int getMapType();
    int getPlayerCount();
    LobbyService* lobbyService;

private slots:
    void on_pushButton_createGame_clicked();
    void on_pushButton_goBack_clicked();

signals:
    void goToLobbyView();
    void goToHomeView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // CREATEGAMEVIEW_H
