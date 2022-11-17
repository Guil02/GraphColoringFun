//
// Created by Dennis Bams on 17/11/2022.
//

#include "Edge.h"

Edge::Edge(int u, int v) {
    this->u = u;
    this->v = v;
}

int Edge::getU() const {
    return u;
}

void Edge::setU(int u) {
    Edge::u = u;
}

int Edge::getV() const {
    return v;
}

void Edge::setV(int v) {
    Edge::v = v;
}

bool operator==(const Edge &lhs, const Edge &rhs) {
    return lhs.u == rhs.u && lhs.v == rhs.v;
}
