cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/user/Qt/6.7.0/macos/lib")

# Include QT6
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

# Add the portAudio subdirectory
add_subdirectory(portaudio)

# Include the portaudio header directory
include_directories(/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/portaudio/include)

add_executable(untitled main.cpp
        MainWindow.cpp
        MainWindow.h
        PlayerControls.cpp
        PlayerControls.h
        PlaylistManager.cpp
        PlaylistManager.h
        AudioPlayer.cpp
        AudioPlayer.h
)
target_link_libraries(untitled
        Qt::Core
        Qt::Gui
        Qt::Widgets
        portaudio
)
