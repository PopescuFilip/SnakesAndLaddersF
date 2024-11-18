//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <nlohmann/json.hpp>

class Player {
private:
    std::string username;
    int color;
    bool isAdmin;

public:
    Player();
    Player(const std::string& username, int color, bool isAdmin);

    std::string getUsername() const;
    void setUsername(const std::string& value);

    int getColor() const;
    void setColor(int value);

    bool getIsAdmin() const;
    void setIsAdmin(bool value);

    friend void to_json(nlohmann::json& j, const Player& p);
    friend void from_json(const nlohmann::json& j, Player& p);
};

#endif //PLAYER_H
