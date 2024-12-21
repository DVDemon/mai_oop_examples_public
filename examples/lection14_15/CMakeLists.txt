cmake_minimum_required(VERSION 3.10)
project(lection14_15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_Counter 01_Counter/main.cpp)
add_executable(02_SpinLock 02_SpinLock/main.cpp)
add_executable(03_LockFreeStack 03_LockFreeStack/main.cpp)
add_subdirectory(04_Pythonlib)
add_subdirectory(05_Numpy)
add_executable(06_Braces 06_Braces/main.cpp)
add_executable(07_Initializer_list 07_Initializer_list/main.cpp)
add_executable(08_Function_chain 08_Function_chain/main.cpp)
add_executable(09_Cartesian_product 09_Cartesian_product/main.cpp)
add_executable(10_Structured_bindings 10_Structured_bindings/main.cpp)
add_executable(11_Compress 11_Compress/main.cpp)
add_executable(12_Chains 12_Chains/main.cpp)
add_executable(15_Overloaded 15_Overloaded/main.cpp)
add_executable(16_Variant 16_Variant/main.cpp)
add_subdirectory(20_Server)
add_subdirectory(21_DLib)


