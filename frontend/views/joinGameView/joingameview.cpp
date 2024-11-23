#include "joingameview.h"

#include <iostream>

#include "ui_joingameview.h"
#include "../../state/UserState.h"
#include "../../state/LobbyState.h"
#include "../../utils/Logger.h"

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
    if(code.isEmpty()) {
        throw std::invalid_argument("Game code cannot be empty.");
    }
    bool success;
    int gameCode = code.toInt(&success);

    if(success) {
        return gameCode;
    } else {
        return -1;
    }
}

void JoinGameView::validateGameCode(int gameCode) {
    if(gameCode == -1) {
        throw std::invalid_argument("Game code should only contain numbers.");
    }
}

void JoinGameView::on_pushButton_joinGame_clicked() {
    try {
    int gameCode = getGameCode();
    validateGameCode(gameCode);
    std::string username = UserState::getInstance().getUsername();
        Lobby lobby = lobbyService->joinLobby(gameCode, username);
        LobbyState::getInstance().setLobby(lobby);
        emit windowPositionChanged(this->pos());
        emit goToLobbyView();
        this->hide();
    } catch(const std::invalid_argument& e) {
        Logger::logError(e.what());
        InfoDialog infoDialog(e.what(), DialogType::Information);
        infoDialog.exec();
    }
    catch(const std::exception& e) {
        Logger::logError(e.what());
    }
}

void JoinGameView::on_pushButton_goBack_clicked() {
    emit windowPositionChanged(this->pos());
    emit goToHomeView();
    this->hide();
}
