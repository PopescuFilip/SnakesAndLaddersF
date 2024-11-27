//
// Created by Alexandru Pestritu on 27.11.2024.
//

#ifndef TURNTIME_H
#define TURNTIME_H

#include <nlohmann/json.hpp>

class TurnTime {
public:
    int current;
    int max;

    TurnTime() : current(0), max(0) {}
    TurnTime(int current, int max) : current(current), max(max) {}

    friend void to_json(nlohmann::json& j, const TurnTime& t) {
        j = nlohmann::json{
                    {"current", t.current},
                    {"max", t.max}
        };
    }

    friend void from_json(const nlohmann::json& j, TurnTime& t) {
        j.at("current").get_to(t.current);
        j.at("max").get_to(t.max);
    }
};

#endif //TURNTIME_H
