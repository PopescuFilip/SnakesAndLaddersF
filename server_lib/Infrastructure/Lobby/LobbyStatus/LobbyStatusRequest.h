#ifndef LOBBYSTATUSREQUEST_H
#define LOBBYSTATUSREQUEST_H



class LobbyStatusRequest {
public:
    LobbyStatusRequest(int lobbyId);

    virtual int GetLobbyId() const;
private:
    int m_iLobbyId;
};



#endif //LOBBYSTATUSREQUEST_H
