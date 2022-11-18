#include <iostream>
#include "graph/graph.h"
#include "algorithms/greedy.h"
#include "graph/randomGraph.h"


int main() {
    graph g = graph(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    node n = g.getNode(4);
    std::cout << n.id << "\n";

    greedy::calculateColoring(g);
    std::vector<int> coloring = g.getColoring();
    int index = 0;
    for (int c: coloring) {
        std::cout << "index " << index++ << ": " << c << "\n";
    }
}
