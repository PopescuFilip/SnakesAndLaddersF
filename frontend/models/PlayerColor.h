//
// Created by Alexandru Pestritu on 24.11.2024.
//

#ifndef PLAYERCOLOR_H
#define PLAYERCOLOR_H
#include <qstring.h>

enum class PlayerColor {
    NONE = 0,
    RED = 1,
    BLUE = 2,
    GREEN = 3,
    YELLOW = 4,
};


inline QString getPlayerImagePath(const PlayerColor& playerColor) {
    switch (playerColor) {
        case PlayerColor::RED:    return ":/images/map_player_red.png";
        case PlayerColor::BLUE:   return ":/images/map_player_blue.png";
        case PlayerColor::GREEN:  return ":/images/map_player_green.png";
        case PlayerColor::YELLOW: return ":/images/map_player_yellow.png";
        case PlayerColor::NONE:   return "";
    }
    return {};
}

#endif //PLAYERCOLOR_H
