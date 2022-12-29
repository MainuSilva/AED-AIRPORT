#ifndef AED_AIR_GRAPH_H
#define AED_AIR_GRAPH_H

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include "Airport.h"

using namespace std;

class Graph {
public:
    struct Edge {
        string destination;   // Destination node
        vector<string> airlines;
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int distance;
    };

    unordered_map<string, Node> nodes;
    unordered_map<string, Airport>; // colocar os aeroportos existentes

    // Constructor: nr nodes and direction (default: undirected)
    Graph();

    void addNode(const Airport &airport);

    // Add edge from source to destination with a certain weight
    void addEdge(const string& src, const string& dest, const string& airline);

    // Depth-First Search
    void dfs(const string& v);

    // Breadth-First Search
    void bfs(const string& v);

    void addNode(const string airport_code, const Airport &airport);

    list<string> findMinPathBfs(const string &airportSrc, const string &airportDest);

    void restart();

};

#endif //AED_AIR_GRAPH_H
