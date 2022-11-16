//
// Created by Dennis Bams on 16/11/2022.
//

#include "Node.h"

Node::Node() {
    id = counter++;
}

bool operator==(const Node &lhs, const Node &rhs) {
    return lhs.id == rhs.id;
}

void Node::addEdge(Node n) {
    adjacent.emplace_back(n);
}

void Node::removeEdge(Node n) {
    adjacent.erase(std::remove_if(adjacent.begin(), adjacent.end(), [&n](const Node &a) { return a == n; }),
                   adjacent.end());
}

const std::vector<Node> &Node::getAdjacent() const {
    return adjacent;
}

int Node::getColor() const {
    return color;
}

void Node::setColor(int c) {
    Node::color = c;
}

void Node::removeColor() {
    Node::color = 0;
}


