
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
    void airport_Info(string airport);
    void flight_info();
    void country_info();
    void network_info();
    void goAirport();
    void goCity();
    void goCoords();
    void goArticulationP();
    void goDiameter();
    void goTopAirports();
    void goMostFlights();
    void goMostAirlines();
    list<string> airlines_select();
    void cityList(const string& airport);
    void airlinesList(const string& airport);
    void countriesList(const string& airport);
    void flightsNum(string airport);
    static void wait_B();

    string getAirport();
    list<string> getAirlines();
    string getCity();
    double getLat();
    double getLong();
    int getNum();

    void airlineTravel();
    void anyTravel();
    void airportReach(const string& airport);
    string getCountry();
};


#endif //AED_AIR_INTERFACE_H
