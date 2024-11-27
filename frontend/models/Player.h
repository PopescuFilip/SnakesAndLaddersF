//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <nlohmann/json.hpp>
#include "PlayerColor.h"

class Player {
private:
    std::string username;
    PlayerColor color;
    bool isAdmin;
    int currentBoardPosition;

public:
    Player();
    Player(const std::string& username, PlayerColor color, bool isAdmin, int currentBoardPosition);

    std::string getUsername() const;
    void setUsername(const std::string& value);

    PlayerColor getColor() const;
    void setColor(PlayerColor value);

    bool getIsAdmin() const;
    void setIsAdmin(bool value);

    int getCurrentBoardPosition() const;
    void setCurrentBoardPosition(int value);

    friend void to_json(nlohmann::json& j, const Player& p);
    friend void from_json(const nlohmann::json& j, Player& p);
};

#endif //PLAYER_H
