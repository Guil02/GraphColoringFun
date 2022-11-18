//
// Created by Dennis Bams on 17/11/2022.
//

#ifndef GRAPHCOLORING_EDGE_H
#define GRAPHCOLORING_EDGE_H


class Edge {
public:
    int u;
    int v;

    Edge(int u, int v);

    int getU() const;

    void setU(int u);

    int getV() const;

    void setV(int v);

    friend bool operator==(const Edge &lhs, const Edge &rhs);
};


#endif //GRAPHCOLORING_EDGE_H
