cmake_minimum_required(VERSION 3.29)
project(frontend)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(APPLE)
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/macos/lib/cmake/Qt6") # Replace with your actual path
elseif(WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\windows\\lib\\cmake\\Qt6")
else()
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/linux/cmake/Qt6")
endif ()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(frontend main.cpp)
target_link_libraries(frontend
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

