cmake_minimum_required(VERSION 3.16.3)

project(ONEGIN_lib)


set(ONEGIN_SOURCE src/ONEGIN_files.cpp src/ONEGIN_strings.cpp src/ONEGIN_structs.cpp)

add_library(ONEGIN_lib STATIC ${ONEGIN_SOURCE})

SET_TARGET_PROPERTIES(ONEGIN_lib PROPERTIES PREFIX "")

include_directories(OBEGIN_lib include/)


install(
    TARGETS ONEGIN_lib
    RUNTIME DESTINATION       "${PROJECT_SOURCE_DIR}/bin"
    LIBRARY DESTINATION       "${PROJECT_SOURCE_DIR}/libs"
    ARCHIVE DESTINATION       "${PROJECT_SOURCE_DIR}/libs"
    PUBLIC_HEADER DESTINATION "${PROJECT_SOURCE_DIR}/include"
)
