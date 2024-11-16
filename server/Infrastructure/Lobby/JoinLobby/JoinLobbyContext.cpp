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

    if(LobbyManager::getInstance().getLobby(request.getLobbyId()).getLobbyId() == -1) {
        return ValidationResponse{false, "Lobby does not exist"};
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

    return JoinLobbyResponse{request.getLobbyId(), lobby.getAdminPlayer(), lobby.getPlayers(), lobby.getMapType()};
}
