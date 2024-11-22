#include "joingameview.h"

#include <iostream>

#include "ui_joingameview.h"
#include "../../state/UserState.h"
#include "../../state/LobbyState.h"

JoinGameView::JoinGameView(QWidget *parent)
    : QMainWindow(parent)
    , ViewObserver(this)
    , ui(new Ui::JoinGameView)
    , lobbyService(new LobbyService())
{
    ui->setupUi(this);
    lobbyService->addObserver(this);
}

JoinGameView::~JoinGameView()
{
    delete ui;
    delete lobbyService;
}

int JoinGameView::getGameCode() {
    QString code = ui->lineEdit_gameCode->text();
    bool success;
    int gameCode = code.toInt(&success);

    if(success) {
        return gameCode;
    } else {
        return -1;
    }
}

void JoinGameView::on_pushButton_joinGame_clicked() {
    int gameCode = getGameCode();
    std::string username = UserState::getInstance().getUsername();

    try {
        Lobby lobby = lobbyService->joinLobby(gameCode, username);
        LobbyState::getInstance().setLobby(lobby);
        emit windowPositionChanged(this->pos());
        emit goToLobbyView();
        this->hide();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void JoinGameView::on_pushButton_goBack_clicked() {
    emit windowPositionChanged(this->pos());
    emit goToHomeView();
    this->hide();
}
