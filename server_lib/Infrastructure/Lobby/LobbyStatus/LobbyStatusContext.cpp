#include "LobbyStatusContext.h"

#include "../../../GameManagement/Lobby/LobbyManager.h"

LobbyStatusResponse LobbyStatusContext::HandleRequest(const LobbyStatusRequest &request) {
    if(ValidationResponse response = ValidateRequest(request); !response.isValid()) {
        return LobbyStatusResponse{response.getMessage()};
    }

    return ApplyChanges(request);
}

ValidationResponse LobbyStatusContext::ValidateRequest(const LobbyStatusRequest &request) {
    if(request.GetLobbyId() < 0) {
        return ValidationResponse{false, "Lobby ID cannot be negative"};
    }

    return ValidationResponse{true};
}

LobbyStatusResponse LobbyStatusContext::ApplyChanges(const LobbyStatusRequest &request) {
    Lobby lobby = LobbyManager::getInstance().getLobby(request.GetLobbyId());

    if(lobby.isNull) {
        return LobbyStatusResponse{"Lobby does not exist"};
    }

    return LobbyStatusResponse{lobby};
}

