//
// Created by Alexandru Pestritu on 20.11.2024.
//

#ifndef USERSTATE_H
#define USERSTATE_H

#include <string>
#include <mutex>

class UserState {
public:
    static UserState& getInstance();

    void setUsername(const std::string& username);
    std::string getUsername() const;

    UserState(const UserState&) = delete;
    UserState& operator=(const UserState&) = delete;

private:
    UserState();
    std::mutex m_userStateMutex;
    std::string m_username;
};

#endif //USERSTATE_H
