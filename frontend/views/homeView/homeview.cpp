#include "homeview.h"
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

void HomeView::on_pushButton_createGame_clicked() {
    emit windowPositionChanged(this->pos());
    emit goToCreateGameView();
    this->hide();
}

void HomeView::on_pushButton_joinGame_clicked() {
    emit windowPositionChanged(this->pos());
    emit goToJoinGameView();
    this->hide();
}
