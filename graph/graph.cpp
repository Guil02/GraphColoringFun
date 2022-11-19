//
// Created by Dennis Bams on 16/11/2022.
//

#include "graph.h"
#include "iostream"

graph::graph() {
    counter = 0;
}

graph::graph(int nodes) {
    // initialize a graph with a given amount of nodes
    for (int i = 0; i < nodes; ++i) {
        this->nodes.emplace_back(node(i));
    }
    counter = nodes;
}

void graph::addNode() {
    // add node to the graph
    nodes.emplace_back(node(counter++));
}

void graph::addNodes(int nodes) {
    for (int i = 0; i < nodes; ++i) {
        addNode();
    }
}

void graph::removeNode(int id) {
    // search if the node exist in the vector then remove it.
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), [&id](const node &a) { return a.id == id; }),
                nodes.end());
}

void graph::removeNode(node n) {
    // search if the node exist in the vector move it to the end then remove everything from the position found to the end.
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), [&n](const node &a) { return a == n; }),
                nodes.end());
}

void graph::addEdge(int u, int v) {
    // check if the nodes are in the graph
    if (containsNode(u) && containsNode(v)) {
        // check if the edges does not yet already exist.
        if (!hasEdge(u, v)) {
            // add the edge object to the list.
            edges.emplace_back(edge(u, v));
            // add the reference to the other node in the node's adjacency vector.
            nodes[u].addEdge(nodes[v]);
            nodes[v].addEdge(nodes[u]);
        }
    } else {
        throw std::invalid_argument("One of the two nodes was not available in the graph");
    }
}

void graph::removeEdge(int u, int v) {
    // check if there is an edge to remove
    if (hasEdge(u, v)) {
        node a = getNode(u);
        node b = getNode(v);
        // remove the node from the other's adjacency vector
        a.removeEdge(v);
        b.removeEdge(u);
        // remove the edge from the edge vector.
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

void graph::adjacencyListPrint() {
    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = 0; j < nodes.size(); ++j) {
            if (hasEdge(i, j)) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }

            if (j != nodes.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "\n";
    }
}


