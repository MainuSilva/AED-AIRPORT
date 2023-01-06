
#ifndef AED_AIR_GESTOR_H
#define AED_AIR_GESTOR_H
#include "Graph.h"
#include "Airline.h"

#include <list>
#include <unordered_set>

using namespace std;

/**
 * @brief Classe responsável por gerir todas as funcionalidades
 */


class Gestor {
private:
    /// Grafo que contem todas as companhias aereas, aeroportos e voos
    Graph* graph;
    
    /// hash table com todos os códigos de cidades
    unordered_set<string> city_codes;
    
    /// hash table com todos os códigos de países
    unordered_set<string> country_codes;
public:

    /**
     * @brief Constructor da classe
     */
    Gestor();
    
    /**
     * @brief Destrutor da classe
     */
    ~Gestor();
    
    /**
     * @brief Lê o ficheiro "Airports.csv"
     * Complexidade Temporal: O(n) onde n é o número de linhas do ficheiro
     */
    void readAirports();
    
    /**
     * @brief Lê o ficheiro "Flights.csv"
     * Complexidade Temporal: O(n) onde n é o número de linhas do ficheiro
     */
    void readFlights();
    
    /**
     * @brief Lê o ficheiro "Airlines.csv"
     * Complexidade Temporal: O(n) onde n é o número de linhas do ficheiro
     */
    void readAirlines();

   /**
    * @brief Função que indica se o aeroporto está ou não disponível
    * Complexidade temporal O(1)
    * @param airport
    * @return Devolve true se estiver e false caso contrário
    */
    bool availableAirport(const string& airport);
    
    /**
    * @brief Função que indica se a cidade está ou não disponível
    * Complexidade temporal O(1)
    * @param city
    * @return Devolve true se estiver e false caso contrário
    */
    bool availableCity(const string& city);
    
    /**
    * @brief Função que indica se o país está ou não disponível
    * Complexidade temporal O(1)
    * @param country
    * @return Devolve true se estiver e false caso contrário
    */
    bool availableCountry(const string& country);
    
    /**
    * @brief Função que indica se a companhia aerea está ou não disponível
    * Complexidade temporal O(1)
    * @param airline
    * @return Devolve true se estiver e false caso contrário
    */
    bool availableAirline(const string& airline);
    
    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para um de destino
    * Complexidade Temporal: O(n + m) no pior caso, onde n é o número de nodes no grafo e m o número de edges.
    * @param airportSrc
    * @param airportDest
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathTwoAirports(const string &airportSrc, const string &airportDest, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para uma cidade de destino
    * Complexidade Temporal: (n * m * k) no pior caso, onde n é o número de nodes do grafo, m é o número de edges e k o número de aeroportos de destino.
    * @param airportSrc
    * @param city
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathAirToCity(const string &airportSrc, const string &city, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para uma localização de destino
    * Complexidade Temporal: (n * m * k) no pior caso, onde n é o número de nodes do grafo, m é o número de edges e k o número de aeroportos de destino.
    * @param airportSrc
    * @param lat
    * @param lon
    * @param kmDistance
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathAirToLocation(const string &airportSrc, double lat, double lon, double kmDistance, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve os pontos de articulação do grafo
    * Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    * @param wantedAirlines
    * @return Lista com os dados que se pretendia aceder
    */
    list<string> getArticulationPoints(const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve o número de voos de um aeroporto
    * Complexidade temporal O(1)
    * @param airport
    * @return O dado que se pretendia aceder
    */
    int getNumberOfAirportFlights(const string& airport);

    /**
    * @brief Função que devolve o número de companhias aereas de um aeroporto
    * Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
    * @param airport
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airline> getAirportAirlines(const string &airport);

    /**
    * @brief Função que devolve o diâmetro de um grafo (maior distância entre 2 nodes)
     * Complexidade Temporal: O(n * m) onde n é o número de nodes no grafo e m o número de edges.
    * @param wantedAirlines
    * @return O dado que se pretendia aceder
    */
    int getDiameter(const list<string> &wantedAirlines);

    /**
    * @brief Função que retorna todos os aeroportos possíveis de atingir só com um voo
    * Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
    * @param airport
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airport> getAirportsArrived(const string &airport);

    /**
    * @brief Função que retorna todas as cidades possíveis de atingir só com um voo
    * Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
    * @param airport
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getCitiesArrived(const string &airport);

    /**
    * @brief Função que retorna todos os paises possíveis de atingir só com um voo
    * Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
    * @param airport
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getCountriesArrived(const string &airport);

    /**
    * @brief Função que retorna todos os voos possíveis de atingir só com um voo
    * Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    * @param airportSrc
    * @param flights
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getPossibleFlightsCountries(const string &airportSrc, int flights);

    /**
    * @brief Devolve uma lista de cidades que consegue atingir com um determinado número de voos de um determinado aeroporto de origem
    * Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    * @param airportSrc
    * @param flights
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getPossibleFlightsCities(const string &airportSrc, int flights);

    /**
    * @brief Devolve uma lista de aeroportos que consegue atingir com um determinado número de voos de um determinado aeroporto de origem
    * Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    * @param airportSrc
    * @param flights
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airport> getPossibleFlightsAirports(const string &airportSrc, int flights);

    /**
    * @brief Devolve um vetor com os melhor números de aeroportos
    * Complexidade Temporal: O(n * log(n)) onde n é o número de nodes no grafo.
    * @param number
    * @param sortingWay
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<string> getTopNumberAirports(int number, string sortingWay);

    /**
    * @brief Função que ordena o vetor de paths por ordem crescente de tamanho e de distância de path
    * Complexidade temporal O(n), onde n é o tamanho do input das listas airportsA e airportsB
    * @param airportsA
    * @param airportsB
    * @return true se a distância em airportsA for menor que em airportsB, false caso contrário
    */
    bool conditionPaths(const list<Airport> &airportsA, const list<Airport> &airportsB);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma localização de origem para uma localização de destino
    * Complexidade temporal O(n * m), onde n é o número de nodes (aeroportos) e m o número de edges (voos). 
    * @param lat1
    * @param lon1
    * @param kmDistance1
    * @param lat2
    * @param lon2
    * @param kmDistance2
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathLocationToLocation(double lat1, double lon1, double kmDistance1, double lat2, double lon2, double kmDistance2, const list<string> &wantedAirlines);
    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um localização de origem para uma cidade de destino
    * Complexidade temporal O(n * m), onde n é o número de nodes (aeroportos) e m o número de edges (voos). 
    * @param lat
    * @param lon
    * @param kmDistance
    * @param city
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathLocationToCity(double lat, double lon, double kmDistance, const string &city, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma cidade de origem para uma localização de destino
    * Complexidade temporal O(n * m), onde n é o número de nodes (aeroportos) e m o número de edges (voos). 
    * @param city
    * @param lat
    * @param lon
    * @param kmDistance
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathCityToLocation(const string &city, double lat, double lon, double kmDistance, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma cidade de origem para uma cidade de destino
    * Complexidade temporal O(n * m), onde n é o número de nodes (aeroportos) e m o número de edges (voos). 
    * @param city1
    * @param city2
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathCityToCity(const string &city1, const string &city2, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma cidade de origem para um aeroporto de destino
    * Complexidade temporal O(n * m), onde n é o número de nodes (aeroportos) e m o número de edges (voos). 
    * @param city1
    * @param airportDest
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathCityToAir(const string &city1, const string &airportDest, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma localização de origem para uma aeroporto de destino
    * Complexidade temporal O(n * m), onde n é o número de nodes (aeroportos) e m o número de edges (voos). 
    * @param lat
    * @param lon
    * @param kmDistance
    * @param airportDest
    * @param wantedAirlines
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathLocationToAir(double lat, double lon, double kmDistance, const string &airportDest, const list<string> &wantedAirlines);

    list<Airline> getAllAirLinesFromCountry(const string &country);

    list<Airport> getAllAirportsFromCountry(const string &country);
};


#endif //AED_AIR_GESTOR_H
