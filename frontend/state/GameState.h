//
// Created by Alexandru Pestritu on 27.11.2024.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../models/Game.h"
#include <mutex>

class GameState {
public:
    static GameState& getInstance();

    void setGame(const Game& game);
    Game& getGame();

    GameState(const GameState&) = delete;
    GameState& operator=(const GameState&) = delete;

private:
    GameState();
    mutable std::mutex m_gameStateMutex;
    Game m_game;
};

#endif //GAMESTATE_H
