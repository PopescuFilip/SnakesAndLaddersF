#ifndef LOBBYVIEW_H
#define LOBBYVIEW_H

#include <QMainWindow>
#include "../../observers/ViewObserver.h"
#include "../../services/LobbyService.h"
#include "../../models/Player.h"
#include "../../services/LobbyUpdater.h"

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
    LobbyUpdater* lobbyUpdater;

    void addPlayerToListView(const Player& player);
    void setGameCode(int gameCode);
    void setStartButtonStatus(bool status);
    void setSettingsButtonStatus(bool status);
    bool checkIsAdmin();
    void gameStarted();
    void updateLobbyStatus(const Lobby& lobby);

    int getMapType();
    int getPlayerCount();
    void setCurrentSettings(int mapType, int playerNumber);

protected:
    void showEvent(QShowEvent* event) override;
    void hideEvent(QHideEvent* event) override;

private slots:
    void on_pushButton_gameCode_clicked();
    void on_pushButton_displaySettings_clicked();
    void on_pushButton_leaveLobby_clicked();
    void on_pushButton_startGame_clicked();
    void on_pushButton_goBack_clicked();
    void on_pushButton_saveSettings_clicked();

signals:
    void goToHomeView();
    void goToGameView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // LOBBYVIEW_H
