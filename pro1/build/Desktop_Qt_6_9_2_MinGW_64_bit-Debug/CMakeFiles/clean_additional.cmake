# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\pro1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\pro1_autogen.dir\\ParseCache.txt"
  "pro1_autogen"
  )
endif()
