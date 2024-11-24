//
// Created by Alexandru Pestritu on 21.11.2024.
//
#include "LobbyState.h"

LobbyState::LobbyState() : m_lobby() {}

LobbyState& LobbyState::getInstance() {
    static LobbyState instance;
    return instance;
}

void LobbyState::setLobby(const Lobby& lobby) {
    std::lock_guard<std::mutex> lock(m_lobbyStateMutex);
    m_lobby = lobby;
}

Lobby LobbyState::getLobby() const {
    std::lock_guard<std::mutex> lock(m_lobbyStateMutex);
    return m_lobby;
}