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

void Map::updatePlayers(const std::vector<Player>& players) {
    playerPositions.clear();
    cellPlayerCount.clear();

    int cellWidth = width() / 10;
    int cellHeight = height() / 10;

    for (const Player& player : players) {
        int position = player.getCurrentBoardPosition();

        if (cellPositions.contains(position)) {
            int count = cellPlayerCount.value(position, 0);
            cellPlayerCount[position] = count + 1;

            QPoint basePosition = cellPositions[position];
            QPoint offset = calculatePlayerOffset(players.size(), count, cellWidth, cellHeight);

            playerPositions[player.getColor()] = basePosition + offset;
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

QPoint Map::calculatePlayerOffset(int numPlayers, int playerIndex, int cellWidth, int cellHeight) const {
    const int quarterWidth = cellWidth / 4;
    const int quarterHeight = cellHeight / 4;

    static const QMap<int, QVector<QPoint>> playerOffsets = {
        {2, {QPoint(-quarterWidth, -quarterHeight), QPoint(quarterWidth, quarterHeight)}},
        {3, {QPoint(-quarterWidth, -quarterHeight), QPoint(quarterWidth, -quarterHeight), QPoint(-quarterWidth, quarterHeight)}},
        {4, {QPoint(-quarterWidth, -quarterHeight), QPoint(quarterWidth, -quarterHeight), QPoint(-quarterWidth, quarterHeight), QPoint(quarterWidth, quarterHeight)}}
    };

    if (numPlayers == 1) {
        return QPoint(0, 0);
    }

    if (playerOffsets.contains(numPlayers)) {
        const QVector<QPoint>& offsets = playerOffsets[numPlayers];
        if (playerIndex < offsets.size()) {
            return offsets[playerIndex];
        }
    }

    return QPoint(0, 0);
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

