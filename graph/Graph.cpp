//
// Created by Dennis Bams on 16/11/2022.
//

#include "Graph.h"

Graph::Graph() {
    counter = 0;
}

Graph::Graph(int nodes) {
    for (int i = 0; i < nodes; ++i) {
        this->nodes.emplace_back(Node(i));
    }
    counter = nodes;
}

void Graph::addNode() {
    nodes.emplace_back(Node(counter++));
}

void Graph::removeNode(int id) {
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), [&id](const Node &a) { return a.id == id; }),
                nodes.end());
}

void Graph::removeNode(Node n) {
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), [&n](const Node &a) { return a == n; }),
                nodes.end());
}

void Graph::addEdge(int u, int v) {
    if (containsNode(u) && containsNode(v)) {
        if (!hasEdge(u, v)) {
            edges.emplace_back(Edge(u, v));
            Node a = getNode(u);
            Node b = getNode(v);
            a.addEdge(b);
            b.addEdge(a);
        }
    } else {
        throw std::invalid_argument("One of the two nodes was not available in the graph");
    }
}

void Graph::removeEdge(int u, int v) {
    if (hasEdge(u, v)) {
        Node a = getNode(u);
        Node b = getNode(v);
        a.removeEdge(v);
        b.removeEdge(u);
        edges.erase(std::remove_if(edges.begin(), edges.end(), [&u, &v](const Edge &a) {
                        return (a.getU() == u && a.getV() == v) || (a.getU() == v && a.getV() == u);
                    }),
                    edges.end());
    }
}

void Graph::removeEdge(Edge e) {
    if (hasEdge(e)) {
        Node a = getNode(e.getU());
        Node b = getNode(e.getV());
        a.removeEdge(e.getV());
        b.removeEdge(e.getU());
        edges.erase(std::remove_if(edges.begin(), edges.end(), [&e](const Edge &a) { return a == e; }), edges.end());
    }
}

bool Graph::containsNode(int id) {
    return std::find_if(nodes.begin(), nodes.end(), [&id](const Node &a) { return id == a.id; }) != nodes.end();
}

bool Graph::containsNode(Node n) {
    return std::find_if(nodes.begin(), nodes.end(), [&n](const Node &a) { return n == a; }) != nodes.end();
}

bool Graph::hasEdge(int u, int v) {
    return std::find_if(edges.begin(), edges.end(), [&u, &v](const Edge &a) {
        return (a.getU() == u && a.getV() == v) || (a.getU() == v && a.getV() == u);
    }) != edges.end();
}

bool Graph::hasEdge(Edge e) {
    return std::find_if(edges.begin(), edges.end(), [&e](const Edge &a) { return a == e; }) != edges.end();
}

Node Graph::getNode(int id) {
    if (containsNode(id)) {
        return std::find_if(nodes.begin(), nodes.end(), [&id](const Node &a) { return id == a.id; })[0];
    } else {
        throw std::invalid_argument("Node was not available in the graph");
    }
}


