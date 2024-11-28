#include "gameview.h"
#include "ui_gameview.h"

GameView::GameView(QWidget *parent)
    : QMainWindow(parent)
    , ViewObserver(this)
    , ui(new Ui::GameView)
    , gameService(new GameService())
    , gameUpdater(new GameUpdater(this))
{
    ui->setupUi(this);
    gameService->addObserver(this);
}

GameView::~GameView()
{
    delete ui;
    delete gameService;
}

void GameView::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
}

void GameView::hideEvent(QHideEvent *event) {
    QMainWindow::hideEvent(event);
}
