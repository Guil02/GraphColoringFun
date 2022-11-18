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

    void removeNode(int id);

    void removeNode(Node n);

    void addEdge(int u, int v);

    void removeEdge(int u, int v);

    void removeEdge(Edge e);

    bool containsNode(int id);

    bool containsNode(Node n);

    Node getNode(int id);

    bool hasEdge(int u, int v);

    bool hasEdge(Edge e);
};


#endif //GRAPHCOLORING_GRAPH_H
