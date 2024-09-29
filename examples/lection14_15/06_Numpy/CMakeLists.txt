cmake_minimum_required(VERSION 3.4)
project(shapes_numpy)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        v2.9.2  # Укажите нужную версию
)

FetchContent_MakeAvailable(pybind11)

# Проверка наличия numpy
find_package(Python REQUIRED COMPONENTS Interpreter Development)
# pybind11_find_package(NumPy)

# if (NOT NUMPY_FOUND)
#     message(FATAL_ERROR "NumPy is required but was not found.")
# endif()

pybind11_add_module(shapes_numpy pybind_shape.cpp circle.h shape.h)