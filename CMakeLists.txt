cmake_minimum_required(VERSION 3.23)
project(GraphColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphColoring main.cpp Node.cpp Node.h Edge.cpp Edge.h)
