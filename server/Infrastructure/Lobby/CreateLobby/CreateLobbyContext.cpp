#include "CreateLobbyContext.h"

CreateLobbyResponse CreateLobbyContext::HandleRequest(const CreateLobbyRequest &request)
{
    if(CreateLobbyResponse response = ValidateRequest(request); !response) {
        return response;
    }

    return ApplyChanges(request);
}

CreateLobbyResponse CreateLobbyContext::ApplyChanges(const CreateLobbyRequest &request) {
    // Call the game manager to create a new lobby
}

CreateLobbyResponse CreateLobbyContext::ValidateRequest(const CreateLobbyRequest &request) {
    int iMaxPlayers = request.getMaxPlayers();
    if(iMaxPlayers < 2 || iMaxPlayers > 4) {
        return CreateLobbyResponse{"Invalid number of players"};
    }

    return CreateLobbyResponse{true};
}
