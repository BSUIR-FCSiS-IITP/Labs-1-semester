cmake_minimum_required(VERSION 3.23)
project(laba5)

set(CMAKE_CXX_STANDARD 14)

add_executable(task1 task1.cpp)
add_executable(task2 task2.cpp)
add_executable(task3 task3.cpp)
add_executable(task4 task4.cpp)
add_executable(task5 task5.cpp)


find_library(LIB_PATH
    NAMES lib
    PATH_SUFFIXES lib
    PATHS ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(task1 ${LIB_PATH})