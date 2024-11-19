cmake_minimum_required(VERSION 3.10)

project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server main.cpp
        API.h
        Routes/JoinLobbyRoute.h
        Routes/LeaveLobbyRoute.h
        Routes/ChangeLobbySettingsRoute.h
        Routes/CreateLobbyRoute.h
        Routes/StatusLobbyRoute.h
)

target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/server_lib)

add_dependencies(server server_lib)

target_link_libraries(server PRIVATE server_lib Crow::Crow)