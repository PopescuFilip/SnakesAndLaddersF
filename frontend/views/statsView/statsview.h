#ifndef STATSVIEW_H
#define STATSVIEW_H

#include <QMainWindow>

#include "../../services/GameService.h"
#include "../../observers/ViewObserver.h"

namespace Ui {
class StatsView;
}

class StatsView : public QMainWindow, public ViewObserver
{
    Q_OBJECT

public:
    explicit StatsView(QWidget *parent = nullptr);
    ~StatsView();

private:
    Ui::StatsView *ui;
    GameService* gameService;

    void addPlayerToListView(const Player& player);
    void setGameDuration(std::string duration);
    void updateGameStats(const GameStats& gameStats);

protected:
    void showEvent(QShowEvent* event) override;

private slots:
    void on_pushButton_goHome_clicked();

signals:
    void goToHomeView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // STATSVIEW_H
