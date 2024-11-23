#include "RollDiceRequest.h"

RollDiceRequest::RollDiceRequest(int gameId, const std::string &strPlayerName) : m_GameId{gameId}, m_strPlayerName{strPlayerName} {

}

int RollDiceRequest::getGameId() const {
    return m_GameId;
}

const std::string &RollDiceRequest::getPlayerName() const {
    return m_strPlayerName;
}
