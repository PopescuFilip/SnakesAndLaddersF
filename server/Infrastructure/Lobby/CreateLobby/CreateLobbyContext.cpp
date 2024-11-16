#include "CreateLobbyContext.h"

#include "../../../GameManagement/Lobby/LobbyManager.h"

CreateLobbyResponse CreateLobbyContext::HandleRequest(const CreateLobbyRequest &request)
{
    if(ValidationResponse response = ValidateRequest(request); !response.isValid()) {
        return CreateLobbyResponse{response.getMessage()};
    }

    return ApplyChanges(request);
}

CreateLobbyResponse CreateLobbyContext::ApplyChanges(const CreateLobbyRequest &request) {
    LobbyManager::getInstance().createLobby(request.getAdminUsername(), request.getMapType(), request.getMaxPlayers());
    return CreateLobbyResponse{true};
}

ValidationResponse CreateLobbyContext::ValidateRequest(const CreateLobbyRequest &request) {
    int iMaxPlayers = request.getMaxPlayers();
    if(iMaxPlayers < 2 || iMaxPlayers > 4) {
        return ValidationResponse{false, "Max players must be between 2 and 4"};
    }

    return ValidationResponse{true};
}
