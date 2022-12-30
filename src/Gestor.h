//
// Created by manue on 30/12/2022.
//

#ifndef AED_AIR_GESTOR_H
#define AED_AIR_GESTOR_H
#include "Graph.h"
#include "Airline.h"

#include <list>
#include <unordered_set>

using namespace std;

class Gestor {

private:

    Graph* graph;
public:
    Gestor();
    ~Gestor();

    static void readAirports(Graph &graph);

    static void readFlights(Graph &graph);
};


#endif //AED_AIR_GESTOR_H
