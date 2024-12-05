#include "LeaveLobbyContext.h"
#include "../../../GameManagement/Lobby/LobbyManager.h"

LeaveLobbyResponse LeaveLobbyContext::HandleRequest(const LeaveLobbyRequest &request) {

    if(ValidationResponse validationResponse = ValidateRequest(request); !validationResponse.isValid()) {
        return LeaveLobbyResponse(validationResponse.getMessage());
    }

    return ApplyChanges(request);
}

LeaveLobbyResponse LeaveLobbyContext::ApplyChanges(const LeaveLobbyRequest &request) {
    Lobby lobby = LobbyManager::getInstance().getLobby(request.getLobbyId());
    const bool result = lobby.removePlayer(request.getPlayerUsername());

    if(!result) {
        const std::string message = "Player not found in lobby";
        return LeaveLobbyResponse(message);
    }

    if(lobby.getPlayers().empty()) {
        LobbyManager::getInstance().removeLobby(lobby.getLobbyId());
        return LeaveLobbyResponse(true);
    }

    LobbyManager::getInstance().updateLobby(lobby.getLobbyId(), lobby);
    return LeaveLobbyResponse(true);

}

ValidationResponse LeaveLobbyContext::ValidateRequest(const LeaveLobbyRequest &request) {
    try
    {
        const auto& lobby = LobbyManager::getInstance().getLobby(request.getLobbyId());
    }
    catch (const std::runtime_error&)
    {
        return ValidationResponse(false, "Lobby does not exist");
    }

    return ValidationResponse(true);
}