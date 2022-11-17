//
// Created by Dennis Bams on 16/11/2022.
//

#ifndef GRAPHCOLORING_GRAPH_H
#define GRAPHCOLORING_GRAPH_H

#include <vector>
#include "Node.h"
#include "Edge.h"

class Graph {
public:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    int counter;

    Graph();

    explicit Graph(int nodes);

    void addNode();

    void addEdge(int u, int v);

    bool containsNode(int id);
    bool containsNode(Node n);
};


#endif //GRAPHCOLORING_GRAPH_H
