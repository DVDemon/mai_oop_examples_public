cmake_minimum_required(VERSION 3.10)

project(lab_06)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab_06 main.cpp npc.cpp knight.cpp dragon.cpp black_knight.cpp)