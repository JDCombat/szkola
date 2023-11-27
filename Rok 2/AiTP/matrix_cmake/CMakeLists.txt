cmake_minimum_required(VERSION 3.27)
project(matrix_cmake)

set(CMAKE_CXX_STANDARD 23)
set(PROJECT_HEADERS headers/matrix.h headers/function.h)
set(PROJECT_SOURCES main.cpp sources/matrix.cpp sources/function.cpp)
add_executable(matrix_cmake ${PROJECT_SOURCES} ${PROJECT_HEADERS})
