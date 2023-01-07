#include "Gestor.h"

#include <fstream>
#include <sstream>

using namespace std;

Gestor::Gestor() {
    graph = new Graph();
    readAirports();
    readFlights();
    readAirlines();
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

        city_codes.insert(city);
        country_codes.insert(country);
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

bool Gestor::availableAirport(const string& airport) {
    return graph->availableAirport(airport);
}

bool Gestor::availableCity(const string& city) {
    auto result = city_codes.find(city);
    if(result != city_codes.end())
        return true;
    return false;
}

bool Gestor::availableCountry(const string& country) {
    auto result = country_codes.find(country);
    if(result != country_codes.end())
        return true;
    return false;
}

bool Gestor::availableAirline(const string& airline) {
    return graph->availableAirline(airline);
}

//aeroporto para aeroporto
vector<list<Airport>> Gestor::getMinPathTwoAirports(const string& airportSrc, const string& airportDest, const list<string>& wantedAirlines = {}){
    return graph->findMinPathsAirportsBfs(airportSrc, airportDest, wantedAirlines);
}

//aeroporto para localização
vector<list<Airport>> Gestor:: getMinPathAirToCity(const string& airportSrc, const string& city, const list<string>& wantedAirlines = {}){
    list<string> cityAirports = graph->getCityAirports(city);
    return graph->findMinPathsAirToLocationBfs(airportSrc, cityAirports, wantedAirlines);
}

//aeroporto para localização
vector<list<Airport>> Gestor:: getMinPathAirToLocation(const string& airportSrc, double lat, double lon, double kmDistance, const list<string>& wantedAirlines = {}){
    list<string> locationAirports = graph->getLocationAirports(lat, lon, kmDistance);
    return graph->findMinPathsAirToLocationBfs(airportSrc, locationAirports, wantedAirlines);
}

//localização para localização
vector<list<Airport>> Gestor:: getMinPathLocationToLocation(double lat1, double lon1, double kmDistance1, double lat2, double lon2, double kmDistance2, const list<string>& wantedAirlines = {}){
    list<string> source = graph ->getLocationAirports(lat1, lon1 , kmDistance1);
    list<string> destination= graph ->getLocationAirports(lat2, lon2 , kmDistance2);
    return graph->findMinPathsLocationsBfs(source, destination, wantedAirlines);
}

//localização para cidade
vector<list<Airport>> Gestor:: getMinPathLocationToCity(double lat, double lon, double kmDistance, const string& city, const list<string>& wantedAirlines = {}){
    list<string> source = graph -> getLocationAirports(lat, lon , kmDistance);
    list<string> destination = graph -> getCityAirports(city);
    return graph->findMinPathsLocationsBfs(source, destination, wantedAirlines);
}

//cidade para localização
vector<list<Airport>> Gestor:: getMinPathCityToLocation( const string& city, double lat, double lon, double kmDistance, const list<string>& wantedAirlines = {}){
    list<string> source = graph -> getCityAirports(city);
    list<string> destination = graph -> getLocationAirports(lat, lon , kmDistance);
    return graph->findMinPathsLocationsBfs(source, destination, wantedAirlines);
}

//cidade para cidade
vector<list<Airport>> Gestor:: getMinPathCityToCity( const string& city1, const string& city2, const list<string>& wantedAirlines = {}){
    list<string> source = graph -> getCityAirports(city1);
    list<string> destination = graph -> getCityAirports(city2);
    return graph->findMinPathsLocationsBfs(source, destination, wantedAirlines);
}

//cidade para aeroporto
vector<list<Airport>> Gestor:: getMinPathCityToAir( const string& city, const string& airportDest, const list<string>& wantedAirlines = {}){
    list<string> source = graph -> getCityAirports(city);
    return graph->findMinPathsLocationToAirBfs(source, airportDest, wantedAirlines);
}

//localização para aeroporto
vector<list<Airport>> Gestor:: getMinPathLocationToAir( double lat, double lon, double kmDistance, const string& airportDest, const list<string>& wantedAirlines = {}){
    list<string> source = graph -> getLocationAirports(lat, lon , kmDistance);
    return graph->findMinPathsLocationToAirBfs(source, airportDest, wantedAirlines);
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

vector<string> Gestor::getTopNumberAirports(int number, string sortingWay){
    return graph->getTopAirports(number, sortingWay);
}

// condição que ordena o vetor de paths por ordem crescente de tamanho e de distância de path
bool Gestor::conditionPaths(const list<Airport>& airportsA, const list<Airport>& airportsB){
    if(airportsA.size() == airportsB.size())
        return graph->pathDistance(airportsA) < graph->pathDistance(airportsB);
    return airportsA.size() < airportsB.size();

}

list<Airline> Gestor::getAllAirLinesFromCountry(const string& country){
    return graph->getAirlinesFromCountry(country);
}

list<Airport> Gestor::getAllAirportsFromCountry(const string& country){
    return graph->getAirportsFromCountry(country);
}

int Gestor::getTotalNumberOfAirlines(){
    return graph->getTotalNumberOfAirlines();
}

int Gestor::getTotalNumberOfAirports() {
    return graph->getTotalNumberOfAirports();
}

int Gestor::getTotalNumberOfFlights() {
    return graph->getTotalNumberOfFlights();
}

int Gestor::getTotalNumberOfCities() {
    return city_codes.size();
}

int Gestor::getTotalNumberOfCountries() {
    return country_codes.size();
}

list<pair<string,string>> Gestor::getDepartureBoard(const string& airport) {
    return graph->getDepartureBoard(airport);
}