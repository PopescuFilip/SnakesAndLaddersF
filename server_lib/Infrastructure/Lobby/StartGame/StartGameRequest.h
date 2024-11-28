#ifndef STARTGAMEREQUEST_H
#define STARTGAMEREQUEST_H
#include <string>


class StartGameRequest {
public:
    StartGameRequest(int lobbyId, const std::string& playerUsername);

    virtual int GetLobbyId() const;
    virtual std::string GetPlayerUsername() const;
private:
    int m_iLobbyId;
    std::string m_strPlayerUsername;
};



#endif //STARTGAMEREQUEST_H
