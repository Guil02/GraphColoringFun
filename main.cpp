#include <iostream>
#include "Graph.h"


int main() {
    Graph g = Graph(5);
    g.addEdge(1, 4);
    std::cout << g.hasEdge(4, 1);
    std::cout << g.hasEdge(1, 4);
    std::cout << g.hasEdge(1, 3);

    std::vector<int> adj = g.getAdjacent(1);
    for (int i: adj) {
        std::cout << i << ' ';
    }
}
