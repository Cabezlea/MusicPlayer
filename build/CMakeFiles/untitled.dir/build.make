# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o: untitled_autogen/mocs_compilation.cpp
CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o -MF CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o -c /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/untitled_autogen/mocs_compilation.cpp

CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/untitled_autogen/mocs_compilation.cpp > CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.i

CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/untitled_autogen/mocs_compilation.cpp -o CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.s

CMakeFiles/untitled.dir/main.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.cpp.o: /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/main.cpp
CMakeFiles/untitled.dir/main.cpp.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled.dir/main.cpp.o -MF CMakeFiles/untitled.dir/main.cpp.o.d -o CMakeFiles/untitled.dir/main.cpp.o -c /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/main.cpp

CMakeFiles/untitled.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/main.cpp > CMakeFiles/untitled.dir/main.cpp.i

CMakeFiles/untitled.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/main.cpp -o CMakeFiles/untitled.dir/main.cpp.s

CMakeFiles/untitled.dir/MainWindow.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/MainWindow.cpp.o: /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/MainWindow.cpp
CMakeFiles/untitled.dir/MainWindow.cpp.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled.dir/MainWindow.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled.dir/MainWindow.cpp.o -MF CMakeFiles/untitled.dir/MainWindow.cpp.o.d -o CMakeFiles/untitled.dir/MainWindow.cpp.o -c /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/MainWindow.cpp

CMakeFiles/untitled.dir/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled.dir/MainWindow.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/MainWindow.cpp > CMakeFiles/untitled.dir/MainWindow.cpp.i

CMakeFiles/untitled.dir/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/MainWindow.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/MainWindow.cpp -o CMakeFiles/untitled.dir/MainWindow.cpp.s

CMakeFiles/untitled.dir/PlayerControls.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/PlayerControls.cpp.o: /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlayerControls.cpp
CMakeFiles/untitled.dir/PlayerControls.cpp.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled.dir/PlayerControls.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled.dir/PlayerControls.cpp.o -MF CMakeFiles/untitled.dir/PlayerControls.cpp.o.d -o CMakeFiles/untitled.dir/PlayerControls.cpp.o -c /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlayerControls.cpp

CMakeFiles/untitled.dir/PlayerControls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled.dir/PlayerControls.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlayerControls.cpp > CMakeFiles/untitled.dir/PlayerControls.cpp.i

CMakeFiles/untitled.dir/PlayerControls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/PlayerControls.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlayerControls.cpp -o CMakeFiles/untitled.dir/PlayerControls.cpp.s

CMakeFiles/untitled.dir/PlaylistManager.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/PlaylistManager.cpp.o: /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlaylistManager.cpp
CMakeFiles/untitled.dir/PlaylistManager.cpp.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled.dir/PlaylistManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled.dir/PlaylistManager.cpp.o -MF CMakeFiles/untitled.dir/PlaylistManager.cpp.o.d -o CMakeFiles/untitled.dir/PlaylistManager.cpp.o -c /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlaylistManager.cpp

CMakeFiles/untitled.dir/PlaylistManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled.dir/PlaylistManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlaylistManager.cpp > CMakeFiles/untitled.dir/PlaylistManager.cpp.i

CMakeFiles/untitled.dir/PlaylistManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/PlaylistManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/PlaylistManager.cpp -o CMakeFiles/untitled.dir/PlaylistManager.cpp.s

CMakeFiles/untitled.dir/AudioPlayer.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/AudioPlayer.cpp.o: /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/AudioPlayer.cpp
CMakeFiles/untitled.dir/AudioPlayer.cpp.o: CMakeFiles/untitled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/untitled.dir/AudioPlayer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled.dir/AudioPlayer.cpp.o -MF CMakeFiles/untitled.dir/AudioPlayer.cpp.o.d -o CMakeFiles/untitled.dir/AudioPlayer.cpp.o -c /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/AudioPlayer.cpp

CMakeFiles/untitled.dir/AudioPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled.dir/AudioPlayer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/AudioPlayer.cpp > CMakeFiles/untitled.dir/AudioPlayer.cpp.i

CMakeFiles/untitled.dir/AudioPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/AudioPlayer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/AudioPlayer.cpp -o CMakeFiles/untitled.dir/AudioPlayer.cpp.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/untitled.dir/main.cpp.o" \
"CMakeFiles/untitled.dir/MainWindow.cpp.o" \
"CMakeFiles/untitled.dir/PlayerControls.cpp.o" \
"CMakeFiles/untitled.dir/PlaylistManager.cpp.o" \
"CMakeFiles/untitled.dir/AudioPlayer.cpp.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/untitled_autogen/mocs_compilation.cpp.o
untitled: CMakeFiles/untitled.dir/main.cpp.o
untitled: CMakeFiles/untitled.dir/MainWindow.cpp.o
untitled: CMakeFiles/untitled.dir/PlayerControls.cpp.o
untitled: CMakeFiles/untitled.dir/PlaylistManager.cpp.o
untitled: CMakeFiles/untitled.dir/AudioPlayer.cpp.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: /Users/user/Qt/6.7.0/macOS/lib/QtWidgets.framework/Versions/A/QtWidgets
untitled: portaudio/libportaudio.dylib
untitled: /Users/user/Qt/6.7.0/macOS/lib/QtGui.framework/Versions/A/QtGui
untitled: /Users/user/Qt/6.7.0/macOS/lib/QtCore.framework/Versions/A/QtCore
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled
.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build /Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/build/CMakeFiles/untitled.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/untitled.dir/depend

