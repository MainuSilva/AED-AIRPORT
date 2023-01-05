
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

    vector<list<Airport>> getMinPathAirToCity(const string &airportSrc, const string &city, const list<string> &wantedAirlines);

    vector<list<Airport>> getMinPathAirToLocation(const string &airportSrc, double lat, double lon, double kmDistance, const list<string> &wantedAirlines);

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

    vector<string> getTopNumberAirports(int number, string sortingWay);

    bool conditionPaths(const list<Airport> &airportsA, const list<Airport> &airportsB);

    vector<list<Airport>> getMinPathLocationToLocation(double lat1, double lon1, double kmDistance1, double lat2, double lon2, double kmDistance2, const list<string> &wantedAirlines);

    vector<list<Airport>> getMinPathLocationToCity(double lat, double lon, double kmDistance, const string &city,
                                                   const list<string> &wantedAirlines);

    vector<list<Airport>> getMinPathCityToLocation(const string &city, double lat, double lon, double kmDistance,
                                                   const list<string> &wantedAirlines);

    vector<list<Airport>>
    getMinPathCityToCity(const string &city1, const string &city2, const list<string> &wantedAirlines);

    vector<list<Airport>>
    getMinPathCityToAir(const string &city1, const string &airportDest, const list<string> &wantedAirlines);

    vector<list<Airport>> getMinPathLocationToAir(double lat, double lon, double kmDistance, const string &airportDest,
                                                  const list<string> &wantedAirlines);
};


#endif //AED_AIR_GESTOR_H
