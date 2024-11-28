#include "gameplayerinfowidget.h"
#include "ui_gameplayerinfowidget.h"

GamePlayerInfoWidget::GamePlayerInfoWidget(const Player& player, bool isRollingDice, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePlayerInfoWidget)
{
    ui->setupUi(this);
    setUsername(player.getUsername());
    setIsRollingDice(isRollingDice);
    setColor(player.getColor());
}

GamePlayerInfoWidget::~GamePlayerInfoWidget()
{
    delete ui;
}

void GamePlayerInfoWidget::setUsername(const std::string &username) {
    ui->label_username->setText(QString::fromStdString(username).toLower());
}

void GamePlayerInfoWidget::setIsRollingDice(bool isRollingDice) {
    if(isRollingDice) {
        ui->label_dice->show();
    } else {
        ui->label_dice->hide();
    }
}

void GamePlayerInfoWidget::setColor(PlayerColor color) {
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
