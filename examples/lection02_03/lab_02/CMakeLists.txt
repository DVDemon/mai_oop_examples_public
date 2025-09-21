# CMakeLists.txt для лабораторной работы 2
# Демонстрирует современную организацию проекта с разделением на библиотеку и исполняемый файл

cmake_minimum_required(VERSION 3.10)

# Настройка проекта
project(lab_02 
    VERSION 1.0.0
    DESCRIPTION "Лабораторная работа 2: Класс DashArray с Правилом пяти"
    LANGUAGES CXX
)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 11)  # Изменено с 20 на 11 для совместимости
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройка директорий
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Добавление директории с заголовочными файлами
include_directories(${INCLUDE_DIR})

# Поиск исходных файлов библиотеки
file(GLOB_RECURSE LIBRARY_SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

# Создание библиотеки
add_library(lab_02_lib ${LIBRARY_SOURCES})

# Создание исполняемого файла
add_executable(lab_02_exe main.cpp)

# Связывание библиотеки с исполняемым файлом
target_link_libraries(lab_02_exe PRIVATE lab_02_lib)

# Настройка компилятора (опционально)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(lab_02_lib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(lab_02_exe PRIVATE -Wall -Wextra -Wpedantic)
endif()
