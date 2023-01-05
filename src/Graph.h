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
        ///Lista com todas os edges adjacentes
        list<Edge> adj; 
        ///set com todas as companhias aerias
        set<string> allAirlines;
        ///Node visitado ou por visitar
        bool visited;
        ///Node está ou não contido na stack
        bool inStack;
        ///
        bool inArt;
        ///distancia a um determinado node
        int distance;
        ///indica a ordem pela qual o node é visitado
        int num;
        ///o node mais antigo que consegue alcansar
        int low;
        ///
        string pred;
    };

    ///Hash Table que guarda todos os nodes
    unordered_map<string, Node> nodes;
    
    ///Hash Table que guarda todas as companhias aerias
    unordered_map<string, Airline> airlines;

    ///reinicia o estado de cada node
    void restart();

    /// Breadth-First Search
    void bfs(const string& v );

    /// Devolve o diametro do bfs: A maior distância entre 2 nodes do bfs
    int bfsDiameter(const string &v, const list<string> &wantedAirlines);

    /// Adiciona os pontos de articulação no result
    void dfsArticulations(const string& v, stack<string> &s, const list<string> &wantedAirlines, list<string> &result, int index);

    /// Verifica se as duas listas têm companhias aericas em comum
    bool hasCommonAirlines(const list<string> &airlines1, const list<string> &airlines2);

    /// Constroi um caminho entre dois aeroportos, colocando-os numa lista de aeroportos
    list<Airport> constructPath(string curr, const string& airportSrc);

public:
    /**
     * @brief Construtor do grafo. Direção default: undirected
     */
    Graph();

    /**
     * @brief Adiciona um novo node (aeroporto)
     * Complexidade Temporal: O(1)
     * @param airport
     */
    void addNode(const Airport &airport);

    /**
     * @brief Adiciona uma nova edge de uma origem a um destinho com um determinado peso
     * Complexidade Temporal: O(n) no pior caso e O(1) no melhor caso
     * @param src
     * @param dest
     * @param airline
     */
    void addEdge(const string& src, const string& dest, const string& airline);
    
    /**
     * @brief Devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de rigem para um destino
     * Complexidade Temporal: O(n + m) no pior caso, onde n é o número de nodes no grafo e m o número de edges.
     * @param airportSrc
     * @param airportDest
     * @param airlines
     */
    vector<list<struct Airport>> findMinPathsBfs(const string &airportSrc, const string &airportDest, const list<string> &airlines);

    /**
     * @brief Devolve um vetor com uma lista do menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de rigem para um destino
     * Complexidade Temporal: (n * m * k) no pior caso, onde n é o número de nodes do grafo, m é o número de edges e k o número de aeroportos de destino.
     * @param airportSrc
     * @param wantedAirports
     * @param wantedAirlines
     */
    vector<list<struct Airport>> getMinPathsAirportsBfs(const string &airportSrc, const list<string> &wantedAirports, const list<string> &wantedAirlines);

<<<<<<< HEAD
    vector<list<Airport>> getMinPathsLocationsBfs(const list<string>& airportSrcs, const list<string>& wantedAirports , const list<string>& wantedAirlines);

    vector<list<Airport>> getMinPathsLocationToAirportBfs(const list<string>& airportSrcs, const string& airportDest, const list<string>& wantedAirlines);

=======
    /**
     * @brief Devolve a distancia de um percurso
     * Complexidade Temporal: O(n)
     * @param airports
     */
>>>>>>> 3aced4f62840c534da28d235f74725407b67ac11
    int pathDistance(list<Airport> airports);

    /**
     * @brief Determina os aeroportos a Xkm de uma determinada coordenada
     * Complexidade Temporal: O(n)
     * @param lat
     * @param lon
     * @param kmdistance
     */
    list<string> getLocationAirports(double lat, double lon , double kmdistance);

    /**
     * @brief Obtem uma lista de aeroportos de uma cidade
     * Complexidade Temporal: O(n)
     * @param city
     */
    list<string> getCityAirports(const string& city);

    /**
     * @brief Devolve os pontos de articulação
     * Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     * @param wantedAirlines
     */
    list<string> getArticulationPoints(const list<string> &wantedAirlines);

<<<<<<< HEAD
    vector<string> getTopAirports(int number, string sortingWay);
=======
    /**
     * @brief Obtem o melhor número de aeroportos
     * Complexidade Temporal: O(n * log(n)) onde n é o número de nodes no grafo.
     * @param number
     */
    vector<string> getTopAirports(int number);
>>>>>>> 3aced4f62840c534da28d235f74725407b67ac11

    /**
     * @brief Devolve uma lista de aeroportos que consegue atingir com um determinado número de voos
     * Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     * @param airportSrc
     * @param flights
     */
    list<Airport> getPossibleFlightsAirports(const string &airportSrc, int flights);

    /**
     * @brief Devolve o número de voos
     * Complexidade Temporal: O(1)
     * @param airport
     */
    int getNumberOfFlights(const string &airport);

    /**
     * @brief Adiciona uma nova companhia aerea à lista de companhias aereas
     * Complexidade Temporal: O(1)
     * @param airline
     */
    void addAirline(const Airline &airline);

    /**
     * @brief Devolve os aeroportos que aterraram
     * Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
     * @param airport
     */
    list<Airport> getAirportsArrived(const string &airport);

    /**
     * @brief Devolve as companhias aereas de um aeroporto
     * Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
     * @param airport
     */
    list<Airline> getAirportAirlines(const string &airport);

    /**
     * @brief Devolve o diametro de um grafo (a maior distânica entre dois nodes)
     * Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     * @param wantedAirlines
     */
    int getDiameter(const list<string> &wantedAirlines);

    /**
     * @brief Devolve o número de Companhias Aereas
     * Complexidade Temporal: O(1)
     */
    int getTotalNumberOfAirlines();

    /**
     * @brief Devolve o número de Aeroportos
     * Complexidade Temporal: O(1)
     */
    int getTotalNumberOfAirports();

    /**
     * @brief Devolve o número de Voos
     * Complexidade Temporal: O(1)
     */
    int getTotalNumberOfFlights();

    /**
     * @brief Devolve  true no caso de existir uma determinada companhia aerea disponível e false caso contrário
     * Complexidade Temporal: O(1)
     * @param airline
     */
    bool availableAirline(const string &airline);

    /**
     * @brief Devolve  true no caso de existir um determinado aeroporto disponível e false caso contrário
     * Complexidade Temporal: O(1)
     * @param airport
     */
    bool availableAirport(const string &airport);

};

#endif //AED_AIR_GRAPH_H
