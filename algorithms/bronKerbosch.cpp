//
// Created by Dennis Bams on 18/11/2022.
//

#include "bronKerbosch.h"

int bronKerbosch::calculateLowerBound(graph &g) {
    maxClique = 0;
    std::vector<node> P = g.nodes;
    bronKerbosch2(std::vector<node>(), P, std::vector<node>());
    return maxClique;
}

void bronKerbosch::bronKerbosch2(std::vector<node> R, std::vector<node> P, std::vector<node> X) {
    if (P.empty() && X.empty()) {
        maxClique = R.size();
    }
    for (node v: P) {
        R.emplace_back(v);
        bronKerbosch2(R, intersectionNeighbours(v, P), intersectionNeighbours(v, X));
        // remove node v from R
        R.erase(std::remove_if(R.begin(), R.end(), [&v](node a) { return v == a; }), R.end());
    }
}

std::vector<node> bronKerbosch::removeNeighbours(node v, std::vector<node> P) {
    std::vector<std::reference_wrapper<node>> adjacent = v.getAdjacent();
    for (std::reference_wrapper<node> n: adjacent) {
        P.erase(std::remove_if(P.begin(), P.end(), [&n](node a) { return n.get() == a; }), P.end());
    }
    return P;
}

std::vector<node> bronKerbosch::intersectionNeighbours(node v, std::vector<node> P) {
    std::vector<std::reference_wrapper<node>> adjacent = v.getAdjacent();
    std::vector<node> intersection;
    for (node n: P) {
        if (std::find_if(adjacent.begin(), adjacent.end(),
                         [&n](std::reference_wrapper<node> a) { return a.get() == n; }) != adjacent.end()) {
            intersection.emplace_back(n);
        }
    }
    return intersection;
}
