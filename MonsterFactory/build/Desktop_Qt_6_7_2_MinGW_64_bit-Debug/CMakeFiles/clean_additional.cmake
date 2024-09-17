# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MonsterFactory_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MonsterFactory_autogen.dir\\ParseCache.txt"
  "MonsterFactory_autogen"
  )
endif()
