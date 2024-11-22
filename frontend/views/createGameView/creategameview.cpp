#include "CreateGameView.h"
#include "ui_creategameview.h"
#include <iostream>
#include "../../state/UserState.h"
#include "../../state/LobbyState.h"

CreateGameView::CreateGameView(QWidget *parent)
    : QMainWindow(parent)
    , ViewObserver(this)
    , ui(new Ui::CreateGameView)
    , lobbyService(new LobbyService())
{
    ui->setupUi(this);
    lobbyService->addObserver(this);
}

CreateGameView::~CreateGameView()
{
    delete ui;
    delete lobbyService;
}

int CreateGameView::getMapType() {
    return ui->comboBox_map->currentIndex() + 1;
}

int CreateGameView::getPlayerCount() {
    return ui->comboBox_players->currentIndex() + 2;
}

void CreateGameView::on_pushButton_createGame_clicked() {
    std::string username = UserState::getInstance().getUsername();
    int mapType = getMapType();
    int maxPlayers = getPlayerCount();

    try {
        int lobbyId = lobbyService->createLobby(username, mapType, maxPlayers);
        LobbyState::getInstance().getLobby().setLobbyId(lobbyId);
        emit windowPositionChanged(this->pos());
        emit goToLobbyView();
        this->hide();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void CreateGameView::on_pushButton_goBack_clicked() {
    emit windowPositionChanged(this->pos());
    emit goToHomeView();
    this->hide();
}
