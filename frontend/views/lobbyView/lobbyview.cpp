#include "lobbyview.h"
#include "ui_lobbyview.h"
#include <QListWidgetItem>
#include "../../widgets/PlayerInfoWidget/playerinfowidget.h"
#include <QClipboard>

#include "../../state/LobbyState.h"
#include "../../state/UserState.h"
#include "../../utils/Logger.h"
#include "../../widgets/InfoDialog/infodialog.h"

LobbyView::LobbyView(QWidget *parent)
    : QMainWindow(parent)
    , ViewObserver(this)
    , ui(new Ui::LobbyView)
    , lobbyService(new LobbyService())
{
    ui->setupUi(this);
    lobbyService->addObserver(this);
}

LobbyView::~LobbyView()
{
    delete ui;
    delete lobbyService;
}

void LobbyView::addPlayerToListView(const Player &player) {
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget_players);
    PlayerInfoWidget* playerInfoWidget = new PlayerInfoWidget(player);
    const QSize fixedSize = QSize(261, 60);
    item->setSizeHint(fixedSize);
    ui->listWidget_players->setItemWidget(item, playerInfoWidget);
}

void LobbyView::setGameCode(int gameCode) {
    ui->pushButton_gameCode->setText(QString::number(gameCode));
}

void LobbyView::setStartButtonStatus(bool status) {
    if(status) {
        ui->pushButton_startGame->setEnabled(true);
    }
    else {
        ui->pushButton_startGame->setEnabled(false);
    }
}

void LobbyView::setSettingsButtonStatus(bool status) {
    if(status) {
        ui->pushButton_displaySettings->setEnabled(true);
    }
    else {
        ui->pushButton_displaySettings->setEnabled(false);
    }
}


void LobbyView::on_pushButton_gameCode_clicked() {
    try {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(ui->pushButton_gameCode->text());
        InfoDialog infoDialog("Game code successfully copied to clipboard!", DialogType::Information);
        infoDialog.exec();
    }
    catch(const std::exception &e) {
        Logger::logError(e.what());
    }
}

void LobbyView::on_pushButton_displaySettings_clicked() {
}

void LobbyView::on_pushButton_leaveLobby_clicked() {
    try {
        int lobbyId = LobbyState::getInstance().getLobby().getLobbyId();
        std::string username = UserState::getInstance().getUsername();
        lobbyService->leaveLobby(lobbyId, username);
        emit windowPositionChanged(this->pos());
        emit goToHomeView();
        this->hide();
        InfoDialog infoDialog("You have successfully left the lobby.", DialogType::Information);
        infoDialog.exec();
    }
    catch(const std::exception& e) {
        Logger::logError(e.what());
    }
}

void LobbyView::on_pushButton_startGame_clicked() {
}
