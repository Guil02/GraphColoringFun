//
// Created by Dennis Bams on 18/11/2022.
//

#include "graphReader.h"
#include "fstream"
#include "sstream"
#include "iostream"
#include <vector>
#include <iterator>

graph graphReader::readInGraph(std::string filePath) {
    std::fstream infile(filePath);
    std::string line;
    graph g = graph();
    while (std::getline(infile, line)) {
//        std::istringstream iss(line);
        std::vector<std::string> splitLine = split(line, ' ');
        if (splitLine[0] == "VERTICES") {
            g.addNodes(std::stoi(splitLine[2]));
        } else if (splitLine[0] == "EDGES") {
            continue;
        } else {
            g.addEdge(std::stoi(splitLine[0]) - 1, std::stoi(splitLine[1]) - 1);
        }
    }
    return g;
}




