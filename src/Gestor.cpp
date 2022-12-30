
#include "Gestor.h"

#include <fstream>
#include <sstream>

using namespace std;

Gestor::Gestor() {
    graph = new Graph();
}

Gestor::~Gestor() { delete graph; }

//first add nodes
void Gestor::readAirports(Graph& graph){
    ifstream file("../data/airports.csv");
    string line;

    for (size_t i = 0; getline(file, line); i++) {
        // Skip the first line
        if (i == 0) continue;

        stringstream ss(line);
        string code, name, city, country, lat, lon;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        getline(ss, lat, ',');
        getline(ss, lon, ',');

        Airport airport(code, name, city, country, stod(lat), stod(lon));
        graph.addNode(airport); // add to graph
    }

}

//second add edges
void Gestor::readFlights(Graph& graph){
    ifstream file("../data/flights.csv");
    string line;

    for (size_t i = 0; getline(file, line); i++) {
        // Skip the first line
        if (i == 0) continue;

        stringstream ss(line);
        string src, dest, airline;
        getline(ss, src, ',');
        getline(ss, dest, ',');
        getline(ss, airline, '\r');

        graph.addEdge(src, dest, airline);
    }
}




