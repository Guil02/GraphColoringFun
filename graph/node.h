//
// Created by Dennis Bams on 16/11/2022.
//

#ifndef GRAPHCOLORING_NODE_H
#define GRAPHCOLORING_NODE_H

#include "vector"
#include "edge.h"

class node {
public:
    std::vector<std::reference_wrapper<node>> adjacent;
    int color = 0;
    int id;

    explicit node(int id);

    void addEdge(node &n);

    void removeEdge(node n);

    void removeEdge(int u);

    void removeColor();

    const std::vector<std::reference_wrapper<node>> &getAdjacent() const;

    int getColor() const;

    void setColor(int c);

    int getId() const;

    friend bool operator==(const node &lhs, const node &rhs);

    std::vector<int> adjacentColors();
};


#endif //GRAPHCOLORING_NODE_H
