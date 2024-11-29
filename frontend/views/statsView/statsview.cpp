#include "statsview.h"
#include "ui_statsview.h"
#include "../../widgets/StatsPlayerInfoWidget/statsplayerinfowidget.h"
#include "../../utils/Logger.h"
#include "../../state/GameState.h"

StatsView::StatsView(QWidget *parent)
    : QMainWindow(parent)
    , ViewObserver(this)
    , ui(new Ui::StatsView)
    , gameService(new GameService())
{
    ui->setupUi(this);
    gameService->addObserver(this);
}

StatsView::~StatsView()
{
    delete ui;
    delete gameService;
}

void StatsView::addPlayerToListView(const Player &player) {
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget_players);
    StatsPlayerInfoWidget* statsPlayerInfoWidget = new StatsPlayerInfoWidget(player);
    const QSize fixedSize = QSize(295, 60);
    item->setSizeHint(fixedSize);
    ui->listWidget_players->setItemWidget(item, statsPlayerInfoWidget);
}

void StatsView::setGameDuration(std::string duration) {
    ui->label_timerValue->setText(QString::fromStdString(duration));
}

void StatsView::updateGameStats(const GameStats &gameStats) {
    setGameDuration(gameStats.getFormattedGameDuration());

    ui->listWidget_players->clear();

    auto players = gameStats.getPlayers();

    std::sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.getCurrentBoardPosition() > b.getCurrentBoardPosition();
    });

    for (const auto& player : players) {
        addPlayerToListView(player);
    }
}

void StatsView::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);

    try {
        int gameId = GameState::getInstance().getGame().getGameId();
        GameStats gameStats = gameService->getGameStats(gameId);
        updateGameStats(gameStats);
    } catch (const std::exception& e) {
        Logger::logError(e.what());
    }
}

void StatsView::on_pushButton_goHome_clicked() {
    emit windowPositionChanged(this->pos());
    emit goToHomeView();
    this->hide();
}
