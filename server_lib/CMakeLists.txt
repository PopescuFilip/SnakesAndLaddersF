cmake_minimum_required(VERSION 3.10)

project(server_lib)

# Keep C++ 17 or the crow and asio libraries will not compile
# Latest crow cpp version requires C++ 17
# Keep the asio version to 1.18.1 or the crow library will not compile.
# Crow is not compatible with the latest asio version

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
        ASIO
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-18-1
        GIT_PROGRESS TRUE
)
message(STATUS "Downloading ASIO ...")
FetchContent_MakeAvailable(ASIO)

set(ASIO_INCLUDE_DIR ${asio_SOURCE_DIR}/asio/include)

FetchContent_Declare(
        CrowCpp
        GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
        GIT_TAG master
        GIT_PROGRESS TRUE
)
message(STATUS "Downloading CrowCpp ...")
FetchContent_MakeAvailable(CrowCpp)



add_library(server_lib STATIC ../server/main.cpp
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
        Infrastructure/Lobby/LobbyStatus/LobbyStatusRequest.cpp
        Infrastructure/Lobby/LobbyStatus/LobbyStatusRequest.h
        Infrastructure/Lobby/LobbyStatus/LobbyStatusResponse.cpp
        Infrastructure/Lobby/LobbyStatus/LobbyStatusResponse.h
        Infrastructure/Lobby/LobbyStatus/LobbyStatusContext.cpp
        Infrastructure/Lobby/LobbyStatus/LobbyStatusContext.h
        Infrastructure/Lobby/LeaveLobby/LeaveLobbyRequest.cpp
        Infrastructure/Lobby/LeaveLobby/LeaveLobbyRequest.h
        Infrastructure/Lobby/LeaveLobby/LeaveLobbyResponse.cpp
        Infrastructure/Lobby/LeaveLobby/LeaveLobbyResponse.h
        Infrastructure/Lobby/LeaveLobby/LeaveLobbyContext.cpp
        Infrastructure/Lobby/LeaveLobby/LeaveLobbyContext.h
)

target_include_directories(server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link CrowCpp to your project
target_link_libraries(server_lib PRIVATE Crow::Crow)

message("src: ${asio_SOURCE_DIR}")
message("install: ${ASIO_INSTALL_DIR}")
message("include: ${ASIO_INCLUDE_DIR}")

# Optionally enable SSL support for HTTPS
# Uncomment the following line if SSL is required:
# target_compile_definitions(MyProject PRIVATE -DUSE_SSL)

message(STATUS "Configuration complete.")
