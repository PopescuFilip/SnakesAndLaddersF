#ifndef LEAVELOBBYREQUEST_H
#define LEAVELOBBYREQUEST_H
#include <string>


class LeaveLobbyRequest {
public:
    LeaveLobbyRequest(int lobbyId, const std::string &strPlayerUsername);

    int getLobbyId() const;
    std::string getPlayerUsername() const;
private:
    int m_lobbyId;
    std::string m_strPlayerUsername;
};



#endif //LEAVELOBBYREQUEST_H
