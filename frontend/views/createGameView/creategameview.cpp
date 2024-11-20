#include "creategameview.h"

#include <iostream>

#include "ui_creategameview.h"
#include "../../utils/CurrentUser.h"

CreateGameView::CreateGameView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateGameView)
{
    ui->setupUi(this);
}

CreateGameView::~CreateGameView()
{
    delete ui;
}

int CreateGameView::getMapType() {
    return ui->comboBox_map->currentIndex() + 1;
}

int CreateGameView::getPlayerCount() {
    return ui->comboBox_players->currentIndex() + 2;
}

void CreateGameView::on_pushButton_createGame_clicked() {
    emit windowPositionChanged(this->pos());
    emit goToLobbyView();
    this->hide();
}
