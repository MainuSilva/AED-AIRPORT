#ifndef AED_AIR_GRAPH_H
#define AED_AIR_GRAPH_H

#include "Airport.h"

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

class Graph {
public:
    struct Edge {
        string destination;   // Destination node
        list<string> airlines;
        double kmDistance;
    };

    struct Node {
        Airport airport;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int distance;
        string pred;
    };

    unordered_map<string, Node> nodes;

    // Constructor: nr nodes and direction (default: undirected)
    Graph();

    void addNode(const Airport &airport);

    // Add edge from source to destination with a certain weight
    void addEdge(const string& src, const string& dest, const string& airline);

    void restart();

    void bfs(const string& v);

    list<list<Airport>>findMinPathsBfs(const string &airportSrc, const string &airportDest, const list<string> &airlines);

    list<Airport> possibleAirports(const string &airportSrc, int flights);

};

#endif //AED_AIR_GRAPH_H
