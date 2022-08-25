cmake_minimum_required(VERSION 3.0.0)
project(algoritmos_rasterizacao VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(algoritmos_rasterizacao src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
