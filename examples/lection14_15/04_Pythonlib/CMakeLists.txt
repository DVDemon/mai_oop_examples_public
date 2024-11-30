cmake_minimum_required(VERSION 3.4)
project(shapes)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        v2.9.2  # Укажите нужную версию
)

FetchContent_MakeAvailable(pybind11)

pybind11_add_module(shapes pybind_shape.cpp circle.h shape.h)