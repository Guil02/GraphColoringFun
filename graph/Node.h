//
// Created by Dennis Bams on 16/11/2022.
//

#ifndef GRAPHCOLORING_NODE_H
#define GRAPHCOLORING_NODE_H

#include "vector"
#include "Edge.h"

class Node {
public:
    std::vector<std::reference_wrapper<Node>> adjacent;
    int color = 0;
    int id;

    explicit Node(int id);

    void addEdge(Node &n);

    void removeEdge(Node n);

    void removeEdge(int u);

    void removeColor();

    const std::vector<std::reference_wrapper<Node>> &getAdjacent() const;

    int getColor() const;

    void setColor(int c);

    int getId() const;

    friend bool operator==(const Node &lhs, const Node &rhs);

    std::vector<int> adjacentColors();
};


#endif //GRAPHCOLORING_NODE_H
