#include <iostream>
#include "graph/graph.h"
#include "algorithms/greedy.h"
#include "graph/randomGraph.h"


int main() {
    graph g = randomGraph::generate(100, 0.2);
    g.print();

    greedy::calculateColoring(g);
    std::vector<int> coloring = g.getColoring();
    int index = 0;
    for (int c: coloring) {
        std::cout << "index " << index++ << ": " << c << "\n";
    }
}
