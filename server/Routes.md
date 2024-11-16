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
  - `color`: The color of the player.
  - `isAdmin`: A boolean indicating whether the player is the admin of the lobby.

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
        "color": 1,
        "isAdmin": true
      },
      {
        "username": "player2",
        "color": 1,
        "isAdmin": false
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
  - `color`: The color of the player.
  - `isAdmin`: A boolean indicating whether the player is the admin of the lobby.

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
        "color": 1,
        "isAdmin": true
      },
      {
        "username": "player2",
        "color": 1,
        "isAdmin": false
      }
    ]
  }
}
```

## POST `/lobby/update`
### Request
Update the lobby. The request is a JSON object with the following fields:
- `lobbyId`: The ID of the lobby to update.
- `adminUsername`: The username of the admin of the lobby.
- `mapType`: The type of map that the game will start in.
- `maxPlayers`: The maximum number of players that can join the lobby.

Json Request Example:
```json
{
    "lobbyId": 1,
    "adminUsername": "player1",
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

