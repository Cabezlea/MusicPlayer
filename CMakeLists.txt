cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/user/Qt/6.7.0/macos/lib")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled main.cpp
        cmake-build-debug/MainWindow.cpp
        cmake-build-debug/MainWindow.h
        cmake-build-debug/PlayerControls.cpp
        cmake-build-debug/PlayerControls.h
        cmake-build-debug/PlaylistManager.cpp
        cmake-build-debug/PlaylistManager.h
        cmake-build-debug/AudioPlayer.cpp
        cmake-build-debug/AudioPlayer.h
)
target_link_libraries(untitled
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

