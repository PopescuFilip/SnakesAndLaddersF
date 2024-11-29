cmake_minimum_required(VERSION 3.29)

project(frontend VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(APPLE)
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/macos/lib/cmake/Qt6")
elseif(WIN32)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM|aarch64")
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\msvc2022_arm64\\lib\\cmake\\Qt6")
        set(WIN_DEPLOY "C:\\Qt\\6.8.0\\msvc2022_arm4\\bin\\windeployqt.exe")
        message("Found arm-based CPU.")
    else()
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\msvc2022_64\\lib\\cmake\\Qt6")
        set(WIN_DEPLOY "C:\\Qt\\6.8.0\\msvc2022_64\\bin\\windeployqt.exe")
        message("Found amd64-based CPU.")
    endif()
else()
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/linux/cmake/Qt6")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

set(PROJECT_SOURCES
        main.cpp
        core/BaseResponse.h
        core/BaseResponse.cpp
        models/Player.h
        models/Player.cpp
        models/Lobby.h
        models/Lobby.cpp
        core/ApiEndpoints.h
        core/BaseService.h
        core/BaseService.cpp

        observers/Observer.h
        observers/Subject.h
        observers/Subject.cpp
        utils/ViewManager.h
        utils/ViewManager.cpp
        state/UserState.h
        state/UserState.cpp
        services/LobbyService.h
        services/LobbyService.cpp
        observers/ViewObserver.h
        observers/ViewObserver.cpp
        state/LobbyState.h
        state/LobbyState.cpp
        utils/Logger.h
        utils/Logger.cpp
        models/PlayerColor.h
        services/LobbyUpdater.h
        services/LobbyUpdater.cpp
        resources/FontManager.h
        models/Game.cpp
        models/Game.h
        models/TurnTime.h
        services/GameService.cpp
        services/GameService.h
        state/GameState.cpp
        state/GameState.h
        services/GameUpdater.cpp
        services/GameUpdater.h
        models/MapType.h
        models/DiceValue.h
        models/GameStats.cpp
        models/GameStats.h
)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(frontend
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            resources/Resources.qrc
            views/homeView/homeview.h views/homeView/homeview.cpp views/homeView/homeview.ui
            views/createGameView/creategameview.h views/createGameView/creategameview.cpp views/createGameView/creategameview.ui
            views/joinGameView/joingameview.h views/joinGameView/joingameview.cpp views/joinGameView/joingameview.ui
            views/lobbyView/lobbyview.h views/lobbyView/lobbyview.cpp views/lobbyView/lobbyview.ui
            widgets/InfoDialog/infodialog.h widgets/InfoDialog/infodialog.cpp widgets/InfoDialog/infodialog.ui
            widgets/PlayerInfoWidget/playerinfowidget.h widgets/PlayerInfoWidget/playerinfowidget.cpp widgets/PlayerInfoWidget/playerinfowidget.ui
            views/gameView/gameview.h views/gameView/gameview.cpp views/gameView/gameview.ui
            views/statsView/statsview.h views/statsView/statsview.cpp views/statsView/statsview.ui
            widgets/Map/map.h widgets/Map/map.cpp widgets/Map/map.ui
            widgets/GamePlayerInfoWidget/gameplayerinfowidget.h widgets/GamePlayerInfoWidget/gameplayerinfowidget.cpp widgets/GamePlayerInfoWidget/gameplayerinfowidget.ui
            widgets/StatsPlayerInfoWidget/statsplayerinfowidget.h widgets/StatsPlayerInfoWidget/statsplayerinfowidget.cpp widgets/StatsPlayerInfoWidget/statsplayerinfowidget.ui

    )
else()
    add_executable(frontend
            ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(frontend PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
        cpr::cpr
        nlohmann_json::nlohmann_json
)

if(APPLE OR WIN32)
    set_target_properties(frontend PROPERTIES
            MACOSX_BUNDLE TRUE
            WIN32_EXECUTABLE TRUE
    )
endif()

include(GNUInstallDirs)
install(TARGETS frontend
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(frontend)
endif()

if(WIN32)
    # Ensure we run windeployqt after building the executable
    add_custom_command(
        TARGET frontend POST_BUILD
        COMMAND ${WIN_DEPLOY} $<TARGET_FILE:frontend>
        COMMENT "Running windeployqt to deploy Qt dependencies"
    )
endif()
