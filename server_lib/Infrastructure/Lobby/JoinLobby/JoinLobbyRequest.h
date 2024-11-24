#ifndef JOINLOBBYREQUEST_H
#define JOINLOBBYREQUEST_H
#include <string>


class JoinLobbyRequest {
public:
    JoinLobbyRequest(int lobbyId, const std::string& strUsername);

    int getLobbyId() const;
    const std::string& getUsername() const;

private:
    int m_iLobbyId;
    std::string m_strUsername;
};



#endif //JOINLOBBYREQUEST_H
