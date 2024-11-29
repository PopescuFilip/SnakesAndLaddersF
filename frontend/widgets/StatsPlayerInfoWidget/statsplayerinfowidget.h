#ifndef STATSPLAYERINFOWIDGET_H
#define STATSPLAYERINFOWIDGET_H

#include <QWidget>
#include "../../models/Player.h"

namespace Ui {
class StatsPlayerInfoWidget;
}

class StatsPlayerInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatsPlayerInfoWidget(const Player& player, QWidget *parent = nullptr);
    ~StatsPlayerInfoWidget();

private:
    Ui::StatsPlayerInfoWidget *ui;
    void setUsername(const std::string& username);
    void setScore(int score);
    void setColor(PlayerColor color);
};

#endif // STATSPLAYERINFOWIDGET_H
