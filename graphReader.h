//
// Created by Dennis Bams on 18/11/2022.
//

#ifndef GRAPHCOLORING_GRAPHREADER_H
#define GRAPHCOLORING_GRAPHREADER_H


#include <sstream>
#include "graph/graph.h"
#include "string"

class graphReader {
public:
    graph readInGraph(std::string filePath);

    template<typename Out>
    void split(const std::string &s, char delim, Out result) {
        std::istringstream iss(s);
        std::string item;
        while (std::getline(iss, item, delim)) {
            *result++ = item;
        }
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }


};


#endif //GRAPHCOLORING_GRAPHREADER_H
