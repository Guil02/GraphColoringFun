//
// Created by Dennis Bams on 18/11/2022.
//

#include "randomGraph.h"
#include "random"

graph randomGraph::generate(int nodes, int edgeProbability) {
    graph g = graph(nodes);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            if (i != j) {
                if (double random = dist(mt) <= edgeProbability) {
                    g.addEdge(i, j);
                }
            }
        }
    }
    return g;
}
