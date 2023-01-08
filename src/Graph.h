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

    /**
     * @brief Função que reinicia o estado de cada node
     * @details Complexidade Temporal: O(n), onde n é o número de nodes do grafo
     */
    void restart();

    /**
     * @brief Breadth-First Search
     * @details Complexidade Temporal: O(n + m), onde n é o número de nodes do grafo e m o número de edges
     *
     * @param v
     */
    void bfs(const string& v);

    /**
     * @brief Função que devolve o diametro do bfs: A maior distância entre 2 nodes do bfs
     * @details Complexidade Temporal: O(n + m), onde n é o número de nodes do grafo e m o número de edges
     *
     * @param wantedAirlines
     */
    int bfsDiameter(const string &v, const list<string> &wantedAirlines);

    /**
     * @brief Função que adiciona os pontos de articulação no result
     * @details Complexidade Temporal: O(n + m), onde n é o número de nodes do grafo e m o número de edges
     *
     * @param v
     * @param s
     * @param wantedAirlines
     * @param result
     * @param index
     */
    void dfsArticulations(const string& v, stack<string> &s, const list<string> &wantedAirlines, list<string> &result, int index);

    /**
     * @brief Função que verifica se as duas listas têm companhias aerias em comum
     * @details Complexidade Temporal: O(n + m), onde n é o número de nodes do grafo e m o número de edges
     *
     * @param airport
     * @return  true no caso de duas listas terem companhias aerias em comum e false caso contrário
     */
    bool hasCommonAirlines(const list<string> &airlines1, const list<string> &airlines2);

    /**
     * @brief Função que Constroi um caminho entre dois aeroportos, colocando-os numa lista de aeroportos
     * @details Complexidade Temporal: O(n), onde n é o número de nodes do grafo
     *
     * @param airport
     */
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
     * @return Vetor com os valores desejados (listas com o menor número de aeroportos pelos quais é necessário passar para ir de um aeroporto de origem para um destino, com um determinado conjunto de airlines)
     */
    vector<list<struct Airport>> findMinPathsAirportsBfs(const string &airportSrc, const string &airportDest, const list<string> &airlines);

    /**
     * @brief Função que devolve o(s) menor(es) caminho(s) possíveis entre um aeroporto e uma localização
     * @details Complexidade Temporal: O(n + m) no pior caso, onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param airportSrc
     * @param wantedAirports
     * @param wantedAirlines
     * @return Vetor com os valores desejados (o(s) menor(es) caminho(s) possíveis entre um aeroporto e uma localização)
     */
    vector<list<struct Airport>> findMinPathsAirToLocationBfs(const string &airportSrc, const list<string> &wantedAirports, const list<string> &wantedAirlines);

    /**
     * @brief Função que devolve o(s) menor(es) caminho(s) possíveis entre duas localizações
     * @details Complexidade Temporal: O(n + m) no pior caso, onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param airportSrcs
     * @param wantedAirports
     * @param wantedAirlines
     * @return Vetor com os valores desejados (o(s) menor(es) caminho(s) possíveis entre duas localizações)
     */
    vector<list<Airport>> findMinPathsLocationsBfs(const list<string>& airportSrcs, const list<string>& wantedAirports , const list<string>& wantedAirlines);

    /**
     * @brief Função que devolve o(s) menor(es) caminho(s) possíveis entre uma localizalição e um aeroporto
     * @details Complexidade Temporal: O(n + m) no pior caso, onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param airportSrcs
     * @param airportDest
     * @param wantedAirlines
     * @return Vetor com os valores desejados (o(s) menor(es) caminho(s) possíveis entre uma localizalição e um aeroporto)
     */
    vector<list<Airport>> findMinPathsLocationToAirBfs(const list<string>& airportSrcs, const string& airportDest, const list<string>& wantedAirlines);

    /**
     * @brief Devolve a distancia em Km de um percurso
     * @details Complexidade Temporal: O(n)
     *
     * @param airports
     * @return O valor desejado (distancia em Km de um percurso)
     */
    int pathDistance(list<Airport> airports);

    /**
     * @brief Determina os aeroportos a Xkm de uma determinada coordenada
     * @details Complexidade Temporal: O(n)
     *
     * @param lat
     * @param lon
     * @param kmdistance
     * @return Lista com os valores desejados (os aeroportos a Xkm de uma determinada coordenada)
     */
    list<string> getLocationAirports(double lat, double lon , double kmdistance);

    /**
     * @brief Obtem uma lista de aeroportos de uma cidade
     * @details Complexidade Temporal: O(n)
     *
     * @param city
     * @return Lista com os valores desejados (aeroportos de uma cidade)
     */
    list<string> getCityAirports(const string& city);

    /**
     * @brief Devolve os pontos de articulação para um determinado conjunto de airlines
     * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param wantedAirlines
     * @return Lista com os valores desejados (pontos de articulação para um determinado conjunto de airlines)
     */
    list<string> getArticulationPoints(const list<string> &wantedAirlines);

    /**
     * @brief Função que devolve o melhor número de aeroportos
     * @details Complexidade Temporal: O(n log n) onde n é o número de nodes no grafo
     *
     * @param airportSrcs
     * @param airportDest
     * @param wantedAirlines
     * @return Vetor com os valores desejados (o melhor número de aeroportos)
     */
    vector<string> getTopAirports(int number, string sortingWay);

    /**
     * @brief Devolve uma lista de aeroportos que consegue atingir com um determinado número de voos
     * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param airportSrc
     * @param flights
     * @return Lista com os valores desejados (aeroportos que consegue atingir com um determinado número de voos)
     */
    list<Airport> getPossibleFlightsAirports(const string &airportSrc, int flights);

    /**
     * @brief Devolve uma lista de aeroportos possíveis de aterrar através de um determinado aeroporto
     * @details Complexidade Temporal: O(n) onde n é o número de edges do node.
     *
     * @param airport
     * @return Lista com os valores desejados (aeroportos possíveis de aterrar através de um determinado aeroporto)
     */
    list<Airport> getAirportsArrived(const string &airport);

    /**
     * @brief Devolve todas as companhias aereas de um aeroporto
     * @details Complexidade Temporal: O(n) onde n é o número de elementos do set de airlines.
     *
     * @param airport
     * @return Lista com os valores desejados (todas as companhias aereas de um aeroporto)
     */
    list<Airline> getAirportAirlines(const string &airport);

    /**
     * @brief Devolve o diametro de um grafo (a maior distânica entre dois nodes), para um determinado conjunto de airlines
     * @details Complexidade Temporal: O(n * m) onde n é o número de nodes no grafo e m o número de edges.
     *
     * @param wantedAirlines
     * @return O valor desejado (diametro de um grafo para um determinado conjunto de airlines)
     */
    int getDiameter(const list<string> &wantedAirlines);

    /**
     * @brief Devolve o número total de Companhias Aereas da Rede
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado (número total de Companhias Aereas da Rede)
     */
    int getTotalNumberOfAirlines();

    /**
     * @brief Devolve o número total de Aeroportos da Rede
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado (número total de Aeroportos da Rede)
     */
    int getTotalNumberOfAirports();

    /**
     * @brief Devolve o número total de Voos da Rede
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado (número total de Voos da Rede)
     */
    int getTotalNumberOfFlights();

    /**
     * @brief Função que indica se existe ou não uma determinada companhia aerea 
     * @details Complexidade Temporal: O(1)
     *
     * @param airline
     * @return true no caso de existir uma determinada companhia aerea existir e false caso contrário
     */
    bool availableAirline(const string &airline);

    /**
     * @brief Função que indica se existe ou não um determinado aeroporto
     * @details Complexidade Temporal: O(1)
     *
     * @param airport
     * @return  true no caso de um determinado aeroporto existir e false caso contrário
     */
    bool availableAirport(const string &airport);

    /**
     * @brief Função que devolve uma lista com todas as companhias aereas possíveis de aceder a partir de um determinado país de origem
     * @details Complexidade temporal O(n), onde n é o número de companhias aéreas no grafo
     *
     * @param country
     * @return Lista com os valores desejados (todas as companhias aereas de um aeroporto)
     */
    list<Airline> getAirlinesFromCountry(const string &country);
    
    /**
     * @brief Função que devolve uma lista com todos os aeroportos possíveis de aceder a partir de um determinado país de origem
     * @details Complexidade temporal O(n), onde n é o número de nós no grafo
     *
     * @param country
     * @return Lista com os valores desejados (todas as companhias aereas de um aeroporto)
     */
    list<Airport> getAirportsFromCountry(const string &country);

    /**
     * @brief Função que devolve lista dos pecursos com os aeroportos e as companhias aéreas com saída de um determinado aeroporto
     * @details Complexidade temporal O(n), onde n é o número de voos que partem do aeroporto especifico
     *
     * @param airport
     * @return Lista com os valores desejados (todas as companhias aereas de um aeroporto)
     */
    list<pair<string, string>> getDepartureBoard(const string &airport);
};

#endif //AED_AIR_GRAPH_H
