#include "creategameview.h"
#include "ui_creategameview.h"

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
