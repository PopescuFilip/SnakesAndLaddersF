#include "playerinfowidget.h"
#include "ui_playerinfowidget.h"

PlayerInfoWidget::PlayerInfoWidget(const Player& player, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayerInfoWidget)
{
    ui->setupUi(this);
    setUsername(player.getUsername());
    setIsAdmin(player.getIsAdmin());
    setColor(player.getColor());
}

PlayerInfoWidget::~PlayerInfoWidget()
{
    delete ui;
}

void PlayerInfoWidget::setUsername(const std::string &username) {
    ui->label_username->setText(QString::fromStdString(username).toLower());
}

void PlayerInfoWidget::setIsAdmin(bool isAdmin) {
    if(isAdmin) {
        ui->label_crown->show();
    } else {
        ui->label_crown->hide();
    }
}

void PlayerInfoWidget::setColor(PlayerColor color) {
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
