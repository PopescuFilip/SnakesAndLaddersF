#include "StartGameContext.h"

#include "GameManagement/Game/GameManager.h"
#include "GameManagement/Lobby/LobbyManager.h"
#include "GameManagement/Objects/Lobby.h"

StartGameResponse StartGameContext::HandleRequest(const StartGameRequest &request) {
    ValidationResponse validationResponse = ValidateRequest(request);
    if (!validationResponse.isValid()) {
        return StartGameResponse{validationResponse.getMessage()};
    }

    return ApplyChanges(request);
}

StartGameResponse StartGameContext::ApplyChanges(const StartGameRequest &request) {
    Lobby lobby = LobbyManager::getInstance().getLobby(request.GetLobbyId());
    RunningGame runningGame = GameManager::getInstance().createGame(lobby);

    if(runningGame.isNull) {
        const std::string messageResponse = "Failed to start game";
        return StartGameResponse{messageResponse};
    }

    lobby.setGameId(runningGame.getGameId());
    LobbyManager::getInstance().updateLobby(lobby.getLobbyId(), lobby);

    return StartGameResponse{true};

}

ValidationResponse StartGameContext::ValidateRequest(const StartGameRequest &request) {
    const std::string &playerUsername = request.GetPlayerUsername();
    if (playerUsername.empty()) {
        return ValidationResponse{false, "Player username is empty"};
    }

    int lobbyId = request.GetLobbyId();
    if (lobbyId < 0) {
        return ValidationResponse{false, "Lobby id is invalid"};
    }

    const Lobby& lobby = LobbyManager::getInstance().getLobby(lobbyId);
    if(lobby.isNull) {
        return ValidationResponse{false, "Lobby does not exist"};
    }

    if(lobby.getAdminPlayer() != playerUsername) {
        return ValidationResponse{false, "Player is not the admin of the lobby"};
    }

    return ValidationResponse{true};
}
