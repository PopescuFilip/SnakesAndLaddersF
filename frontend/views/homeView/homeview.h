#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QMainWindow>
#include "../../utils/CurrentUser.h"

namespace Ui {
class HomeView;
}

class HomeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeView(QWidget *parent = nullptr);
    ~HomeView();

private:
    Ui::HomeView *ui;
    void setCurrentUser();

private slots:
    void on_pushButton_createGame_clicked();
    void on_pushButton_joinGame_clicked();

signals:
    void goToCreateGameView();
    void goToJoinGameView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // HOMEVIEW_H
