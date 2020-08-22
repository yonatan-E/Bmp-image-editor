cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

include(CTest)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/build)
link_directories(${CMAKE_SOURCE_DIR}/build)
add_executable(tester tester.cpp Matrix.cpp ErrorCode.cpp)
target_link_libraries(tester matrix)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
