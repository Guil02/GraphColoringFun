#include <iostream>
#include "graph/graph.h"
#include "algorithms/greedy.h"
#include "graph/randomGraph.h"
#include "algorithms/bronKerbosch.h"
#include "graphReader.h"


int main() {
//    graph g = randomGraph::generate(100, 0.2);
////    g.print();
//    g.adjacencyListPrint();
//
//    std::cout << "upper bound: " << greedy::maxColor(g) << "\n";
//    bronKerbosch b = bronKerbosch();
//    std::cout << "lower bound: " << b.calculateLowerBound(g) << "\n";
//    graphReader::readInGraph("/2020-2021_exampleGraphs/graph04_2020.txt");
    graphReader g = graphReader();
    g.readInGraph("/Users/dennisbams/CLionProjects/GraphColoring/2020-2021_exampleGraphs/graph04_2020.txt");
}
