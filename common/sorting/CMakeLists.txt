cmake_minimum_required(VERSION 3.5)
project(sorting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c Common.h InsertSort.c QuickSort.c Test.c SelectSort.c)
add_executable(sorting ${SOURCE_FILES})