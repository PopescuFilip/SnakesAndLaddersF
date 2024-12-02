//
// Created by Alexandru Pestritu on 28.11.2024.
//

#ifndef MAPTYPE_H
#define MAPTYPE_H
#include <qstring.h>

enum class MapType {
    NONE = 0,
    MAP_01 = 1,
    MAP_02 = 2,
    MAP_03 = 3
};


inline QString getMapImagePath(const MapType& mapType) {
    switch (mapType) {
        case MapType::NONE: return {};
        case MapType::MAP_01: return ":/images/map_01.png";
        case MapType::MAP_02: return {};
        case MapType::MAP_03: return {};
    }
    return {};
}
#endif //MAPTYPE_H
