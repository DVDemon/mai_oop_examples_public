cmake_minimum_required(VERSION 3.14)
project(kmeans_example)

# Устанавливаем стандарт C++11
set(CMAKE_CXX_STANDARD 11)

# Загружаем OpenBLAS
FetchContent_Declare(
    openblas
    GIT_REPOSITORY https://github.com/xianyi/OpenBLAS.git
    GIT_TAG        v0.3.23  # Укажите нужную версию OpenBLAS
)

FetchContent_MakeAvailable(openblas)

# Используем FetchContent для загрузки Dlib
include(FetchContent)

FetchContent_Declare(
    dlib
    GIT_REPOSITORY https://github.com/davisking/dlib.git
    GIT_TAG        v19.24  # Укажите нужную версию Dlib
)

FetchContent_MakeAvailable(dlib)

# Добавляем исполняемый файл
add_executable(kmeans_example main.cpp)

# Линкуем с библиотекой Dlib
target_link_libraries(kmeans_example PRIVATE dlib::dlib)