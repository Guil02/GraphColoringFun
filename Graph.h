//
// Created by Dennis Bams on 16/11/2022.
//

#ifndef GRAPHCOLORING_GRAPH_H
#define GRAPHCOLORING_GRAPH_H

#include <vector>

class Graph {
public:
    explicit Graph(int amount);

    int amount;
    std::vector<std::vector<int>> adjacent;
    std::vector<int> colors;

    void addEdge(int u, int v);

    bool hasEdge(int u, int v);

    std::vector<std::vector<int>> getAdjacent() const;

    std::vector<int> getAdjacent(int u);

    void initializeAdjacencyList();

    void initializeColorVector();

    void setColor(int u, int color);
};


#endif //GRAPHCOLORING_GRAPH_H
