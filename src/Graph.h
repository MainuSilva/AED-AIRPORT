#ifndef AED_AIR_GRAPH_H
#define AED_AIR_GRAPH_H

#include "Airport.h"
#include "Airline.h"

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

/**
 * @brief Classe de comandos dos grafos
 */

class Graph {
private:
    struct Edge {
        /// Node de destino
        string destination;
        /// Lista das companhias aerias
        list<string> airlines;
    };

    struct Node {
        ///Aeroporto
        Airport airport;
        /// Lista com todas os edges adjacentes
        list<Edge> adj; 
        /// Set com todas as companhias aerias
        set<string> allAirlines;
        /// Node visitado ou por visitar
        bool visited;
        /// Node está ou não contido na stack
        bool inStack;
        /// Node é ou não uma articulação
        bool inArt;
        /// Distancia a um determinado node
        int distance;
        /// Indica a ordem pela qual o node é visitado
        int num;
        /// O node de ordem mais pequena que este node consegue alcançar
        int low;
        /// O node visitado anteriormente
        string pred;
    };

    /// Hash Table que guarda todos os nodes
    unordered_map<string, Node> nodes;
    
    /// Hash Table que guarda todas as companhias aerias
    unordered_map<string, Airline> airlines;

    /// Reinicia o estado de cada node
    void restart();

    /// Breadth-First Search
    void bfs(const string& v );

    /// Devolve o diametro do bfs: A maior distância entre 2 nodes do bfs
    int bfsDiameter(const string &v, const list<string> &wantedAirlines);

    /// Adiciona os pontos de articulação no result
    void dfsArticulations(const string& v, stack<string> &s, const list<string> &wantedAirlines, list<string> &result, int index);

    /// Verifica se as duas listas têm companhias aerias em comum
    bool hasCommonAirlines(const list<string> &airlines1, const list<string> &airlines2);

    /// Constroi um caminho entre dois aeroportos, colocando-os numa lista de aeroportos
    list<Airport> constructPath(string curr);

public:
    /**
     * @brief Construtor do grafo. Direção default: undirected
     */
    Graph();

    /**
     * @brief Adiciona um novo node ao grafo (aeroporto)
     * @details Complexidade Temporal: O(1)
     *
     * @param airport
     */
    void addNode(const Airport &airport);

    /**
     * @brief Adiciona uma nova companhia aerea à lista de companhias aereas
     * @details Complexidade Temporal: O(1)
     *
     * @param airline
     */
    void addAirline(const Airline &airline);

    /**
     * @brief Adiciona uma nova edge de uma origem a um destino com uma lista de airlines, se a edge já existe adiciona a nova airline na lista de airlines
     * @details Complexidade Temporal: O(n) no pior caso e O(1) no melhor caso
     *
     * @param src
     * @param dest
     * @param airline
     */
    void addEdge(const string& src, const string& dest, const string& airline);
    
    /**
     * @brief Devolve um vetor de listas com o menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para um destino, com um determinado conjunto de airlines
     * @details Complexidade Temporal: O(n + m) no pior caso, onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param airportSrc
     * @param airportDest
     * @param airlines
     */
    vector<list<struct Airport>> findMinPathsAirportsBfs(const string &airportSrc, const string &airportDest, const list<string> &airlines);


    vector<list<struct Airport>> findMinPathsAirToLocationBfs(const string &airportSrc, const list<string> &wantedAirports, const list<string> &wantedAirlines);

    vector<list<Airport>> findMinPathsLocationsBfs(const list<string>& airportSrcs, const list<string>& wantedAirports , const list<string>& wantedAirlines);

    vector<list<Airport>> findMinPathsLocationToAirBfs(const list<string>& airportSrcs, const string& airportDest, const list<string>& wantedAirlines);

    /**
     * @brief Devolve a distancia em Km de um percurso
     * @details Complexidade Temporal: O(n)
     *
     * @param airports
     */
    int pathDistance(list<Airport> airports);

    /**
     * @brief Determina os aeroportos a Xkm de uma determinada coordenada
     * @details Complexidade Temporal: O(n)
     *
     * @param lat
     * @param lon
     * @param kmdistance
     */
    list<string> getLocationAirports(double lat, double lon , double kmdistance);

    /**
     * @brief Obtem uma lista de aeroportos de uma cidade
     * @details Complexidade Temporal: O(n)
     *
     * @param city
     */
    list<string> getCityAirports(const string& city);

    /**
     * @brief Devolve os pontos de articulação para um determinado conjunto de airlines
     * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param wantedAirlines
     */
    list<string> getArticulationPoints(const list<string> &wantedAirlines);

    vector<string> getTopAirports(int number, string sortingWay);


    /**
     * @brief Devolve uma lista de aeroportos que consegue atingir com um determinado número de voos
     * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param airportSrc
     * @param flights
     */
    list<Airport> getPossibleFlightsAirports(const string &airportSrc, int flights);

    /**
     * @brief Devolve o número de voos de um determinado aeroporto
     * @details Complexidade Temporal: O(1)
     *
     * @param airport
     */
    int getNumberOfFlights(const string &airport);

    /**
     * @brief Devolve uma lista de aeroportos possíveis de aterrar através de um determinado aeroporto
     * @details Complexidade Temporal: O(n) onde n é o número de edges do node.
     *
     * @param airport
     */
    list<Airport> getAirportsArrived(const string &airport);

    /**
     * @brief Devolve todas as companhias aereas de um aeroporto
     * @details Complexidade Temporal: O(n) onde n é o número de elementos do set de airlines.
     *
     * @param airport
     */
    list<Airline> getAirportAirlines(const string &airport);

    /**
     * @brief Devolve o diametro de um grafo (a maior distânica entre dois nodes), para um determinado conjunto de airlines
     * @details Complexidade Temporal: O(n * m) onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param wantedAirlines
     */
    int getDiameter(const list<string> &wantedAirlines);

    /**
     * @brief Devolve o número total de Companhias Aereas da Rede
     * @details Complexidade Temporal: O(1)
     */
    int getTotalNumberOfAirlines();

    /**
     * @brief Devolve o número total de Aeroportos da Rede
     * @details Complexidade Temporal: O(1)
     */
    int getTotalNumberOfAirports();

    /**
     * @brief Devolve o número total de Voos da Rede
     * @details Complexidade Temporal: O(1)
     */
    int getTotalNumberOfFlights();

    /**
     * @brief Devolve true no caso de existir uma determinada companhia aerea existir e false caso contrário
     * @details Complexidade Temporal: O(1)
     *
     * @param airline
     */
    bool availableAirline(const string &airline);

    /**
     * @brief Devolve  true no caso de um determinado aeroporto existir e false caso contrário
     * @details Complexidade Temporal: O(1)
     *
     * @param airport
     */
    bool availableAirport(const string &airport);

    list<Airline> getAirlinesFromCountry(const string &country);

    list<Airport> getAirportsFromCountry(const string &country);

    list<pair<string, string>> getDepartureBoard(const string &airport);
};

#endif //AED_AIR_GRAPH_H
