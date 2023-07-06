cmake_minimum_required(VERSION 3.25)
project(practice_ford)

set(CMAKE_CXX_STANDARD 17)

add_executable(practice_ford main.cpp graph.h ford_algorithm.cpp)
