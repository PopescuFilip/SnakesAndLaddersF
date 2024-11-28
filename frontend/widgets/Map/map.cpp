#include "map.h"
#include "ui_map.h"
#include <QPainter>

Map::Map(MapType mapType, int width, int height, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Map)
{
    ui->setupUi(this);
    setMap(mapType);

    setFixedSize(width, height);
    setCorners(QPoint(0, height), QPoint(width, 0));

    backgroundPixmap = QPixmap(getMapImagePath(mapType));
    if (!backgroundPixmap.isNull()) {
        setAutoFillBackground(true);
    }
}

Map::~Map()
{
    delete ui;
}

void Map::movePlayer(PlayerColor playerColor, int position) {
    if (cellPositions.contains(position)) {
        playerPositions[playerColor] = cellPositions[position];
        update();
    }
}

void Map::setMap(MapType mapType) {
    backgroundPixmap = QPixmap(getMapImagePath(mapType));
    if (!backgroundPixmap.isNull()) {
        update();
    }
}

void Map::setPlayerImage(PlayerColor playerColor) {
    QString path = getPlayerImagePath(playerColor);
    QPixmap playerPixmap(path);
    if (!playerPixmap.isNull()) {
        int cellSize = width() / 10;
        int playerIconSize = cellSize * 0.7;

        playerPixmap = playerPixmap.scaled(playerIconSize, playerIconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        playerImages[playerColor] = playerPixmap;
    }
}


void Map::setCorners(const QPoint& bottomLeft, const QPoint& topRight) {
    generateGrid(bottomLeft, topRight);
}

void Map::updatePlayers(const std::vector<Player> &players) {
    playerPositions.clear();

    for (const Player& player : players) {
        int position = player.getCurrentBoardPosition();

        if (cellPositions.contains(position)) {
            playerPositions[player.getColor()] = cellPositions[position];
        }

        setPlayerImage(player.getColor());
    }

    update();
}

void Map::generateGrid(const QPoint& bottomLeft, const QPoint& topRight) {
    cellPositions.clear();
    int rows = 10;
    int cols = 10;

    int widgetWidth = width();
    int widgetHeight = height();

    int cellWidth = widgetWidth / cols;
    int cellHeight = widgetHeight / rows;

    int cellIndex = 1;
    bool reverse = false;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int x = bottomLeft.x() + col * cellWidth + cellWidth / 2;
            int y = bottomLeft.y() - row * cellHeight - cellHeight / 2;
            cellPositions[cellIndex] = QPoint(x, y);
            ++cellIndex;
        }
        reverse = !reverse;
    }
    update();
}


void Map::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    if (!backgroundPixmap.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), backgroundPixmap);
    }

    for (auto it = playerPositions.constBegin(); it != playerPositions.constEnd(); ++it) {
        PlayerColor playerColor = it.key();
        QPoint pos = it.value();
        if (playerImages.contains(playerColor)) {
            QPixmap playerIcon = playerImages[playerColor];
            painter.drawPixmap(pos.x() - playerIcon.width() / 2,
                               pos.y() - playerIcon.height() / 2,
                               playerIcon);
        }
    }
}
