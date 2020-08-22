cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
include(CTest)
enable_testing()

add_executable(matrix_tester tester.cpp)
include_directories(ErrorCode.h ErrorCode.hpp Matrix.h Matrix.hpp)
link_directories(${CMAKE_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
