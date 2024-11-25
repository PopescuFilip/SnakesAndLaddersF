//
// Created by Tudor Andrei on 15.11.2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <crow/json.h>

#include "BaseObject.h"
#include "PlayerColor.h"

class Player  : public BaseObject {
public:
    Player(const std::string& strUsername, PlayerColor playerColor, bool isAdmin);
    Player();

    virtual const std::string& getUsername() const;
    virtual PlayerColor getPlayerColor() const;
    virtual bool isLobbyAdmin() const;
    virtual int getCurrentBoardPosition() const;
    virtual void setCurrentBoardPosition(int iPosition);

    virtual void setIsLobbyAdmin(bool bIsLobbyAdmin);

    crow::json::wvalue convertToJson() const override;
private:
    std::string m_strUsername;
    PlayerColor m_PlayerColor;
    bool m_bIsLobbyAdmin;
    int m_iCurrentBoardPosition = 0;
};



#endif //PLAYER_H
