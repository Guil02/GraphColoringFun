//
// Created by Dennis Bams on 18/11/2022.
//

#include "RandomGraph.h"
#include "random"

Graph RandomGraph::randomGraph(int nodes, int edgeProbability) {
    Graph g = Graph(nodes);
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
