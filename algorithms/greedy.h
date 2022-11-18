//
// Created by Dennis Bams on 18/11/2022.
//

#ifndef GRAPHCOLORING_GREEDY_H
#define GRAPHCOLORING_GREEDY_H

#include <vector>
#include "../graph/graph.h"


class greedy {
public:
    static void calculateColoring(graph &g);

    static void assignColor(node &n);
};


#endif //GRAPHCOLORING_GREEDY_H
