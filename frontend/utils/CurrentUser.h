//
// Created by Alexandru Pestritu on 20.11.2024.
//

#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <string>
#include <mutex>

class CurrentUser {
public:
    static CurrentUser& getInstance();

    void setUsername(const std::string& username);
    std::string getUsername() const;

    CurrentUser(const CurrentUser&) = delete;
    CurrentUser& operator=(const CurrentUser&) = delete;

private:
    CurrentUser();
    std::mutex m_currentUserMutex;
    std::string m_username;
};

#endif //CURRENTUSER_H
