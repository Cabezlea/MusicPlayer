# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/untitled_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/untitled_autogen.dir/ParseCache.txt"
  "portaudio/CMakeFiles/portaudio_autogen.dir/AutogenUsed.txt"
  "portaudio/CMakeFiles/portaudio_autogen.dir/ParseCache.txt"
  "portaudio/CMakeFiles/portaudio_static_autogen.dir/AutogenUsed.txt"
  "portaudio/CMakeFiles/portaudio_static_autogen.dir/ParseCache.txt"
  "portaudio/portaudio_autogen"
  "portaudio/portaudio_static_autogen"
  "untitled_autogen"
  )
endif()
