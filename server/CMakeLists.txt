cmake_minimum_required(VERSION 3.10)

project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server main.cpp
        API.h
  )

add_custom_command(TARGET server POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/server/maps
        ${CMAKE_CURRENT_BINARY_DIR}/maps
)

target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/server_lib)

add_dependencies(server server_lib)

target_link_libraries(server PRIVATE server_lib Crow::Crow)