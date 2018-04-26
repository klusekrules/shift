project(MyHello CXX)
cmake_minimum_required(VERSION 2.8)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SHIFT_SOURCES "*.cpp")
file(GLOB_RECURSE SHIFT_HEADERS "*.h")

set (SHIFT_INCLUDE_DIRS "")
foreach (_headerFile ${SHIFT_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND SHIFT_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES SHIFT_INCLUDE_DIRS)

add_library(shift ${SHIFT_SOURCES})
target_include_directories(shift PRIVATE ${SHIFT_INCLUDE_DIRS})