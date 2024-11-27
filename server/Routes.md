# Server Routes

## GET `/lobby/status`
### Request
Request the status of a lobby. The request is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby to get the status of.

Json Request Example:
```json
{
    "lobbyId": 1
}
```
### Response
Returns the status of the lobby. The response is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby.
- `adminUsername`: The username of the admin of the lobby. For easier access
- `mapType`: The type of map that the game will start in.
- `maxPlayers`: The maximum number of players that can join the lobby.
- `gameId`: The ID of the game that the lobby is associated with. If the game has not started, this will be `-1`.
- `players`: An array of player objects, each with the following fields:
  - `username`: The username if the player
  - `playerColor`: The color of the player.
  - `isLobbyAdmin`: A boolean indicating whether the player is the admin of the lobby.
  - `currentBoardPosition`: The current position of the player on the board. This is only relevant if the game has started.

Json Response example:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success",
  "lobby": {
    "lobbyId": 1,
    "adminUsername": "player1",
    "mapType": 1,
    "maxPlayers": 2,
    "gameId": -1,
    "players": [
      {
        "username": "player1",
        "playerColor": 1,
        "isLobbyAdmin": true,
        "currentBoardPosition": 0
      },
      {
        "username": "player2",
        "playerColor": 1,
        "isLobbyAdmin": false,
        "currentBoardPosition": 0
      }
    ]
  }
}
```

## POST `/lobby/create`
### Request
Create a new lobby. The request is a JSON object with the following fields:
- `adminUsername`: The username of the player creating the lobby. This player will be the admin of the lobby.
- `mapType`: The type of map that the game will start in.
- `maxPlayers`: The maximum number of players that can join the lobby.

Json Request Example:
```json
{
    "adminUsername": "player1",
    "mapType": 1,
    "maxPlayers": 2
}
```

### Response
Returns the status of the lobby. The response is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby.

Json Response example:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success",
  "lobbyId": 1
}
```

## POST `/lobby/join`
### Request
Join a lobby. The request is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby to join.
- `username`: The username of the player joining the lobby.

Json Request Example:
```json
{
    "lobbyId": 1,
    "username": "player2"
}
```

### Response
Returns the status of the lobby. The response is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby.
- `adminUsername`: The username of the admin of the lobby. For easier access
- `mapType`: The type of map that the game will start in.
- `maxPlayers`: The maximum number of players that can join the lobby.
- `gameId`: The ID of the game that the lobby is associated with. If the game has not started, this will be `-1`.
- `players`: An array of player objects, each with the following fields:
    - `username`: The username if the player
    - `playerColor`: The color of the player.
    - `isLobbyAdmin`: A boolean indicating whether the player is the admin of the lobby.
    - `currentBoardPosition`: The current position of the player on the board. This is only relevant if the game has started.

Json Response example:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success",
  "lobby": {
    "lobbyId": 1,
    "adminUsername": "player1",
    "mapType": 1,
    "maxPlayers": 2,
    "gameId": -1,
    "players": [
      {
        "username": "player1",
        "playerColor": 1,
        "isLobbyAdmin": true,
        "currentBoardPosition": 0
      },
      {
        "username": "player2",
        "playerColor": 1,
        "isLobbyAdmin": false,
        "currentBoardPosition": 0
      }
    ]
  }
}
```

## POST `/lobby/update`
### Request
Update the lobby. The request is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby to update.
- `playerUsername`: The username of the admin of the lobby.
- `mapType`: The type of map that the game will start in.
- `maxPlayers`: The maximum number of players that can join the lobby.

Json Request Example:
```json
{
    "lobbyId": 1,
    "playerUsername": "player1",
    "mapType": 1,
    "maxPlayers": 2
}
```

### Response
This route does not return anything. It is used to update the lobby.
This will return only the success status and an error message if any.

Json Response example:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success"
}
```

## POST `/lobby/leave`
### Request
Leave a lobby. The request is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby to leave.
- `playerUsername`: The username of the player leaving the lobby.

Json Request Example:
```json
{
    "lobbyId": 1,
    "playerUsername": "player2"
}
```

### Response

This route does not return anything. It is used to update the lobby.
This will return only the success status and an error message if any.

Json Response example:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success"
}
```

## POST `/lobby/start-game`
### Request
Start the game
This route accepts a JSON object with the following fields:
- `lobbyId`: The ID of the lobby to start the game in.
- `playerUsername`: The username of the admin of the lobby.

Example JSON request:
```json
{
    "lobbyId": 1,
    "playerUsername": "player1"
}
```
### Response
This route does not return anything. It is used to update the lobby.
This will return only the success status and an error message if any.
Example JSON response:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success"
}
```
## POST `/game/leave`
### Request
This route removes a player from the game. The request is a JSON object with the following fields:
- `gameId`: The ID of the game to leave.
- `playerUsername`: The username of the player leaving the game.
Example JSON request:
```json
{
    "gameId": 1,
    "playerUsername": "player2"
}
```
### Response
This route does not return anything. It is used to update the game.
This will return only the success status and an error message if any.
Example JSON response:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success"
}
```
## POST `/game/stats`
### Request
This route is called at the end of the game to save the stats of the game. The request is a JSON object with the following fields:
- `gameId`: The ID of the game to save the stats of.

Example JSON request:
```json
{
    "gameId": 1
}
```
### Response
This route returns the stats of the game.
The response is a JSON object with the following fields:
- `gameData`: details about the game that contain some fields:
  - `gameDurationInSeconds`: how long was the game running in seconds
  - `players`: a list of players with all their data
    - `username`: the username of the player
    - `playerColor`: the color of the player
    - `isLobbyAdmin`: a boolean indicating whether the player was the admin of the lobby
    - `currentBoardPosition`: the current position of the player on the board

Example JSON response:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success",
  "gameData": {
    "gameDurationInSeconds": 100,
    "players": [
      {
        "username": "player1",
        "playerColor": 1,
        "isLobbyAdmin": true,
        "currentBoardPosition": 0
      },
      {
        "username": "player2",
        "playerColor": 1,
        "isLobbyAdmin": false,
        "currentBoardPosition": 0
      }
    ]
  }
}
```
## POST `/game/status`
### Request
This route is called to get the status of the game. The request is a JSON object with the following fields:
- `gameId`: The ID of the game to get the status of.

Example JSON request:
```json
{
    "gameId": 1
}
```
### Response
This route returns the status of the game.
The response is a JSON object with the following fields:
- `game`: details about the game
  - `gameId`: the ID of the game
  - `playerTurnIndex`: the index of the player whose turn it is
  - `players`: a list of players with all their data
    - `username`: the username of the player
    - `playerColor`: the color of the player
    - `isLobbyAdmin`: a boolean indicating whether the player was the admin of the lobby
    - `currentBoardPosition`: the current position of the player on the board
  - `turnTime`: details about the time of the turn
    - `current`: the current time of the turn
    - `max`: the maximum time of the turn
  - `diceRolling`: a boolean indicating whether the dice is rolling
  - `latestDiceValue`: the latest value of the dice
  - `shouldFinishGame`: a boolean indicating whether the game should finish

Example JSON response:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success",
  "game": {
    "gameId": 1,
    "playerTurnIndex": 0,
    "players": [
      {
        "username": "player1",
        "playerColor": 1,
        "isLobbyAdmin": true,
        "currentBoardPosition": 0
      },
      {
        "username": "player2",
        "playerColor": 1,
        "isLobbyAdmin": false,
        "currentBoardPosition": 0
      }
    ],
    "turnTime": {
      "current": 10,
      "max": 20
    },
    "diceRolling": false,
    "latestDiceValue": 6,
    "shouldFinishGame": false
  }
}
```

## POST `/game/roll-dice`
### Request
This route is called to roll the dice. The request is a JSON object with the following fields:
- `gameId`: The ID of the game to roll the dice in.
- `playerUsername`: The username of the player rolling the dice.

Example JSON request:
```json
{
    "gameId": 1,
    "playerUsername": "player1"
}
```

### Response
This route the base response
This will return only the success status and an error message if any.

Example JSON response:
```json
{
  "success": true,
  "message": "Error message if any. Empty if success"
}
```