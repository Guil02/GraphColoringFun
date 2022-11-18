#include <iostream>
#include "graph/Graph.h"
#include "algorithms/Greedy.h"


int main() {
    Graph g = Graph(5);
    g.addEdge(1, 4);
    std::cout << g.hasEdge(4, 1);
    std::cout << g.hasEdge(1, 4);
    std::cout << g.hasEdge(1, 3);

    Node n = g.getNode(4);
    std::cout << n.id << "\n";

    Greedy::calculateColoring(g);
    std::vector<int> coloring = g.getColoring();
    int index = 0;
    for (int c: coloring) {
        std::cout << "index " << index++ << ": " << c << "\n";
    }
}
