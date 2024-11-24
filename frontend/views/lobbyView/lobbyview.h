#ifndef LOBBYVIEW_H
#define LOBBYVIEW_H

#include <QMainWindow>
#include "../../observers/ViewObserver.h"
#include "../../services/LobbyService.h"
#include "../../models/Player.h"

namespace Ui {
class LobbyView;
}

class LobbyView : public QMainWindow, public ViewObserver
{
    Q_OBJECT

public:
    explicit LobbyView(QWidget *parent = nullptr);
    ~LobbyView();

private:
    Ui::LobbyView *ui;
    LobbyService* lobbyService;
    void addPlayerToListView(const Player& player);
    void setGameCode(int gameCode);
    void setStartButtonStatus(bool status);
    void setSettingsButtonStatus(bool status);

private slots:
    void on_pushButton_gameCode_clicked();
    void on_pushButton_displaySettings_clicked();
    void on_pushButton_leaveLobby_clicked();
    void on_pushButton_startGame_clicked();

signals:
    void goToHomeView();
    void goToGameView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // LOBBYVIEW_H
