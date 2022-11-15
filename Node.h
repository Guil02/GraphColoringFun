//
// Created by Dennis Bams on 15/11/2022.
//

#ifndef GRAPHCOLORING_NODE_H
#define GRAPHCOLORING_NODE_H


#include <list>
#include <string>

class Node {
public:
    std::list<Node> adjacent;
    int color;

    std::list<Node> getAdjacent();

    int getColor();

    void setColor();

    void addAdjacent(Node n);

    void removeAdjacent(Node *n);
};


#endif //GRAPHCOLORING_NODE_H
