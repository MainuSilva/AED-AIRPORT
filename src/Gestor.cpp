
#include "Gestor.h"

#include <fstream>
#include <sstream>

using namespace std;

Gestor::Gestor() {
    graph = new Graph();
}

Gestor::~Gestor() { delete graph; }

//first add nodes
void Gestor::readAirports(){
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
        graph->addNode(airport); // add to graph
    }

}

//second add edges
void Gestor::readFlights(){
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

        graph->addEdge(src, dest, airline);
    }
}

void Gestor::readAirlines(){
    ifstream file("../data/airlines.csv");
    string line;

    for (size_t i = 0; getline(file, line); i++) {
        if (i == 0) continue;

        stringstream ss(line);
        string code, name, callsign, country;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, callsign, ',');
        getline(ss, country, '\r');

        Airline airline = Airline(code, name, callsign, country);
        graph->addAirline(airline);
    }
}


vector<list<Airport>> Gestor::getMinPathTwoAirports(const string& airportSrc, const string& airportDest, const list<string>& wantedAirlines = {}){
    return graph->findMinPathsBfs(airportSrc, airportDest, wantedAirlines);
}

vector<list<Airport>> Gestor:: getMinPathToCity(const string& airportSrc, const string& city, const list<string>& wantedAirlines = {}){
    list<string> cityAirports = graph->getCityAirports(city);
    return graph->getMinPathsAirportsBfs(airportSrc, cityAirports, wantedAirlines);
}

vector<list<Airport>> Gestor:: getMinPathToLocation(const string& airportSrc, double lat, double lon, double kmDistance, const list<string>& wantedAirlines = {}){
    list<string> locationAirports = graph->getLocationAirports(lat, lon, kmDistance);
    return graph->getMinPathsAirportsBfs(airportSrc, locationAirports, wantedAirlines);
}

list<string> Gestor::getArticulationPoints(const list<string>& wantedAirlines = {}){
    return graph->getArticulationPoints(wantedAirlines);
}

int Gestor::getNumberOfAirportFlights(const string& airport){
    return graph->getNumberOfFlights(airport);
}

list<Airline> Gestor::getAirportAirlines(const string& airport){
    return graph->getAirportAirlines(airport);
}

list<Airport> Gestor::getAirportsArrived(const string& airport){
    return graph->getAirportsArrived(airport);
}

set<string> Gestor::getCitiesArrived(const string& airport){
    set<string> cities;
    for(const auto& a: graph->getAirportsArrived(airport)){
        cities.insert(a.get_city());
    }

    return cities;
}

set<string> Gestor::getCountriesArrived(const string& airport){
    set<string> countries;
    for(const auto& a: graph->getAirportsArrived(airport)){
        countries.insert(a.get_country());
    }
    return countries;
}

list<Airport> Gestor::getPossibleFlightsAirports(const string& airportSrc, int flights){
    return graph->getPossibleFlightsAirports(airportSrc, flights);
}

set<string> Gestor:: getPossibleFlightsCities(const string& airportSrc, int flights){
    set<string> result;

    list<Airport> airports = graph->getPossibleFlightsAirports(airportSrc, flights);

    for(const Airport& airport : airports){
        result.insert(airport.get_city());
    }

    return result;
}

set<string> Gestor::getPossibleFlightsCountries(const string& airportSrc, int flights){
    set<string> result;

    list<Airport> airports = graph->getPossibleFlightsAirports(airportSrc, flights);

    for(const Airport& airport : airports){
        result.insert(airport.get_country());
    }

    return result;
}


int Gestor::getDiameter(const list<string>& wantedAirlines = {}){
    return graph->getDiameter(wantedAirlines);
}

vector<string> Gestor::getTopNumberAirports(int number){
    return graph->getTopAirports(number);
}

// condição que ordena o vetor de paths por ordem crescente de tamanho e de distância de path
bool Gestor::conditionPaths(const list<Airport>& airportsA, const list<Airport>& airportsB){
    if(airportsA.size() == airportsB.size())
        return graph->pathDistance(airportsA) < graph->pathDistance(airportsB);
    return airportsA.size() < airportsB.size();

}





