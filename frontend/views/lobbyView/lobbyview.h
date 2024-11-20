#ifndef LOBBYVIEW_H
#define LOBBYVIEW_H

#include <QMainWindow>

namespace Ui {
class LobbyView;
}

class LobbyView : public QMainWindow
{
    Q_OBJECT

public:
    explicit LobbyView(QWidget *parent = nullptr);
    ~LobbyView();

private:
    Ui::LobbyView *ui;
};

#endif // LOBBYVIEW_H
