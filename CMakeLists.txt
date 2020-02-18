cmake_minimum_required(VERSION "3.7.1")

project("Main" VERSION "1.0.0")

SET(GCC_COVERAGE_COMPILE_FLAGS "-lGL -lGLU -lglut")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_library(linkedList.hpp linkedList.cpp)

add_executable("${PROJECT_NAME}" Main.cpp)
