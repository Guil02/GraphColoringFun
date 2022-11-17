//
// Created by Dennis Bams on 16/11/2022.
//

#include "Graph.h"

Graph::Graph() = default;

Graph::Graph(int nodes) {
    for (int i = 0; i < nodes; ++i) {
        this->nodes.emplace_back(Node(i));
    }
    counter = nodes;
}

void Graph::addNode() {
    nodes.emplace_back(Node(counter++));
}

void Graph::addEdge(int u, int v) {

}

bool Graph::containsNode(int id) {
    return std::find_if(nodes.begin(), nodes.end(), [&id](const Node& a) { return id == a.id; }) != nodes.end();
}
