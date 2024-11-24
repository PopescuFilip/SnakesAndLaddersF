//
// Created by Alexandru Pestritu on 20.11.2024.
//
#include "UserState.h"

UserState::UserState() : m_username("") {}

UserState& UserState::getInstance() {
    static UserState instance;
    return instance;
}

void UserState::setUsername(const std::string& username) {
    std::lock_guard<std::mutex> lock(m_userStateMutex);
    m_username = username;
}
std::string UserState::getUsername() const {
    return m_username;
}