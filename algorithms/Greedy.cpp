//
// Created by Dennis Bams on 18/11/2022.
//

#include "Greedy.h"

void Greedy::calculateColoring(Graph &g) {
    for (Node &n: g.nodes) {
        assignColor(n);
    }
}

void Greedy::assignColor(Node &n) {
    int color = 1;
    std::vector<int> adjacentColors = n.adjacentColors();
    while (std::find_if(adjacentColors.begin(), adjacentColors.end(), [&color](int a) { return color == a; }) !=
           adjacentColors.end()) {
        color++;
    }
    n.setColor(color);
}
