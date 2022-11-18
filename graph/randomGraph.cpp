//
// Created by Dennis Bams on 18/11/2022.
//

#include "randomGraph.h"
#include "random"

graph randomGraph::generate(int nodes, double edgeProbability) {
    // create the graph object
    graph g = graph(nodes);

    //setup random number generator
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // loop over all the nodes to assign an edge with a certain probability.
    for (int i = 0; i < nodes; ++i) {
        for (int j = i + 1; j < nodes; ++j) {
            if (double random = dist(mt) <= edgeProbability) {
                g.addEdge(i, j);
            }
        }
    }
    return g;
}
