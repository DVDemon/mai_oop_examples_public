cmake_minimum_required(VERSION 3.10)

project(lection_12_13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads)

add_executable(01_ParameterFunction 01_ParameterFunction/main.cpp)
add_executable(02_Lambda 02_Lambda/main.cpp)
add_executable(03_LambdaReturn 03_LambdaReturn/main.cpp)
add_executable(04_LambdaCapture 04_LambdaCapture/main.cpp)
add_executable(05_LambdaGen 05_LambdaGen/main.cpp)
add_executable(06_LambdaVariadic 06_LambdaVariadic/main.cpp)
add_executable(07_LambdaExample 07_LambdaExample/main.cpp)
add_executable(08_Thread 08_Thread/main.cpp)
add_executable(09_ThreadParameter 09_ThreadParameter/main.cpp)
add_executable(10_ScopedThread 10_ScopedThread/main.cpp)
add_executable(11_RaceCondition 11_RaceCondition/main.cpp)
add_executable(12_Mutex 12_Mutex/main.cpp)
add_executable(13_MutexRecursive 13_MutexRecursive/main.cpp)
add_executable(14_LockGuard 14_LockGuard/main.cpp)
add_executable(15_Deadlock 15_Deadlock/main.cpp)
add_executable(16_SharedLock 16_SharedLock/main.cpp)
add_executable(17_DeadLock2 17_DeadLock2/main.cpp)
add_executable(18_Stack 18_Stack/main.cpp)
add_executable(19_PassOut 19_PassOut/main.cpp)
add_executable(20_Future 20_Future/main.cpp)
add_executable(21_Promise 21_Promise/main.cpp)
add_executable(22_Conditional 22_Conditional/main.cpp)
add_executable(23_CustomAsync 23_CustomAsync/main.cpp)
add_executable(24_CoAwait 24_CoAwait/main.cpp)
add_executable(25_CoYield 25_CoYield/main.cpp)
add_executable(26_Multivalue 26_Multivalue/main.cpp)


target_link_libraries(01_ParameterFunction PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(02_Lambda PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(03_LambdaReturn PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(04_LambdaCapture PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(05_LambdaGen PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(06_LambdaVariadic PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(07_LambdaExample PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(08_Thread PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(09_ThreadParameter PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(10_ScopedThread PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(11_RaceCondition PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(12_Mutex PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(13_MutexRecursive PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(14_LockGuard PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(15_Deadlock PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(16_SharedLock PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(17_DeadLock2 PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(18_Stack PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(19_PassOut PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(20_Future PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(21_Promise PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(22_Conditional PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(23_CustomAsync PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(24_CoAwait PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(25_CoYield PRIVATE  ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(26_Multivalue PRIVATE  ${CMAKE_THREAD_LIBS_INIT})

add_subdirectory(lab_07)