cmake_minimum_required(VERSION 3.0.0)
project(algoritmos_rasterizacao VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(algoritmos_rasterizacao src/main.cpp src/utils/utils.cpp src/utils/utils.h src/bresenham_line/bresenham_line.cpp src/bresenham_line/bresenham_line.h src/bresenham_circle/bresenham_circle.cpp src/bresenham_circle/bresenham_circle.h src/polar_coordinate_circle/polar_coordinate_circle.cpp src/polar_coordinate_circle/polar_coordinate_circle.h src/constants.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
