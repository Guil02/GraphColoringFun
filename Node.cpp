//
// Created by Dennis Bams on 15/11/2022.
//

#include "Node.h"

std::list<Node> Node::getAdjacent() {
    return adjacent;
}

void Node::addAdjacent(Node n) {
    adjacent.emplace_back(n);
}

void Node::removeAdjacent(Node *n) {
    //TODO needs to be defined
}

void Node::setColor() {

}

int Node::getColor() {
    return 0;
}
