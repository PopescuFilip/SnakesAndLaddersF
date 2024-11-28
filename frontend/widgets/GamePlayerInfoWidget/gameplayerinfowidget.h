#ifndef GAMEPLAYERINFOWIDGET_H
#define GAMEPLAYERINFOWIDGET_H

#include <QWidget>
#include "../../models/Player.h"

namespace Ui {
class GamePlayerInfoWidget;
}

class GamePlayerInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GamePlayerInfoWidget(const Player& player, bool isRollingDice, QWidget *parent = nullptr);
    ~GamePlayerInfoWidget();

private:
    Ui::GamePlayerInfoWidget *ui;
    void setUsername(const std::string& username);
    void setIsRollingDice(bool isRollingDice);
    void setColor(PlayerColor color);
};

#endif // GAMEPLAYERINFOWIDGET_H
