#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include "../../models/MapType.h"
#include "../../models/PlayerColor.h"
#include "../../models/Player.h"

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(MapType mapType, int width, int height, QWidget *parent = nullptr);
    ~Map();

    void movePlayer(PlayerColor playerColor, int position);
    void setMap(MapType mapType);
    void setPlayerImage(PlayerColor playerColor);
    void setCorners(const QPoint& bottomLeft, const QPoint& topRight);
    void updatePlayers(const std::vector<Player>& players);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::Map *ui;
    QPixmap backgroundPixmap;
    QMap<int, QPoint> cellPositions;
    QMap<PlayerColor, QPoint> playerPositions;
    QMap<PlayerColor, QPixmap> playerImages;
    void generateGrid(const QPoint& bottomLeft, const QPoint& topRight);
};

#endif // MAP_H
