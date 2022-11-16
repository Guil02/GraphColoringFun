//
// Created by Dennis Bams on 16/11/2022.
//

#ifndef GRAPHCOLORING_NODE_H
#define GRAPHCOLORING_NODE_H

#include "vector"

static int counter = 0;

class Node {
public:
    std::vector<Node> adjacent;
    int color = 0;
    int id;

    Node();

    void addEdge(Node n);

    void removeEdge(Node n);

    void removeColor();

    const std::vector<Node> &getAdjacent() const;

    int getColor() const;

    void setColor(int c);

    friend bool operator==(const Node &lhs, const Node &rhs);
};


#endif //GRAPHCOLORING_NODE_H
