#include "Player.h"

Player::Player(const std::string& strUsername, PlayerColor playerColor, bool isAdmin) :
    m_strUsername{strUsername}, m_PlayerColor{playerColor}, m_bIsLobbyAdmin{isAdmin}, m_iCurrentBoardPosition{0}
{
    // Empty constructor
}

const std::string& Player::getUsername() const
{
    return m_strUsername;
}

PlayerColor Player::getPlayerColor() const
{
    return m_PlayerColor;
}

bool Player::isLobbyAdmin() const
{
    return m_bIsLobbyAdmin;
}

int Player::getCurrentBoardPosition() const
{
    return m_iCurrentBoardPosition;
}

void Player::setCurrentBoardPosition(int iPosition)
{
    m_iCurrentBoardPosition = iPosition;
}