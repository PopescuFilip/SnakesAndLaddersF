#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QMainWindow>

#include "../../services/GameService.h"
#include "../../services/GameUpdater.h"
#include "../../observers/ViewObserver.h"
#include "../../widgets/Map/map.h"

namespace Ui {
class GameView;
}

class GameView : public QMainWindow, public ViewObserver
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);
    ~GameView();

private:
    Ui::GameView *ui;
    GameService* gameService;
    GameUpdater* gameUpdater;
    Map* gameMap;
    QMovie* diceAnimation;

    void setupMap();
    void addPlayerToListView(const Player& player, bool isRollingDice);
    void setTimer(int seconds);
    void setRollDiceButtonStatus(bool status);
    void setDiceValue(int diceValue);
    void setDiceAnimationStatus(bool status);
    bool checkIsCurrentTurn();
    void gameEnded();
    void updateGameStatus(const Game& game);

protected:
    void showEvent(QShowEvent* event) override;
    void hideEvent(QHideEvent* event) override;

private slots:
    void on_pushButton_leaveGame_clicked();
    void on_pushButton_rollDice_clicked();

signals:
    void goToHomeView();
    void goToStatsView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // GAMEVIEW_H
