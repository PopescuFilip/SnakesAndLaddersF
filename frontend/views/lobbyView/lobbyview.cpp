#include "lobbyview.h"

#include <iostream>

#include "ui_lobbyview.h"
#include <QListWidgetItem>
#include "../../widgets/PlayerInfoWidget/playerinfowidget.h"
#include <QClipboard>

#include "../../state/GameState.h"
#include "../../state/LobbyState.h"
#include "../../state/UserState.h"
#include "../../utils/Logger.h"
#include "../../widgets/InfoDialog/infodialog.h"

LobbyView::LobbyView(QWidget *parent)
    : QMainWindow(parent)
    , ViewObserver(this)
    , ui(new Ui::LobbyView)
    , lobbyService(new LobbyService())
    , lobbyUpdater(new LobbyUpdater(this))
{
    ui->setupUi(this);
    lobbyService->addObserver(this);

    connect(lobbyUpdater, &LobbyUpdater::lobbyUpdated, this, &LobbyView::updateLobbyStatus);
    connect(lobbyUpdater, &LobbyUpdater::errorOccurred, [](const QString& errorMessage) {
        Logger::logError(errorMessage.toStdString());
    });

    ui->groupBox_lobbySettings->hide();
}

LobbyView::~LobbyView()
{
    delete ui;
    delete lobbyService;
}

void LobbyView::showEvent(QShowEvent* event) {
    QMainWindow::showEvent(event);

    int lobbyId = LobbyState::getInstance().getLobby().getLobbyId();
    if (lobbyId > 0) {
        lobbyUpdater->start(lobbyId);
    }
}

void LobbyView::hideEvent(QHideEvent* event) {
    QMainWindow::hideEvent(event);
    lobbyUpdater->stop();
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
    ui->pushButton_startGame->setCursor(status ? QCursor(Qt::PointingHandCursor) : QCursor(Qt::ForbiddenCursor));
}

void LobbyView::setSettingsButtonStatus(bool status) {
    ui->pushButton_displaySettings->setCursor(status ? QCursor(Qt::PointingHandCursor) : QCursor(Qt::ForbiddenCursor));
}

bool LobbyView::checkIsAdmin() {
    return LobbyState::getInstance().getLobby().getAdminUsername() == UserState::getInstance().getUsername();
}

void LobbyView::gameStarted() {
    emit windowPositionChanged(this->pos());
    emit goToGameView();
    this->hide();
}

void LobbyView::updateLobbyStatus(const Lobby& lobby) {
    LobbyState::getInstance().setLobby(lobby);

    if(lobby.getGameId() != -1) {
        GameState::getInstance().getGame().setGameId(lobby.getGameId());
        gameStarted();
    }

    setGameCode(lobby.getLobbyId());
    setStartButtonStatus(checkIsAdmin());
    setSettingsButtonStatus(checkIsAdmin());

    ui->listWidget_players->clear();
    for (const auto& player : lobby.getPlayers()) {
        addPlayerToListView(player);
    }
}

int LobbyView::getMapType() {
    return ui->comboBox_map->currentIndex() + 1;
}

int LobbyView::getPlayerCount() {
    return ui->comboBox_players->currentIndex() + 2;
}

void LobbyView::setCurrentSettings(MapType mapType, int playerNumber) {
    int mapIndex = static_cast<int>(mapType) - 1;
    ui->comboBox_map->setCurrentIndex(mapIndex);
    ui->comboBox_players->setCurrentIndex(playerNumber - 2);
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
    if(!checkIsAdmin()) {
        InfoDialog infoDialog("Only admin can edit game settings.", DialogType::Information);
        infoDialog.exec();
    }
    else {
        setCurrentSettings(LobbyState::getInstance().getLobby().getMapType(), LobbyState::getInstance().getLobby().getMaxPlayers());
        ui->groupBox_lobbyInfo->hide();
        ui->groupBox_lobbySettings->show();
    }
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
    if(!checkIsAdmin()) {
        InfoDialog infoDialog("Only admin can start the game.", DialogType::Information);
        infoDialog.exec();
    }
    else {
        try {
            int lobbyId = LobbyState::getInstance().getLobby().getLobbyId();
            std::string username = UserState::getInstance().getUsername();
            lobbyService->startGame(lobbyId, username);
        } catch(const std::exception& e) {
            Logger::logError(e.what());
        }
    }
}

void LobbyView::on_pushButton_goBack_clicked() {
    ui->groupBox_lobbyInfo->show();
    ui->groupBox_lobbySettings->hide();
}

void LobbyView::on_pushButton_saveSettings_clicked() {
    try {
        int lobbyId = LobbyState::getInstance().getLobby().getLobbyId();
        std::string username = UserState::getInstance().getUsername();
        int mapType = getMapType();
        int playerCount = getPlayerCount();
        lobbyService->updateLobby(lobbyId, username, mapType, playerCount);
        ui->groupBox_lobbySettings->hide();
        ui->groupBox_lobbyInfo->show();
        InfoDialog infoDialog("Game settings updated successfully.", DialogType::Information);
        infoDialog.exec();
    } catch(const std::exception& e) {
        Logger::logError(e.what());
    }
}
