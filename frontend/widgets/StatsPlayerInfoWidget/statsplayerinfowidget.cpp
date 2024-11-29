#include "statsplayerinfowidget.h"
#include "ui_statsplayerinfowidget.h"

StatsPlayerInfoWidget::StatsPlayerInfoWidget(const Player& player, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatsPlayerInfoWidget)
{
    ui->setupUi(this);
    setUsername(player.getUsername());
    setScore(player.getCurrentBoardPosition());
    setColor(player.getColor());
}

StatsPlayerInfoWidget::~StatsPlayerInfoWidget()
{
    delete ui;
}

void StatsPlayerInfoWidget::setUsername(const std::string &username) {
    ui->label_username->setText(QString::fromStdString(username).toLower());
}

void StatsPlayerInfoWidget::setScore(int score) {
    ui->label_score->setText(QString::number(score));
}

void StatsPlayerInfoWidget::setColor(PlayerColor color) {
    QString pixmapPath;

    switch (color) {
        case PlayerColor::RED:
            pixmapPath = ":/images/player_red.png";
        break;
        case PlayerColor::BLUE:
            pixmapPath = ":/images/player_blue.png";
        break;
        case PlayerColor::GREEN:
            pixmapPath = ":/images/player_green.png";
        break;
        case PlayerColor::YELLOW:
            pixmapPath = ":/images/player_yellow.png";
        break;
        default:
            break;
    }

    ui->label_playerColor->setPixmap(QPixmap(pixmapPath));
}
