cmake_minimum_required(VERSION 3.10)
project(SnakesAndLadders)

# Add the main project
add_subdirectory(server)

# Add the tests project
add_subdirectory(Tests/ServerTests)