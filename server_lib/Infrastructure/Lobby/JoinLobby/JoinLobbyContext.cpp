#include "JoinLobbyContext.h"

#include "../../../GameManagement/Lobby/LobbyManager.h"

JoinLobbyResponse JoinLobbyContext::HandleRequest(const JoinLobbyRequest &request) {
    if(ValidationResponse response = ValidateRequest(request); !response.isValid()) {
        return JoinLobbyResponse{response.getMessage()};
    }

    return ApplyChanges(request);
}

ValidationResponse JoinLobbyContext::ValidateRequest(const JoinLobbyRequest &request) {
    if(request.getUsername().empty()) {
        return ValidationResponse{false, "Username cannot be empty"};
    }

    const LobbyManager lobbyManager = LobbyManager::getInstance();
    
    try
    {
        const Lobby lobby = lobbyManager.getLobby(request.getLobbyId());

        if (lobby.getPlayers().size() == lobby.getMaxPlayers()) {
            return ValidationResponse{ false, "Lobby is full" };
        }

        for (const Player& player : lobby.getPlayers()) {
            if (player.getUsername() == request.getUsername()) {
                return ValidationResponse{ false, "Player already exists in lobby" };
            }
        }
    }
    catch (const std::exception&)
    {
        return ValidationResponse{ false, "Lobby does not exist" };
    }

    return ValidationResponse{true};
}

JoinLobbyResponse JoinLobbyContext::ApplyChanges(const JoinLobbyRequest &request) {
    Lobby lobby = LobbyManager::getInstance().getLobby(request.getLobbyId());
    const PlayerColor color = lobby.getNextAvailableColor();
    bool playerAdded = lobby.addPlayer(request.getUsername(), color);
    if(!playerAdded) {
        return JoinLobbyResponse{"Lobby is full"};
    }
    LobbyManager::getInstance().updateLobby(request.getLobbyId(), lobby);

    return JoinLobbyResponse{lobby};
}
