cmake_minimum_required(VERSION 3.10)
project(SnakesAndLadders)

add_subdirectory(server_lib)

add_subdirectory(server)
add_subdirectory(frontend)
add_subdirectory(Tests/ServerTests)