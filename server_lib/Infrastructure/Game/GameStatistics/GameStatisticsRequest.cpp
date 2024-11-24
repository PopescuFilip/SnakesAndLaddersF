//
// Created by Tudor Andrei on 23.11.2024.
//

#include "GameStatisticsRequest.h"

GameStatisticsRequest::GameStatisticsRequest(int gameId) : m_GameId{gameId} {}

int GameStatisticsRequest::getGameId() const {
    return m_GameId;
}
