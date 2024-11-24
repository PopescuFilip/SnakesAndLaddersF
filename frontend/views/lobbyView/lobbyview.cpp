#include "lobbyview.h"
#include "ui_lobbyview.h"

LobbyView::LobbyView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LobbyView)
{
    ui->setupUi(this);
}

LobbyView::~LobbyView()
{
    delete ui;
}
