//
// Created by Dennis Bams on 16/11/2022.
//

#include "node.h"

node::node(int id) {
    this->id = id;
}

bool operator==(const node &lhs, const node &rhs) {
    return lhs.id == rhs.id;
}

void node::addEdge(node &n) {
    adjacent.emplace_back(std::reference_wrapper<node>(n));
}

void node::removeEdge(node n) {
    adjacent.erase(std::remove_if(adjacent.begin(), adjacent.end(), [&n](const node &a) { return a == n; }),
                   adjacent.end());
}

const std::vector<std::reference_wrapper<node>> &node::getAdjacent() const {
    return adjacent;
}

int node::getColor() const {
    return color;
}

void node::setColor(int c) {
    node::color = c;
}

void node::removeColor() {
    node::color = 0;
}

void node::removeEdge(int u) {
    adjacent.erase(std::remove_if(adjacent.begin(), adjacent.end(),
                                  [&u](const node &a) { return u == a.getId(); }), adjacent.end());
}

int node::getId() const {
    return id;
}

std::vector<int> node::adjacentColors() {
    std::vector<int> adjacentColors;
    for (node &n: adjacent) {
        adjacentColors.emplace_back(n.color);
    }
    return adjacentColors;
}


