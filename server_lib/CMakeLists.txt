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

add_library(server_lib STATIC
        Infrastructure/BaseResponse.cpp
        Infrastructure/BaseResponse.h
        GameManagement/Objects/MapTypeEnum.h
        GameManagement/Objects/Player.cpp
        GameManagement/Objects/Player.h
        GameManagement/Objects/PlayerColor.h
        Infrastructure/BaseContext.h
        GameManagement/Game/GameManager.cpp
        GameManagement/Game/GameManager.h
        GameManagement/Objects/Lobby.cpp
        GameManagement/Objects/Lobby.h
        GameManagement/Objects/RunningGame.cpp
        GameManagement/Objects/RunningGame.h
        GameManagement/Lobby/LobbyManager.cpp
        GameManagement/Lobby/LobbyManager.h
        Infrastructure/ValidationResponse.cpp
        Infrastructure/ValidationResponse.h
        GameManagement/Objects/BaseObject.cpp
        GameManagement/Objects/BaseObject.h
        Infrastructure/Commands/HttpCommand.h
        Infrastructure/Commands/HttpCommand.cpp
        Infrastructure/Request.h
        Infrastructure/Request.cpp
        Infrastructure/JsonSerializer.h
        Infrastructure/JsonSerializer.cpp
        Infrastructure/Commands/CreateLobbyCommand.h
        Infrastructure/Commands/CreateLobbyCommand.cpp
        Infrastructure/UniversalResponse.h
        Infrastructure/UniversalResponse.cpp
        Infrastructure/Commands/ChangeLobbySettingsCommand.h
        Infrastructure/Commands/ChangeLobbySettingsCommand.cpp
        Infrastructure/Commands/GameStatisticsCommand.h
        Infrastructure/Commands/GameStatisticsCommand.cpp
        Infrastructure/Commands/GameStatusCommand.h
        Infrastructure/Commands/GameStatusCommand.cpp
        Infrastructure/Commands/JoinLobbyCommand.h
        Infrastructure/Commands/JoinLobbyCommand.cpp
        Infrastructure/Commands/LeaveGameCommand.h
        Infrastructure/Commands/LeaveGameCommand.cpp
        Infrastructure/Commands/RollDiceCommand.h
        Infrastructure/Commands/RollDiceCommand.cpp
        Infrastructure/Commands/StartGameCommand.h
        Infrastructure/Commands/StartGameCommand.cpp
        Infrastructure/Commands/StatusLobbyCommand.h
        Infrastructure/Commands/StatusLobbyCommand.cpp
        Infrastructure/Commands/LeaveLobbyCommand.h
        Infrastructure/Commands/LeaveLobbyCommand.cpp
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
