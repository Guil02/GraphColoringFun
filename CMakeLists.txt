cmake_minimum_required(VERSION 3.23)
project(GraphColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphColoring main.cpp graph/Graph.cpp graph/Graph.h graph/Node.cpp graph/Node.h graph/Edge.cpp graph/Edge.h algorithms/Greedy.cpp algorithms/Greedy.h)
