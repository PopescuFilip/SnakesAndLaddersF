//
// Created by Alexandru Pestritu on 18.11.2024.
//
#include "Player.h"

Player::Player() : username(""), color(0), isAdmin(false) {}
Player::Player(const std::string& username, int color, bool isAdmin)
    : username(username), color(color), isAdmin(isAdmin) {}

std::string Player::getUsername() const { return username; }
void Player::setUsername(const std::string& value) { username = value; }

int Player::getColor() const { return color; }
void Player::setColor(int value) { color = value; }

bool Player::getIsAdmin() const { return isAdmin; }
void Player::setIsAdmin(bool value) { isAdmin = value; }

void to_json(nlohmann::json& j, const Player& p) {
    j = nlohmann::json{{"username", p.username}, {"color", p.color}, {"isAdmin", p.isAdmin}};
}

void from_json(const nlohmann::json& j, Player& p) {
    j.at("username").get_to(p.username);
    j.at("color").get_to(p.color);
    j.at("isAdmin").get_to(p.isAdmin);
}
