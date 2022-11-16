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

    void addEdge(int u, int v);

    bool hasEdge(int u, int v);

    std::vector<std::vector<int>> getAdjacent() const;
    
    void initializeAdjacencyList();

};


#endif //GRAPHCOLORING_GRAPH_H
