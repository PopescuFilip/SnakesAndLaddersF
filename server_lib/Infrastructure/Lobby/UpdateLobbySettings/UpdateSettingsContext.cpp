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

    try
    {
        Lobby lobby = LobbyManager::getInstance().getLobby(request.getLobbyId());
        if (lobby.getAdminPlayer() != request.getPlayerUsername()) {
            return ValidationResponse{ false, "Player is not the admin" };
        }

        if (lobby.getPlayers().size() > request.getMaxPlayers()) {
            return ValidationResponse{ false, "Max players cannot be less than current players" };
        }
    }
    catch (const std::runtime_error&)
    {
        return ValidationResponse{ false, "Lobby does not exist" };
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
