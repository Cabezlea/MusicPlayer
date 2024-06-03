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


# Add the include directory for libsndfile this is where we find the header
include_directories(/opt/homebrew/Cellar/libsndfile/1.2.2/include)

# Add the library directory for libsndfile where we find the library
link_directories(/opt/homebrew/Cellar/libsndfile/1.2.2/lib)

#Include the directory for mpg123 to decode mp3 files
include_directories(/opt/homebrew/Cellar/mpg123/1.32.6/include)
link_directories(/opt/homebrew/Cellar/mpg123/1.32.6/lib)


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
        sndfile
        mpg123
)
