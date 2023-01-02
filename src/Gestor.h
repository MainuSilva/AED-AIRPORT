
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
    //to verify if they exist
    unordered_set<string> city_codes;
    unordered_set<string> country_codes;
public:
    Gestor();
    ~Gestor();
    void readAirports();
    void readFlights();
    void readAirlines();

    bool availableAirport(const string& airport);
    bool availableCity(const string& city);
    bool availableCountry(const string& country);
    bool availableAirline(const string& airline);

    vector<list<Airport>> getMinPathTwoAirports(const string &airportSrc, const string &airportDest, const list<string> &wantedAirlines);

    vector<list<Airport>> getMinPathToCity(const string &airportSrc, const string &city, const list<string> &wantedAirlines);

    vector<list<Airport>> getMinPathToLocation(const string &airportSrc, double lat, double lon, double kmDistance, const list<string> &wantedAirlines);

    list<string> getArticulationPoints(const list<string> &wantedAirlines);

    int getNumberOfAirportFlights(const string& airport);

    list<Airline> getAirportAirlines(const string &airport);

    int getDiameter(const list<string> &wantedAirlines);

    list<Airport> getAirportsArrived(const string &airport);

    set<string> getCitiesArrived(const string &airport);

    set<string> getCountriesArrived(const string &airport);

    set<string> getPossibleFlightsCountries(const string &airportSrc, int flights);

    set<string> getPossibleFlightsCities(const string &airportSrc, int flights);

    list<Airport> getPossibleFlightsAirports(const string &airportSrc, int flights);

    vector<string> getTopNumberAirports(int number);

    bool conditionPaths(const list<Airport> &airportsA, const list<Airport> &airportsB);
};


#endif //AED_AIR_GESTOR_H
