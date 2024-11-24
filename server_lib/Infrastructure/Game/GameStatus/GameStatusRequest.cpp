//
// Created by Tudor Andrei on 20.11.2024.
//

#include "GameStatusRequest.h"

GameStatusRequest::GameStatusRequest(int gameId) : m_GameId{gameId} {
}

int GameStatusRequest::getGameId() const {
    return m_GameId;
}
