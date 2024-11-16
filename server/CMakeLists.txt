cmake_minimum_required(VERSION 3.10)

# Project Name
project(server)

# Set the C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the compiler flags
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

# FetchContent module to download dependencies
include(FetchContent)

# Fetch ASIO
FetchContent_Declare(
        ASIO
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-18-1  # Or use a stable version like asio-1-18-1
)
message(STATUS "Downloading ASIO ...")
FetchContent_MakeAvailable(ASIO)

# Set ASIO include directory
set(ASIO_INCLUDE_DIR ${asio_SOURCE_DIR}/asio/include)

# Fetch CrowCpp
FetchContent_Declare(
        CrowCpp
        GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
        GIT_TAG master  # Or use a stable release tag
)
message(STATUS "Downloading CrowCpp ...")
FetchContent_MakeAvailable(CrowCpp)

# Define your executable
add_executable(server main.cpp
        Infrastructure/BaseResponse.cpp
        Infrastructure/BaseResponse.h
        Infrastructure/Lobby/CreateLobby/CreateLobbyRequest.cpp
        Infrastructure/Lobby/CreateLobby/CreateLobbyRequest.h
        GameManagement/Objects/MapTypeEnum.h
        GameManagement/Objects/Player.cpp
        GameManagement/Objects/Player.h
        GameManagement/Objects/PlayerColor.h
        Infrastructure/Lobby/CreateLobby/CreateLobbyResponse.cpp
        Infrastructure/Lobby/CreateLobby/CreateLobbyResponse.h
        Infrastructure/BaseContext.h
        Infrastructure/Lobby/CreateLobby/CreateLobbyContext.cpp
        Infrastructure/Lobby/CreateLobby/CreateLobbyContext.h
        GameManagement/Game/GameManager.cpp
        GameManagement/Game/GameManager.h
        GameManagement/Objects/Lobby.cpp
        GameManagement/Objects/Lobby.h
        GameManagement/Objects/RunningGame.cpp
        GameManagement/Objects/RunningGame.h
        GameManagement/Lobby/LobbyManager.cpp
        GameManagement/Lobby/LobbyManager.h
        Routes/CreateLobbyRoute.h
        Routes/JoinLobbyRoute.h
        Infrastructure/Lobby/JoinLobby/JoinLobbyRequest.cpp
        Infrastructure/Lobby/JoinLobby/JoinLobbyRequest.h
        Infrastructure/Lobby/JoinLobby/JoinLobbyResponse.cpp
        Infrastructure/Lobby/JoinLobby/JoinLobbyResponse.h
        Infrastructure/Lobby/JoinLobby/JoinLobbyContext.cpp
        Infrastructure/Lobby/JoinLobby/JoinLobbyContext.h
        Infrastructure/ValidationResponse.cpp
        Infrastructure/ValidationResponse.h
        Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsRequest.cpp
        Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsRequest.h
        Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsResponse.cpp
        Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsResponse.h
        Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsContext.cpp
        Infrastructure/Lobby/UpdateLobbySettings/UpdateSettingsContext.h
        Routes/ChangeLobbySettingsRoute.h
        API.h
        Infrastructure/Lobby/LobbyStatus/LobbyStatusRequest.cpp
        Infrastructure/Lobby/LobbyStatus/LobbyStatusRequest.h
        Infrastructure/Lobby/LobbyStatus/LobbyStatusResponse.cpp
        Infrastructure/Lobby/LobbyStatus/LobbyStatusResponse.h
        Infrastructure/Lobby/LobbyStatus/LobbyStatusContext.cpp
        Infrastructure/Lobby/LobbyStatus/LobbyStatusContext.h
        Routes/StatusLobbyRoute.h
)

# Link CrowCpp to your project
target_link_libraries(server PRIVATE Crow::Crow)

message("src: ${asio_SOURCE_DIR}")
message("install: ${ASIO_INSTALL_DIR}")
message("include: ${ASIO_INCLUDE_DIR}")

# Optionally enable SSL support for HTTPS
# Uncomment the following line if SSL is required:
# target_compile_definitions(MyProject PRIVATE -DUSE_SSL)

message(STATUS "Configuration complete.")
