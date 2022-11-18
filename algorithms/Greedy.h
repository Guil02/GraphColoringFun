//
// Created by Dennis Bams on 18/11/2022.
//

#ifndef GRAPHCOLORING_GREEDY_H
#define GRAPHCOLORING_GREEDY_H

#include <vector>
#include "../graph/Graph.h"


class Greedy {
public:
    static void calculateColoring(Graph &g);

    static void assignColor(Node &n);
};


#endif //GRAPHCOLORING_GREEDY_H
