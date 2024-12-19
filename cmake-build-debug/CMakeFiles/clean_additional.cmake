# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "ApproxImageAlgoAdaptatif_autogen"
  "CMakeFiles/ApproxImageAlgoAdaptatif_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ApproxImageAlgoAdaptatif_autogen.dir/ParseCache.txt"
  )
endif()
