cmake_minimum_required(VERSION 3.10)
project(ServerTests)

set(CMAKE_CXX_STANDARD 17)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_SHARED_LIBS OFF)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        GIT_PROGRESS TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)




add_executable(ServerTests main.cpp
        GameManagementTests/LobbyManagerTests/MockLobbyManager.h
        GameManagementTests/GameManagerTests/MockGameManager.h
        GameManagementTests/ObjectTests/LobbyTests.h
        GameManagementTests/ObjectTests/PlayerTests.h
        GameManagementTests/ObjectTests/RunningGameTests.h
        InfrastructureTests/LobbyTests/CreatLobbyTests/CreateLobbyRequestTest.h
        InfrastructureTests/LobbyTests/CreatLobbyTests/CreateLobbyResponseTests.h
        InfrastructureTests/LobbyTests/CreatLobbyTests/CreateLobbyContextTest.h
        InfrastructureTests/LobbyTests/JoinLobbyTests/JoinLobbyRequestTest.h
        InfrastructureTests/LobbyTests/JoinLobbyTests/JoinLobbyResponseTest.h
        InfrastructureTests/LobbyTests/JoinLobbyTests/JoinLobbyContextTest.h
        InfrastructureTests/LobbyTests/LeaveLobbyTests/LeaveLobbyContextTest.h
        InfrastructureTests/LobbyTests/LeaveLobbyTests/LeaveLobbyRequestTest.h
        InfrastructureTests/LobbyTests/LeaveLobbyTests/LeaveLobbyResponseTest.h
        InfrastructureTests/LobbyTests/LobbyStatusTests/LobbyStatusRequestTest.h
        InfrastructureTests/LobbyTests/LobbyStatusTests/LobbyStatusResponseTest.h
        InfrastructureTests/LobbyTests/LobbyStatusTests/LobbyStatusContextTest.h)

target_include_directories(ServerTests PRIVATE ${CMAKE_SOURCE_DIR}/server_lib)

add_dependencies(ServerTests server_lib)

target_link_libraries(ServerTests GTest::gmock  GTest::gtest GTest::gmock_main GTest::gtest_main Crow::Crow server_lib)

enable_testing()
