#ifndef JOINGAMEVIEW_H
#define JOINGAMEVIEW_H

#include <QMainWindow>

#include "../../observers/ViewObserver.h"
#include "../../services/LobbyService.h"

namespace Ui {
class JoinGameView;
}

class JoinGameView : public QMainWindow, public ViewObserver
{
    Q_OBJECT

public:
    explicit JoinGameView(QWidget *parent = nullptr);
    ~JoinGameView();

private:
    Ui::JoinGameView *ui;
    LobbyService* lobbyService;
    int getGameCode();
    void validateGameCode(int gameCode);

private slots:
    void on_pushButton_joinGame_clicked();
    void on_pushButton_goBack_clicked();

signals:
    void goToLobbyView();
    void goToHomeView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // JOINGAMEVIEW_H
