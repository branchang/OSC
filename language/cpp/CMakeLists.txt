cmake_minimum_required(VERSION 2.6)
# project(hello)

SET(CMAKE_C_COMPILER "/usr/local/bin/gcc")


if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++11)
    message(STATUS "optional:-std=c++11")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(LIB_LIST PocoFoundation PocoUtil PocoData PocoJSON PocoNet pthread ssl crypto )
SET(SRC_LIST main.cpp generic_proc.cpp containers.cpp tpoco/TestPoco.cpp algo.cpp stack.cpp basic.cpp sequence.cpp
    interview.cpp utilities/BinaryTree.cpp design_patterns/w_bridge.cpp
    # book/test_co.cpp
    book/cpprimer.cpp book/primer_const.cpp)
# SET(SRC_LIST poco_test.cpp tpoco/TestPoco.cpp)
# SET(SRC_LIST tpoco/net.cpp tpoco/TestPoco.cpp)
# SET(SRC_LIST design_patterns/w_bridge.cpp)

INCLUDE_DIRECTORIES(../include/ ../design_patterns)
ADD_EXECUTABLE(hello ${SRC_LIST})
TARGET_LINK_LIBRARIES(hello ${LIB_LIST})

# add_executable(cpp main.cpp generic_proc.cpp containers.cpp tpoco/TestPoco.cpp algo.cpp)
# add_executable(cpp main.cpp generic_proc.cpp containers.cpp algo.cpp)
