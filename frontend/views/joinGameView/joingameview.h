#ifndef JOINGAMEVIEW_H
#define JOINGAMEVIEW_H

#include <QMainWindow>

namespace Ui {
class JoinGameView;
}

class JoinGameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit JoinGameView(QWidget *parent = nullptr);
    ~JoinGameView();

private:
    Ui::JoinGameView *ui;

signals:
    void goToLobbyView();
    void windowPositionChanged(const QPoint& newPosition);
};

#endif // JOINGAMEVIEW_H
