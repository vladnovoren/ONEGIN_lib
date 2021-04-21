cmake_minimum_required(VERSION 3.16.3)

set(ONEGIN_SOURCE src/ONEGIN_files.cpp src/ONEGIN_strings.cpp src/ONEGIN_structs.cpp)

add_library(ONEGIN_lib STATIC ${ONEGIN_SOURCE})

SET_TARGET_PROPERTIES(ONEGIN_lib
    PROPERTIES
    PREFIX ""
    )

include_directories(OBEGIN_lib include/)

