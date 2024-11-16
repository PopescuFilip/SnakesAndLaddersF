//
// Created by Tudor Andrei on 15.11.2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "PlayerColor.h"

class Player {
public:
    Player(const std::string& strUsername, PlayerColor playerColor, bool isAdmin);
    virtual ~Player() = default;
    const std::string& getUsername() const;
    PlayerColor getPlayerColor() const;
    bool isLobbyAdmin() const;
    int getCurrentBoardPosition() const;
    void setCurrentBoardPosition(int iPosition);
private:
    std::string m_strUsername;
    PlayerColor m_PlayerColor;
    bool m_bIsLobbyAdmin;
    int m_iCurrentBoardPosition = 0; // Default value is 0. Everyone starts at 0.
};



#endif //PLAYER_H
