//
// Created by Alexandru Pestritu on 18.11.2024.
//
#include "Player.h"

Player::Player() : username(""), color(PlayerColor::NONE), isAdmin(false), currentBoardPosition(0) {}

Player::Player(const std::string& username, PlayerColor color, bool isAdmin, int currentBoardPosition)
    : username(username), color(color), isAdmin(isAdmin), currentBoardPosition(currentBoardPosition) {}

std::string Player::getUsername() const { return username; }
void Player::setUsername(const std::string& value) { username = value; }

PlayerColor Player::getColor() const { return color; }
void Player::setColor(PlayerColor value) { color = value; }

bool Player::getIsAdmin() const { return isAdmin; }
void Player::setIsAdmin(bool value) { isAdmin = value; }

int Player::getCurrentBoardPosition() const { return currentBoardPosition; }
void Player::setCurrentBoardPosition(int value) { currentBoardPosition = value; }

void to_json(nlohmann::json& j, const Player& p) {
    j = nlohmann::json{{"username", p.username}, {"playerColor", p.color}, {"isLobbyAdmin", p.isAdmin}, {"currentBoardPosition", p.currentBoardPosition}};
}

void from_json(const nlohmann::json& j, Player& p) {
    j.at("username").get_to(p.username);
    j.at("playerColor").get_to(p.color);
    j.at("isLobbyAdmin").get_to(p.isAdmin);
    j.at("currentBoardPosition").get_to(p.currentBoardPosition);
}

bool Player::operator==(const Player& other) const {
    return username == other.username &&
        color == other.color &&
        isAdmin == other.isAdmin &&
        currentBoardPosition == other.currentBoardPosition;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}
