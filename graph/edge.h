//
// Created by Dennis Bams on 17/11/2022.
//

#ifndef GRAPHCOLORING_EDGE_H
#define GRAPHCOLORING_EDGE_H


class edge {
public:
    int u;
    int v;

    edge(int u, int v);

    int getU() const;

    void setU(int u);

    int getV() const;

    void setV(int v);

    friend bool operator==(const edge &lhs, const edge &rhs);
};


#endif //GRAPHCOLORING_EDGE_H
