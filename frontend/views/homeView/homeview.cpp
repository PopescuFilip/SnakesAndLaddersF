#include "homeview.h"

#include <iostream>

#include "ui_homeview.h"

HomeView::HomeView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeView)
{
    ui->setupUi(this);
}

HomeView::~HomeView()
{
    delete ui;
}

void HomeView::setCurrentUser() {
    std::string username = ui->lineEdit_username->text().toUtf8().constData();
    CurrentUser::getInstance().setUsername(username);
}

void HomeView::on_pushButton_createGame_clicked() {
    setCurrentUser();
    emit windowPositionChanged(this->pos());
    emit goToCreateGameView();
    this->hide();
}

void HomeView::on_pushButton_joinGame_clicked() {
    setCurrentUser();
    emit windowPositionChanged(this->pos());
    emit goToJoinGameView();
    this->hide();
}
