//
// Created by Dennis Bams on 18/11/2022.
//

#include "Greedy.h"
#include <iostream>

void Greedy::calculateColoring(Graph &g) {
    for (Node &n: g.nodes) {
        assignColor(n);
    }
}

void Greedy::assignColor(Node &n) {
    std::vector<int> adjacentColors = n.adjacentColors();
    if (adjacentColors.empty()) {
        n.setColor(1);
    } else {
        auto it = std::max_element(adjacentColors.begin(), adjacentColors.end());
        n.setColor(it[0] + 1);
    }
}
