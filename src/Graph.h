#ifndef AED_AIR_GRAPH_H
#define AED_AIR_GRAPH_H

#include "Airport.h"
#include "Airline.h"

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

class Graph {
private:
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
    unordered_map<string, Airline> airlines;

    void restart();

    void bfs(const string& v );

    int bfsDiameter(const string &v, const list<string> &wantedAirlines);

    void bfsArticulations(const string& v, stack<string> &s, const list<string> &wantedAirlines, list<string> &result, int index);

    bool hasCommonAirlines(const list<string> &airlines1, const list<string> &airlines2);

    list<Airport> constructPath(string curr, const string& airportSrc);

public:
    Graph();

    void addNode(const Airport &airport);

    // Add edge from source to destination with a certain weight
    void addEdge(const string& src, const string& dest, const string& airline);

    vector<list<struct Airport>> findMinPathsBfs(const string &airportSrc, const string &airportDest, const list<string> &airlines);

    vector<list<struct Airport>> getMinPathsAirportsBfs(const string &airportSrc, const list<string> &wantedAirports, const list<string> &wantedAirlines);

    int pathDistance(list<Airport> airports);

    list<string> getLocationAirports(double lat, double lon , double kmdistance);

    list<string> getCityAirports(const string& city);

    list<string> getArticulationPoints(const list<string> &wantedAirlines);

    vector<string> getTopAirports(int number);

    list<Airport> getPossibleFlightsAirports(const string &airportSrc, int flights);

    int getNumberOfFlights(const string &airport);

    void addAirline(const Airline &airline);

    list<Airport> getAirportsArrived(const string &airport);

    list<Airline> getAirportAirlines(const string &airport);

    int getDiameter(const list<string> &wantedAirlines);

    int getTotalNumberOfAirlines();

    int getTotalNumberOfAirports();

    int getTotalNumberOfFlights();

    bool availableAirline(const string &airline);

    bool availableAirport(const string &airport);
};

#endif //AED_AIR_GRAPH_H
