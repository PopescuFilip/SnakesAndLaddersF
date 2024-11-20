#include "RunningGame.h"

RunningGame::RunningGame(const Lobby &baseLobby) : m_Players{baseLobby.getPlayers()} {
    m_GameId = baseLobby.getLobbyId();
    m_MapType = baseLobby.getMapType();
}

void RunningGame::updatePlayerPosition(const std::string &strUsername, int iPosition) {
    auto it = std::find_if(m_Players.begin(), m_Players.end(), [&strUsername](const Player& player) {
        return player.getUsername() == strUsername;
    });

    if(it != m_Players.end()) {
        it->setCurrentBoardPosition(iPosition);
    }
}

void RunningGame::startNewTurn() {
    resetTriggerDiceRolling();
    m_TurnStartTime = std::chrono::system_clock::now();
    m_iCurrentPlayerIndex = (m_iCurrentPlayerIndex + 1) % m_Players.size();
}

int RunningGame::getCurrentTurnTime() const {
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - m_TurnStartTime).count();
}

MapType RunningGame::getMapType() const {
    return m_MapType;
}

void RunningGame::triggerDiceRolling() {
    m_DiceRollStartTime = std::chrono::system_clock::now();
}

void RunningGame::resetTriggerDiceRolling() {
    m_iLatestDiceValue = 0;
    m_DiceRollStartTime = std::chrono::system_clock::now() - std::chrono::seconds(DICE_ROLL_TIME_SECONDS);
}

bool RunningGame::getDiceRolling() const {
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - m_DiceRollStartTime).count() < DICE_ROLL_TIME_SECONDS;
}

void RunningGame::setLatestDiceValue(int iDiceValue) {
    m_iLatestDiceValue = iDiceValue;
}

int RunningGame::getLatestDiceValue() const {
    return m_iLatestDiceValue;
}

void RunningGame::setPlayerTurn(const std::string &strPlayerName) {
    auto it = std::find_if(m_Players.begin(), m_Players.end(), [&strPlayerName](const Player& player) {
        return player.getUsername() == strPlayerName;
    });

    if (it != m_Players.end()) {
        m_iCurrentPlayerIndex = std::distance(m_Players.begin(), it);
    }
}

Player & RunningGame::getCurrentPlayer() {
    return m_Players[m_iCurrentPlayerIndex];
}

void RunningGame::setShouldFinishGame(bool bShouldFinishGame) {
    m_bShouldFinishGame = bShouldFinishGame;
}

bool RunningGame::getShouldFinishGame() const {
    return m_bShouldFinishGame;
}

int RunningGame::getGameId() const {
    return m_GameId;
}

crow::json::wvalue RunningGame::convertToJson() const {
    crow::json::wvalue json;
    json["gameId"] = m_GameId;
    json["playerTurnIndex"] = m_iCurrentPlayerIndex;
    json["mapType"] = static_cast<int>(m_MapType);

    crow::json::wvalue::list playersJson;
    for (const Player& player : m_Players) {
        playersJson.push_back(player.convertToJson());
    }

    json["players"] = std::move(playersJson);
    json["turnTime"]["current"] = getCurrentTurnTime();
    json["turnTime"]["max"] = MAX_SECONDS_PER_TURN;
    json["diceRolling"] = getDiceRolling();
    json["latestDiceValue"] = m_iLatestDiceValue;
    json["shouldFinishGame"] = m_bShouldFinishGame;

    return json;
}

RunningGame::RunningGame() : isNull(true), m_GameId{-1} {
    // Null constructor. Used for error handling
}
