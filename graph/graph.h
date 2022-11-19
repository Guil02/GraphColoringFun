//
// Created by Dennis Bams on 16/11/2022.
//

#ifndef GRAPHCOLORING_GRAPH_H
#define GRAPHCOLORING_GRAPH_H

#include <vector>
#include "node.h"
#include "edge.h"

class graph {
public:
    std::vector<node> nodes;
    std::vector<edge> edges;
    int counter;

    graph();

    explicit graph(int nodes);

    void addNode();

    void addNodes(int nodes);

    void removeNode(int id);

    void removeNode(node n);

    void addEdge(int u, int v);

    void removeEdge(int u, int v);

    void removeEdge(edge e);

    bool containsNode(int id);

    bool containsNode(node n);

    node getNode(int id);

    bool hasEdge(int u, int v);

    bool hasEdge(edge e);

    std::vector<int> getColoring();

    void print();

    void adjacencyListPrint();
};


#endif //GRAPHCOLORING_GRAPH_H
