#include <iostream>
#include "graph/graph.h"
#include "algorithms/greedy.h"
#include "graph/randomGraph.h"
#include "algorithms/bronKerbosch.h"
#include "graphReader.h"


int main() {
    graphReader greader = graphReader();
    graph g = greader.readInGraph("../2020-2021_exampleGraphs/graph04_2020.txt");
    g.adjacencyListPrint();

    std::cout << "upper bound: " << greedy::maxColor(g) << "\n";
    bronKerbosch b = bronKerbosch();
    std::cout << "lower bound: " << b.calculateLowerBound(g) << "\n";

}
