//
// Created by Dennis Bams on 18/11/2022.
//

#ifndef GRAPHCOLORING_BRONKERBOSCH_H
#define GRAPHCOLORING_BRONKERBOSCH_H


#include "../graph/graph.h"

class bronKerbosch {
public:
    int maxClique;

    int calculateLowerBound(graph &g);

    void bronKerbosch2(std::vector<node> R, std::vector<node> P, std::vector<node> X);

    std::vector<node> removeNeighbours(node v, std::vector<node> P);

    std::vector<node> intersectionNeighbours(node v, std::vector<node> P);
};

#endif //GRAPHCOLORING_BRONKERBOSCH_H
