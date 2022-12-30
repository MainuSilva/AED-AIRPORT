//
// Created by manue on 30/12/2022.
//

#ifndef AED_AIR_INTERFACE_H
#define AED_AIR_INTERFACE_H
#include "Airline.h"
#include "Airport.h"
#include "CoordDistance.h"
#include "Graph.h"
#include <string>

class Interface {

private:
    bool end_prog;
    string airport;

public:
    Interface();
    void showMenu();
    static bool verifyExit();
    void airport_ask();
    void airport_Info();
    void flight_Info();
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
    void wait_B();
    string findAirport();
    string findCity();
    double findLat();
    double findLong();
    void airlineTravel();
    void anyTravel();
    void airportReach();

};


#endif //AED_AIR_INTERFACE_H
