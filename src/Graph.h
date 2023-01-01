#ifndef AED_AIR_GRAPH_H
#define AED_AIR_GRAPH_H

#include "Airport.h"

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

class Graph {
public:
    struct Edge {
        string destination;   // Destination node
        list<string> airlines;
    };

    struct Node {
        Airport airport;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        set<string> allAirlines;
        bool visited;// As the node been visited on a search?
        bool inStack;
        bool inArt;
        int distance;
        int num;
        int low;
        string pred;
    };

    unordered_map<string, Node> nodes;

    // Constructor: nr nodes and direction (default: undirected)
    Graph();

    void addNode(const Airport &airport);

    // Add edge from source to destination with a certain weight
    void addEdge(const string& src, const string& dest, const string& airline);

    void restart();

    void bfs(const string& v );

    vector<list<struct Airport>> findMinPathsBfs(const string &airportSrc, const string &airportDest, const list<string> &airlines);

    vector<list<struct Airport>> minPathsAirportsBfs(const string &airportSrc, const list<string> &wantedAirports, const list<string> &wantedAirlines);

    list<Airport> possibleAirports(const string &airportSrc, int flights);

    list <string> closestAirports(double lat, double lon , double kmdistance);

    list<string> cityAirports(const string& city);

    set<string> possibleCities(const string &airportSrc, int flights);

    set<string> possibleCountries(const string &airportSrc, int flights);

    static bool conditionPaths(const list<Airport>& airportA, const list<Airport>& airportB);

    bool hasCommonAirlines(const list<string> &airlines1, const list<string> &airlines2);

    list<Airport> constructPath(string curr, const string& airportSrc);

    list<string> getArticulationPoints(const list<string> &wantedAirlines);

    void dfsArticulations(const string& v, stack<string> &s, const list<string> &wantedAirlines, list<string> &result, int index);

    int bfs_diameter(const string &v);

    int getDiameter();

    vector<string> getTopAirports(int number);

    int pathDistance(list<Airport> airports);
};

#endif //AED_AIR_GRAPH_H
