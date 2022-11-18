//
// Created by Dennis Bams on 17/11/2022.
//

#include "edge.h"

edge::edge(int u, int v) {
    this->u = u;
    this->v = v;
}

int edge::getU() const {
    return u;
}

void edge::setU(int u) {
    edge::u = u;
}

int edge::getV() const {
    return v;
}

void edge::setV(int v) {
    edge::v = v;
}

bool operator==(const edge &lhs, const edge &rhs) {
    return lhs.u == rhs.u && lhs.v == rhs.v;
}
