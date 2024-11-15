cmake_minimum_required(VERSION 3.29)
project(frontend)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(APPLE)
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/macos/lib/cmake/Qt6") # Replace with your actual path
elseif(WIN32)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM|aarch64")
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\msvc2022_arm64\\lib\\cmake\\Qt6")
        message("Found arm based CPU.")
    else ()
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\msvc2022\\lib\\cmake\\Qt6")
        message("Found amd64 based CPU")
    endif ()
else()
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/linux/cmake/Qt6")
endif ()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_executable(frontend main.cpp
    windows/mainwindow.h windows/mainwindow.cpp windows/mainwindow.ui
)

target_link_libraries(frontend
        Qt::Core
        Qt::Gui
        Qt::Widgets
        cpr::cpr
)

