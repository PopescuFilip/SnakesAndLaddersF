#ifndef CREATEGAMEVIEW_H
#define CREATEGAMEVIEW_H

#include <QMainWindow>

namespace Ui {
class CreateGameView;
}

class CreateGameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateGameView(QWidget *parent = nullptr);
    ~CreateGameView();

private:
    Ui::CreateGameView *ui;
    int getMapType();
    int getPlayerCount();

private slots:
    void on_pushButton_createGame_clicked();

signals:
    void goToLobbyView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // CREATEGAMEVIEW_H
