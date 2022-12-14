//
// Created by Dennis Bams on 18/11/2022.
//

#include "greedy.h"

void greedy::calculateColoring(graph &g) {
    for (node &n: g.nodes) {
        assignColor(n);
    }
}

void greedy::assignColor(node &n) {
    int color = 1;
    std::vector<int> adjacentColors = n.adjacentColors();
    while (std::find_if(adjacentColors.begin(), adjacentColors.end(), [&color](int a) { return color == a; }) !=
           adjacentColors.end()) {
        color++;
    }
    n.setColor(color);
}

int greedy::maxColor(graph &g) {
    calculateColoring(g);
    std::vector<int> coloring = g.getColoring();
    auto it = std::max_element(coloring.begin(), coloring.end());
    return it[0];
}
