//
// Created by Alexandru Pestritu on 28.11.2024.
//

#ifndef MAPTYPE_H
#define MAPTYPE_H
#include <qstring.h>

enum class MapType {
    MAP_01,
    MAP_02,
    MAP_03
};


inline QString getMapImagePath(const MapType& mapType) {
    switch (mapType) {
        case MapType::MAP_01: return ":/images/map_01.png";
        case MapType::MAP_02:  return ":/images/map_01.png";
        case MapType::MAP_03:  return ":/images/map_01.png";
    }
    return {};
}
#endif //MAPTYPE_H
