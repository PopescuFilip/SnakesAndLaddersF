//
// Created by Tudor Andrei on 23.11.2024.
//

#ifndef LEAVEGAMEREQUEST_H
#define LEAVEGAMEREQUEST_H
#include <string>


class LeaveGameRequest {
public:
    LeaveGameRequest(int gameId, const std::string& playerUsername);

    int getGameId() const;
    const std::string& getPlayerUsername() const;
private:
    int m_GameId;
    std::string m_PlayerUsername;
};



#endif //LEAVEGAMEREQUEST_H
