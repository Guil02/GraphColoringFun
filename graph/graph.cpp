//
// Created by Dennis Bams on 16/11/2022.
//

#include "graph.h"
#include "iostream"

graph::graph() {
    counter = 0;
}

graph::graph(int nodes) {
    for (int i = 0; i < nodes; ++i) {
        this->nodes.emplace_back(node(i));
    }
    counter = nodes;
}

void graph::addNode() {
    nodes.emplace_back(node(counter++));
}

void graph::removeNode(int id) {
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), [&id](const node &a) { return a.id == id; }),
                nodes.end());
}

void graph::removeNode(node n) {
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), [&n](const node &a) { return a == n; }),
                nodes.end());
}

void graph::addEdge(int u, int v) {
    if (containsNode(u) && containsNode(v)) {
        if (!hasEdge(u, v)) {
            edges.emplace_back(edge(u, v));
            nodes[u].addEdge(nodes[v]);
            nodes[v].addEdge(nodes[u]);
        }
    } else {
        throw std::invalid_argument("One of the two nodes was not available in the graph");
    }
}

void graph::removeEdge(int u, int v) {
    if (hasEdge(u, v)) {
        node a = getNode(u);
        node b = getNode(v);
        a.removeEdge(v);
        b.removeEdge(u);
        edges.erase(std::remove_if(edges.begin(), edges.end(), [&u, &v](const edge &a) {
                        return (a.getU() == u && a.getV() == v) || (a.getU() == v && a.getV() == u);
                    }),
                    edges.end());
    }
}

void graph::removeEdge(edge e) {
    if (hasEdge(e)) {
        node a = getNode(e.getU());
        node b = getNode(e.getV());
        a.removeEdge(e.getV());
        b.removeEdge(e.getU());
        edges.erase(std::remove_if(edges.begin(), edges.end(), [&e](const edge &a) { return a == e; }), edges.end());
    }
}

bool graph::containsNode(int id) {
    return std::find_if(nodes.begin(), nodes.end(), [&id](const node &a) { return id == a.id; }) != nodes.end();
}

bool graph::containsNode(node n) {
    return std::find_if(nodes.begin(), nodes.end(), [&n](const node &a) { return n == a; }) != nodes.end();
}

bool graph::hasEdge(int u, int v) {
    return std::find_if(edges.begin(), edges.end(), [&u, &v](const edge &a) {
        return (a.getU() == u && a.getV() == v) || (a.getU() == v && a.getV() == u);
    }) != edges.end();
}

bool graph::hasEdge(edge e) {
    return std::find_if(edges.begin(), edges.end(), [&e](const edge &a) { return a == e; }) != edges.end();
}

node graph::getNode(int id) {
    if (containsNode(id)) {
        return std::find_if(nodes.begin(), nodes.end(), [&id](const node &a) { return id == a.id; })[0];
    } else {
        throw std::invalid_argument("node was not available in the graph");
    }
}

std::vector<int> graph::getColoring() {
    std::vector<int> coloring;
    for (const node &n: nodes) {
        coloring.emplace_back(n.color);
    }
    return coloring;
}

void graph::print() {
    for (int i = 0; i < nodes.size(); ++i) {
        std::cout << "node " << i << ": ";
        node n = nodes[i];
        for (int j = 0; j < n.adjacent.size(); ++j) {
            std::cout << n.adjacent[j].get().getId() << ", ";
        }
        std::cout << "\n";
    }

}


