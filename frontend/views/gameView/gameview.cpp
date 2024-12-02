#include "gameview.h"

#include <qlayout.h>

#include "ui_gameview.h"
#include "../../state/GameState.h"
#include "../../state/UserState.h"
#include "../../widgets/GamePlayerInfoWidget/gameplayerinfowidget.h"
#include "../../utils/Logger.h"
#include "../../models/DiceValue.h"
#include <QMovie>

GameView::GameView(QWidget *parent)
    : QMainWindow(parent)
    , ViewObserver(this)
    , ui(new Ui::GameView)
    , gameService(new GameService())
    , gameUpdater(new GameUpdater(this))
    , gameMap(nullptr)
    , diceAnimation(new QMovie(":/images/dice-animation.gif"))
{
    ui->setupUi(this);
    gameService->addObserver(this);
    setupMap();

    connect(gameUpdater, &GameUpdater::gameUpdated, this, &GameView::updateGameStatus);
    connect(gameUpdater, &GameUpdater::errorOccurred, [](const QString& errorMessage) {
        Logger::logError(errorMessage.toStdString());
    });
}

GameView::~GameView()
{
    delete ui;
    delete gameService;
    delete gameMap;
    delete diceAnimation;
}

void GameView::setupMap() {
    gameMap = new Map(MapType::MAP_01, 550, 550, this);
    ui->groupBox_map->layout()->addWidget(gameMap);
}

void GameView::addPlayerToListView(const Player &player, bool isRollingDice) {
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget_players);
    GamePlayerInfoWidget* gamePlayerInfoWidget = new GamePlayerInfoWidget(player, isRollingDice);
    const QSize fixedSize = QSize(240, 60);
    item->setSizeHint(fixedSize);
    ui->listWidget_players->setItemWidget(item, gamePlayerInfoWidget);
}

void GameView::setTimer(int seconds) {
    ui->label_timerValue->setText(QString::number(seconds));
}

void GameView::setRollDiceButtonStatus(bool status) {
    ui->pushButton_rollDice->setCursor(status ? QCursor(Qt::PointingHandCursor) : QCursor(Qt::ForbiddenCursor));
}

void GameView::setDiceValue(int diceValue) {
    QPixmap dicePixmap = QPixmap(getDiceImagePath(DiceValue(diceValue)));
    ui->label_dice->setPixmap(dicePixmap);
}

void GameView::setDiceAnimationStatus(bool status) {
    if (status) {
        ui->label_dice->clear();
        ui->label_dice->setMovie(diceAnimation);
        diceAnimation->start();
    } else {
        diceAnimation->stop();
        ui->label_dice->clear();
        setDiceValue(GameState::getInstance().getGame().getLatestDiceValue());
    }
}

bool GameView::checkIsCurrentTurn() {
    int currentPlayerIndex = GameState::getInstance().getGame().getPlayerTurnIndex();
    return GameState::getInstance().getGame().getPlayers()[currentPlayerIndex].getUsername() == UserState::getInstance().getUsername();
}

void GameView::gameEnded() {
    emit windowPositionChanged(this->pos());
    emit goToStatsView();
    this->hide();
}

void GameView::updateGameStatus(const Game &game) {
    int currentDiceValue = GameState::getInstance().getGame().getLatestDiceValue();
    GameState::getInstance().setGame(game);

    if(game.getLatestDiceValue() == 0) {
        GameState::getInstance().getGame().setLatestDiceValue(currentDiceValue);
    }

    setTimer(game.getTurnTime().maxTime - game.getTurnTime().current);
    setDiceAnimationStatus(game.isDiceRolling());
    setRollDiceButtonStatus(checkIsCurrentTurn());
    gameMap->updatePlayers(game.getPlayers());

    ui->listWidget_players->clear();
    for(int i=0; i<game.getPlayers().size(); i++) {
        addPlayerToListView(game.getPlayers()[i], i == game.getPlayerTurnIndex());
    }

    if(game.getShouldFinishGame()) {
        gameEnded();
    }
}

void GameView::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);

    int gameId = GameState::getInstance().getGame().getGameId();
    if(gameId>0) {
        gameUpdater->start(gameId);
    }
}

void GameView::hideEvent(QHideEvent *event) {
    QMainWindow::hideEvent(event);
    gameUpdater->stop();
}

void GameView::on_pushButton_leaveGame_clicked() {
    try {
        int gameId = GameState::getInstance().getGame().getGameId();
        std::string username = UserState::getInstance().getUsername();
        gameService->leaveGame(gameId, username);
        emit windowPositionChanged(this->pos());
        emit goToHomeView();
        this->hide();
        InfoDialog infoDialog("You have successfully left the game.", DialogType::Information);
        infoDialog.exec();
    }
    catch(const std::exception& e) {
        Logger::logError(e.what());
    }
}

void GameView::on_pushButton_rollDice_clicked() {
    try {
        int gameId = GameState::getInstance().getGame().getGameId();
        std::string username = UserState::getInstance().getUsername();
        gameService->rollDice(gameId, username);
    }
    catch(const std::exception& e) {
        Logger::logError(e.what());
    }
}
