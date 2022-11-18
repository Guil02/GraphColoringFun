//
// Created by Dennis Bams on 16/11/2022.
//

#include "Node.h"

Node::Node(int id) {
    this->id = id;
}

bool operator==(const Node &lhs, const Node &rhs) {
    return lhs.id == rhs.id;
}

void Node::addEdge(Node &n) {
    adjacent.emplace_back(std::reference_wrapper<Node>(n));
}

void Node::removeEdge(Node n) {
    adjacent.erase(std::remove_if(adjacent.begin(), adjacent.end(), [&n](const Node &a) { return a == n; }),
                   adjacent.end());
}

const std::vector<std::reference_wrapper<Node>> &Node::getAdjacent() const {
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

void Node::removeEdge(int u) {
    adjacent.erase(std::remove_if(adjacent.begin(), adjacent.end(),
                                  [&u](const Node &a) { return u == a.getId(); }), adjacent.end());
}

int Node::getId() const {
    return id;
}

std::vector<int> Node::adjacentColors() {
    std::vector<int> adjacentColors;
    for (Node &n: adjacent) {
        adjacentColors.emplace_back(n.color);
    }
    return adjacentColors;
}


