//
// Created by Alexandru Pestritu on 27.11.2024.
//

#include "GameState.h"

GameState::GameState() : m_game() {}

GameState& GameState::getInstance() {
    static GameState instance;
    return instance;
}

void GameState::setGame(const Game& game) {
    std::lock_guard<std::mutex> lock(m_gameStateMutex);
    m_game = game;
}

Game& GameState::getGame() {
    std::lock_guard<std::mutex> lock(m_gameStateMutex);
    return m_game;
}
