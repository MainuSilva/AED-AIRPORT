//
// Created by manue on 30/12/2022.
//

#ifndef AED_AIR_INTERFACE_H
#define AED_AIR_INTERFACE_H
#include "Airline.h"
#include "Airport.h"
#include "CoordDistance.h"
#include "Graph.h"
#include "Gestor.h"
#include <string>

class Interface {

private:
    Gestor* gestor;
    bool end_prog;

public:
    Interface();
    void showMenu();
    bool verifyExit();
    void airport_ask();
    void airport_Info();
    void flight_info();
    void goAirport();
    void goCity();
    void goCoords();
    void departuresBoard();
    void airlines_Info();
    void destinationsList();
    void airlinesList();
    void countriesList();
    void flights();
    void flightsNum();
    static void wait_B();
    string getAirport();
    string getCity();
    static double getLat();
    static double getLong();
    void airlineTravel();
    void anyTravel();
    void airportReach();
    string getCountry();
};


#endif //AED_AIR_INTERFACE_H
