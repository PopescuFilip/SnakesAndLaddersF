#include "UpdateSettingsContext.h"
#include "../../../GameManagement/Lobby/LobbyManager.h"

UpdateSettingsResponse UpdateSettingsContext::HandleRequest(const UpdateSettingsRequest &request) {
    if(ValidationResponse response = ValidateRequest(request); !response.isValid()) {
        return UpdateSettingsResponse{response.getMessage()};
    }

    return ApplyChanges(request);
}

ValidationResponse UpdateSettingsContext::ValidateRequest(const UpdateSettingsRequest &request) {
    if(request.getPlayerUsername().empty()) {
        return ValidationResponse{false, "Username cannot be empty"};
    }

    Lobby lobby = LobbyManager::getInstance().getLobby(request.getLobbyId());

    if(lobby.isNull) {
        return ValidationResponse{false, "Lobby does not exist"};
    }

    if(lobby.getAdminPlayer() != request.getPlayerUsername()) {
        return ValidationResponse{false, "Player is not the admin"};
    }

    if(lobby.getMaxPlayers() < request.getMaxPlayers()) {
        return ValidationResponse{false, "Max players cannot be less than current players"};
    }

    return ValidationResponse{true};
}

UpdateSettingsResponse UpdateSettingsContext::ApplyChanges(const UpdateSettingsRequest &request) {
    Lobby lobby = LobbyManager::getInstance().getLobby(request.getLobbyId());
    lobby.setMapType(request.getMapType());
    lobby.setMaxPlayers(request.getMaxPlayers());
    LobbyManager::getInstance().updateLobby(request.getLobbyId(), lobby);

    return UpdateSettingsResponse{true};
}
