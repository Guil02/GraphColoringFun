//
// Created by Dennis Bams on 16/11/2022.
//

#include "Graph.h"

void Graph::addEdge(int u, int v) {
    if (u >= amount || v >= amount) {
        throw std::invalid_argument("received out of bound arguments");
    }
    adjacent[u].emplace_back(v);
    adjacent[v].emplace_back(u);
}

Graph::Graph(int amount) {
    this->amount = amount;
    initializeAdjacencyList();
}

void Graph::initializeAdjacencyList() {
    for (int i = 0; i < amount; ++i) {
        adjacent.emplace_back(std::vector<int>());
    }
}

bool Graph::hasEdge(int u, int v) {
    if (std::count(adjacent[u].begin(), adjacent[u].end(), v)) {
        return true;
    } else {
        return false;
    }
}

std::vector<std::vector<int>> Graph::getAdjacent() const {
    return adjacent;
}
