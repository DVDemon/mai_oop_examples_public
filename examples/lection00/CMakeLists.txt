cmake_minimum_required(VERSION 3.10)
project(oop_example_01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(01_FirstCppProgram 01_FirstCppProgram/main.cpp)
add_executable(02_StatementsAndFunctions 02_StatementsAndFunctions/main.cpp)
add_executable(03_DataInputAndOutput 03_DataInputAndOutput/main.cpp)
add_executable(04_OutputFormatting 04_OutputFormatting/main.cpp)
add_executable(05_VariableScope 05_VariableScope/main.cpp)

add_subdirectory(06_GTest)
