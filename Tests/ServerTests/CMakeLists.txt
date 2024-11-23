cmake_minimum_required(VERSION 3.10)
project(ServerTests)

set(CMAKE_CXX_STANDARD 17)
set(FETCHCONTENT_QUIET FALSE)

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




add_executable(ServerTests main.cpp)

target_include_directories(ServerTests PRIVATE ${CMAKE_SOURCE_DIR}/server_lib)

add_dependencies(ServerTests server_lib)

target_link_libraries(ServerTests GTest::gmock GTest::gmock_main GTest::gtest GTest::gtest_main)

enable_testing()
