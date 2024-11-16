#include "CreateLobbyContext.h"

#include "../../../GameManagement/Lobby/LobbyManager.h"

CreateLobbyResponse CreateLobbyContext::HandleRequest(const CreateLobbyRequest &request)
{
    if(CreateLobbyResponse response = ValidateRequest(request); !response) {
        return response;
    }

    ApplyChanges(request);
    return CreateLobbyResponse{true};
}

void CreateLobbyContext::ApplyChanges(const CreateLobbyRequest &request) {
    LobbyManager::getInstance().createLobby(request.getAdminUsername(), request.getMapType(), request.getMaxPlayers());
}

CreateLobbyResponse CreateLobbyContext::ValidateRequest(const CreateLobbyRequest &request) {
    int iMaxPlayers = request.getMaxPlayers();
    if(iMaxPlayers < 2 || iMaxPlayers > 4) {
        return CreateLobbyResponse{"Invalid number of players"};
    }

    return CreateLobbyResponse{true};
}
