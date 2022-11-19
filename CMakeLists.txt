cmake_minimum_required(VERSION 3.23)
project(GraphColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphColoring main.cpp graph/graph.cpp graph/graph.h graph/node.cpp graph/node.h graph/edge.cpp graph/edge.h algorithms/greedy.cpp algorithms/greedy.h graph/randomGraph.cpp graph/randomGraph.h algorithms/bronKerbosch.cpp algorithms/bronKerbosch.h graphReader.cpp graphReader.h)
