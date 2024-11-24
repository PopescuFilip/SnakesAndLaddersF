#ifndef PLAYERINFOWIDGET_H
#define PLAYERINFOWIDGET_H

#include <QWidget>

#include "../../models/PlayerColor.h"
#include "../../models/Player.h"

namespace Ui {
class PlayerInfoWidget;
}

class PlayerInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerInfoWidget(const Player& player, QWidget *parent = nullptr);
    ~PlayerInfoWidget();

private:
    Ui::PlayerInfoWidget *ui;
    void setUsername(const std::string& username);
    void setIsAdmin(bool isAdmin);
    void setColor(PlayerColor color);
};

#endif // PLAYERINFOWIDGET_H
