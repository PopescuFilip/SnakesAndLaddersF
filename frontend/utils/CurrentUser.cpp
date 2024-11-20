//
// Created by Alexandru Pestritu on 20.11.2024.
//
#include "CurrentUser.h"

CurrentUser::CurrentUser() : m_username("") {}

CurrentUser& CurrentUser::getInstance() {
    static CurrentUser instance;
    return instance;
}

void CurrentUser::setUsername(const std::string& username) {
    std::lock_guard<std::mutex> lock(m_currentUserMutex);
    m_username = username;
}
std::string CurrentUser::getUsername() const {
    return m_username;
}