cmake_minimum_required(VERSION 3.10)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab_02_lib ${SOURCES})
add_executable(lab_02_exe main.cpp)

target_link_libraries(lab_02_exe PRIVATE lab_02_lib)
