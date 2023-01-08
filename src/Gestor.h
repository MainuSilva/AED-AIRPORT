
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
     * @details Complexidade Temporal: O(n) onde n é o número de linhas do ficheiro
     */
    void readAirports();
    
    /**
     * @brief Lê o ficheiro "Flights.csv"
     * @details Complexidade Temporal: O(n) onde n é o número de linhas do ficheiro
     */
    void readFlights();
    
    /**
     * @brief Lê o ficheiro "Airlines.csv"
     * @details Complexidade Temporal: O(n) onde n é o número de linhas do ficheiro
     */
    void readAirlines();

   /**
    * @brief Função que indica se o aeroporto existe ou não
    * @details Complexidade temporal O(1)
    *
    * @param airport
    * @return Devolve true se existir e false caso contrário
    */
    bool availableAirport(const string& airport);
    
    /**
    * @brief Função que indica se a cidade existe ou não
    * @details Complexidade temporal O(1)
    *
    * @param city
    * @return Devolve true se existir e false caso contrário
    */
    bool availableCity(const string& city);
    
    /**
    * @brief Função que indica se o país existe ou não
    * @details Complexidade temporal O(1)
    *
    * @param country
    * @return Devolve true se existir e false caso contrário
    */
    bool availableCountry(const string& country);
    
    /**
    * @brief Função que indica se a companhia aerea existe ou não
    * @details Complexidade temporal O(1)
    *
    * @param airline
    * @return Devolve true se existir e false caso contrário
    */
    bool availableAirline(const string& airline);
    
    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para um de destino
    * @details Complexidade Temporal: O(n + m + vlog(v)) no pior caso, onde n é o número de nodes no grafo e m o número de edges e v o comprimento do vetor path.
    *
    * @param airportSrc : aeroporto de origem
    * @param airportDest : aeroporto de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathTwoAirports(const string &airportSrc, const string &airportDest, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para uma cidade de destino
    * @details Complexidade Temporal: (n + m + k + vlog(v)) no pior caso, onde n é o número de nodes do grafo, m é o número de edges, k o número de aeroportos de destino e v o comprimento do vetor paths.
    *
    * @param airportSrc : aeroporto de origem
    * @param city
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathAirToCity(const string &airportSrc, const string &city, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para uma localização de destino
    * @details Complexidade Temporal: (n + m + k + vlog(v)) no pior caso, onde n é o número de nodes do grafo, m é o número de edges, k o número de aeroportos de destino e v o comprimento do vetor paths.
    *
    * @param airportSrc : aeroporto de origem
    * @param lat
    * @param lon
    * @param kmDistance : distância às coordenadas fornecidas de onde se pode encontrar o aeroporto de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathAirToLocation(const string &airportSrc, double lat, double lon, double kmDistance, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve os pontos de articulação do grafo
    * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    *
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Lista com os dados que se pretendia aceder
    */
    list<string> getArticulationPoints(const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve o número de companhias aereas de um aeroporto
    * @details Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
    *
    * @param airport
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airline> getAirportAirlines(const string &airport);

    /**
    * @brief Função que devolve o diâmetro de um grafo (maior distância entre 2 nodes)
    * @details Complexidade Temporal: O(n * (n + m)) onde n é o número de nodes no grafo e m o número de edges.
    *
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return O dado que se pretendia aceder
    */
    int getDiameter(const list<string> &wantedAirlines);

    /**
    * @brief Função que retorna todos os aeroportos possíveis de atingir só com um voo
    * @details Complexidade Temporal: O(n) onde n é o número de aeroportos adjacentes ao aeroporto especificado
    * @param airport
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airport> getAirportsArrived(const string &airport);

    /**
    * @brief Função que retorna todas as cidades possíveis de atingir só com um voo
    * @details Complexidade Temporal: O(n * log(n)) onde n é o número de aeroportos adjacentes ao aeroporto especificado.
    *
    * @param airport
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getCitiesArrived(const string &airport);

    /**
    * @brief Função que retorna todos os paises possíveis de atingir só com um voo
    * @details Complexidade Temporal: O(n * log(n)) onde n é o número de aeroportos adjacentes ao aeroporto especificado
    *
    * @param airport
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getCountriesArrived(const string &airport);

    /**
    * @brief Função que retorna todos os voos possíveis de atingir só com um voo
    * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    *
    * @param airportSrc : aeroporto de origem
    * @param flights
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getPossibleFlightsCountries(const string &airportSrc, int flights);

    /**
    * @brief Devolve uma lista de cidades que consegue atingir com um determinado número de voos de um determinado aeroporto de origem
    * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    *
    * @param airportSrc : aeroporto de origem
    * @param flights
    * @return Set com os dados que se pretendia aceder
    */
    set<string> getPossibleFlightsCities(const string &airportSrc, int flights);

    /**
    * @brief Devolve uma lista de aeroportos que consegue atingir com um determinado número de voos de um determinado aeroporto de origem
    * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
    *
    * @param airportSrc : aeroporto de origem
    * @param flights
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airport> getPossibleFlightsAirports(const string &airportSrc, int flights);

    /**
    * @brief Devolve um vetor com os melhor números de aeroportos
    * @details Complexidade Temporal: O(n * log(n)) onde n é o número de nodes no grafo.
    *
    * @param number
    * @param sortingWay : de que maneira devem ser ordenados os resultados
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<string> getTopNumberAirports(int number, string sortingWay);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma localização de origem para uma localização de destino
    * @details Complexidade temporal O(n + m + k1+ k2 + vlog(v)), onde n é o número de nodes (aeroportos) e m o número de edges (voos), k1 o número de aeroportos fonte, k2 o número de aeroportos destino e v o comprimento do vetor paths
    *
    * @param lat1 : Latitude do ponto do aeoporto de origem
    * @param lon1 : Longitude do ponto do aeoporto de origem
    * @param kmDistance1 : distância às coordenadas fornecidas de onde se pode encontrar o aeroporto de origem
    * @param lat2 : Latitude do ponto do aeoporto de destino
    * @param lon2 : Longitude do ponto do aeoporto de destino
    * @param kmDistance2 : distância às coordenadas fornecidas de onde se pode encontrar o aeroporto de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathLocationToLocation(double lat1, double lon1, double kmDistance1, double lat2, double lon2, double kmDistance2, const list<string> &wantedAirlines);
    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um localização de origem para uma cidade de destino
    * @details Complexidade temporal O(n + m + k1+ k2 + vlog(v)), onde n é o número de nodes (aeroportos) e m o número de edges (voos), k1 o número de aeroportos fonte, k2 o número de aeroportos destino e v o comprimento do vetor paths
    *
    * @param lat : Latitude do ponto do aeoporto de origem
    * @param lon : Longitude do ponto do aeoporto de origem
    * @param kmDistance : distância às coordenadas fornecidas de onde se pode encontrar o aeroporto de origem
    * @param city : cidade de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathLocationToCity(double lat, double lon, double kmDistance, const string &city, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma cidade de origem para uma localização de destino
    * @details Complexidade temporal O(n + m + k1+ k2 + vlog(v)), onde n é o número de nodes (aeroportos) e m o número de edges (voos), k1 o número de aeroportos fonte, k2 o número de aeroportos destino e v o comprimento do vetor paths
    *
    * @param city : cidade de origem
    * @param lat : Latitude do ponto do aeoporto de destino
    * @param lon : Longitude do ponto do aeoporto de destino
    * @param kmDistance : distância às coordenadas fornecidas de onde se pode encontrar o aeroporto de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathCityToLocation(const string &city, double lat, double lon, double kmDistance, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma cidade de origem para uma cidade de destino
    * @details Complexidade temporal O(n + m + k1+ k2 + vlog(v)), onde n é o número de nodes (aeroportos) e m o número de edges (voos), k1 o número de aeroportos fonte, k2 o número de aeroportos destino e v o comprimento do vetor paths
    *
    * @param city1 : cidade de origem
    * @param city2 : cidade de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathCityToCity(const string &city1, const string &city2, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma cidade de origem para um aeroporto de destino
    * @details Complexidade temporal O(n + m + k + vlog(v)), onde n é o número de nodes (aeroportos) e m o número de edges (voos), k o número de aeroportos fonte e v o comprimento do vetor paths.
    *
    * @param city1 : cidade de origem
    * @param airportDest : aeroporto de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathCityToAir(const string &city1, const string &airportDest, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de uma localização de origem para uma aeroporto de destino
    * @details Complexidade temporal O(n + m + k + vlog(v)), onde n é o número de nodes (aeroportos) e m o número de edges (voos), k o número de aeroportos fonte e v o comprimento do vetor paths.
    *
    * @param lat : Latitude do ponto do aeoporto de origem
    * @param lon : Longitude do ponto do aeoporto de origem
    * @param kmDistance : distância às coordenadas fornecidas de onde se pode encontrar o aeroporto de origem
    * @param airportDest : aeroporto de destino
    * @param wantedAirlines : lista com as companhias aereas escolhidas pelo utilizador
    * @return Vetor com os dados que se pretendia aceder
    */
    vector<list<Airport>> getMinPathLocationToAir(double lat, double lon, double kmDistance, const string &airportDest, const list<string> &wantedAirlines);

    /**
    * @brief Função que devolve uma lista com todas as companhias aereas possíveis de aceder a partir de um determinado país de origem
    * @details Complexidade temporal O(n), onde n é o número de companhias aéreas no grafo
    *
    * @param country
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airline> getAllAirLinesFromCountry(const string &country);

    /**
    * @brief Função que devolve uma lista com todos os aeroportos possíveis de aceder a partir de um determinado país de origem
    * @details Complexidade temporal O(n), onde n é o número de nós no grafo
    *
    * @param country
    * @return Lista com os dados que se pretendia aceder
    */
    list<Airport> getAllAirportsFromCountry(const string &country);

    /**
    * @brief Função que um inteiro que representa o número total de cidades
    * @details Complexidade Temporal: O(1)
    *
    * @return Um inteiro com o valor que se pretendia aceder (número total de cidades)
    */
    int getTotalNumberOfCities();

    /**
    * @brief Função que um inteiro que representa o número total de países
    * @details Complexidade Temporal: O(1)
    *
    * @return Um inteiro com o valor que se pretendia aceder (número total de países)
    */
    int getTotalNumberOfCountries();

    /**
    * @brief Função que um inteiro que representa o número total de voos
    * @details Complexidade Temporal: O(1)
    *
    * @return Um inteiro com o valor que se pretendia aceder (número total de voos)
    */
    int getTotalNumberOfFlights();

    /**
    * @brief Função que um inteiro que representa o número total de companhias aéreas
    * @details Complexidade Temporal: O(1)
    *
    * @return Um inteiro com o valor que se pretendia aceder (número total de companhias aéreas)
    */
    int getTotalNumberOfAirlines();

    /**
    * @brief Função que devolve lista dos pecursos com os aeroportos e as companhias aéreas com saída de um determinado aeroporto
    * @details Complexidade temporal O(n), onde n é o número de voos que partem do aeroporto especifico
    *
    * @param airport
    * @return Lista com os dados que se pretendia aceder
    */
    list<pair<string, string>> getDepartureBoard(const string &airport);

    /**
    * @brief Função que um inteiro que representa o número total de aeroportos
    * @details Complexidade Temporal: O(1)
    *
    * @return Um inteiro com o valor que se pretendia aceder (número total de aeroportos)
    */
    int getTotalNumberOfAirports();

    /**
    * @brief Função que devolve a distancia em Km de um percurso
    * @details Complexidade temporal O(n) onde n é o número de aeroportos na lista path
    *
    * @param path : lista de aeroportos de um percurso
    * @return Os dados que se pretendia aceder
    */
    int getPathDistance(const list<Airport> &path);


    /**
    * @brief Devolve o aeroporto a partir do codigo de aeroporto
    * @details Complexidade Temporal: O(1)
    * @param airport : airport code
     *
    * @return aeroporto
    */
    Airport getAirport(const string &airport);
};


#endif //AED_AIR_GESTOR_H
