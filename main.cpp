#include <iostream>
#include "graph/graph.h"
#include "algorithms/greedy.h"
#include "graph/randomGraph.h"
#include "algorithms/bronKerbosch.h"


int main() {
    graph g = randomGraph::generate(100, 0.2);
//    g.print();
    g.adjacencyListPrint();

    std::cout << "upper bound: " << greedy::maxColor(g) << "\n";
    bronKerbosch b = bronKerbosch();
    std::cout << "lower bound: " << b.calculateLowerBound(g) << "\n";
}
