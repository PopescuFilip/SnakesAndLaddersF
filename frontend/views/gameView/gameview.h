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

protected:
    void showEvent(QShowEvent* event) override;
    void hideEvent(QHideEvent* event) override;


signals:
    void goToHomeView();
    void goToStatsView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // GAMEVIEW_H
