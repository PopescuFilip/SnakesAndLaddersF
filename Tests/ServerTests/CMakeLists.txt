cmake_minimum_required(VERSION 3.10)
project(ServerTests)

set(CMAKE_CXX_STANDARD 17)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_SHARED_LIBS OFF)

# This option works only for Windows systems
# This is not tested on Windows arm systems
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif(WIN32)

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
        GameManagementTests/LobbyManagerTests/LobbyManagerTests.h
        GameManagementTests/GameManagerTests/MockGameManager.h
        GameManagementTests/ObjectTests/LobbyTests.h
        GameManagementTests/ObjectTests/PlayerTests.h
        GameManagementTests/ObjectTests/RunningGameTests.h
        GameManagementTests/GameManagementTests.h
        InfrastructureTests/InfrastructureTests.h
        InfrastructureTests/CommandTests/CommandTests.h
)

target_include_directories(ServerTests PRIVATE ${CMAKE_SOURCE_DIR}/server_lib)

add_dependencies(ServerTests server_lib)

target_link_libraries(ServerTests GTest::gmock  GTest::gtest GTest::gmock_main GTest::gtest_main Crow::Crow server_lib)

enable_testing()
