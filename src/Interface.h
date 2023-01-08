
#ifndef AED_AIR_INTERFACE_H
#define AED_AIR_INTERFACE_H
#include "Airline.h"
#include "Airport.h"
#include "CoordDistance.h"
#include "Graph.h"
#include "Gestor.h"
#include <string>


/**
 * @brief Classe que funciona como interface
 */


class Interface {

private:
    /// Gestor das funcionalidades implementadas
    Gestor* gestor;

    /// Termina a execução do programa quando for true
    bool end_prog;

public:
    /**
     * @brief Constructor da Classe
     * @details Complexidade Temporal: O(1)
     */
    Interface();
    
    /**
     * @brief Função que cria uma interface para o menu inicial, com todas as opções de navegação associadas
     * @details Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada.
     */
    void showMenu();
    
    /**
     * @brief Função que verifica se o utilizador quer de facto sair após ter pressionado "E"
     * @details Complexidade Temporal: O(1)
     *
     * @return true se o utilizador pretender sair (pressionando Y) ou false se o utilizador pretender continuar a utilizar o programa (pressionando N)
     */
    bool verifyExit();

    /**
     * @brief Função que cria uma interface para o menu informação dos aeroportos
     * @details Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada.
     */
    void airportInfo();

    /**
     * @brief Função que cria uma interface para o menu informação dos voos
     * @details Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada.
     */
    void flightInfo();
    
    /**
     * @brief Função que indica as opções de voos para um aeroporto específico
     * @details Complexidade Temporal: O(1)
     */
    void goAirport();
    
    /**
     * @brief Função que indica as opções de voos para uma cidade específica
     * @details Complexidade Temporal: O(1)
     */
    void goCity();
    
    /**
     * @brief Função que devolve as coordenadas de um aeroporto
     * @details Complexidade Temporal: O(1)
     */
    void goCoords();

    /**
     * @brief Função que devolve os pontos de articulação do grafo
     * @details Complexidade Temporal: O(n + m) onde n é o número de nodes no grafo e m o número de edges.
     */
    void goArticulationP();

    /**
     * @brief Função que devolve o diametro do grafo
     * @details Complexidade Temporal: O(n * (n + m)) onde n é o número de nodes no grafo e m o número de edges.
     */
    void goDiameter();

    /**
     * @brief Função que cria uma interface para o menu de escolha de apresentação dos melhores aeroportos (mais voos ou mais airlines)
     * @details Complexidade Temporal: O(1)
     */
    void goTopAirports();

    /**
     * @brief Calcula os melhor números de aeroportos
     * @details Complexidade Temporal: O(n * log(n)) onde n é o número de nodes no grafo.
     */
    void goMostFlights();

    /**
     * @brief Calcula os melhor números de aeroportos
     * @details Complexidade Temporal: O(n * log(n)) onde n é o número de nodes no grafo.
     */
    void goMostAirlines();

    /**
     * @brief Função que pede e retorna uma lista com as airlines escolhidas pelo utilizador
     * @details Complexidade Temporal: O(1)
     *
     * @return Lista com os valores desejados
     */
    list<string> airlines_select();

    /**
     * @brief Função que imprime as cidades de destino do aeroporto escolhido pelo utilizador
     * @details Complexidade Temporal: O(n * log(n)) onde n é o número de aeroportos adjacentes ao aeroporto especificado.
     *
     * @param airport
     */
    void cityList(const string& airport);

    /**
     * @brief Função que imprime as companhias aereas do aeroporto escolhido pelo utilizador
     * @details Complexidade Temporal: O(n) onde n é o número de nodes no grafo.
     *
     * @param airport
     */
    void airlinesList(const string& airport);

    /**
     * @brief Função que retorna as companhias aereas de um pais
     * @details Complexidade Temporal: O(n), onde n é o número de companhias aéreas
     *
     * @param country
     */
    void airlinesListCountry(const string& country);

    /**
     * @brief Função que retorna todos os paises possíveis de atingir só com um voo
     * @details Complexidade Temporal: O(n * log(n)) onde n é o número de aeroportos adjacentes ao aeroporto especificado
     *
     * @param airport
     */
    void countriesList(const string& airport);

    /**
     * @brief Função que retorna todos os aeroportos possíveis de atingir só com um voo
     * @details Complexidade Temporal: O(n) onde n é o número de aeroportos adjacentes ao aeroporto especificado
     *
     * @param airport
     */
    void airportsList(const string& airport);

    /**
     * @brief Função que calcula todos os aeroportos possíveis de aceder a partir de um determinado país de origem
     * @details Complexidade temporal O(n), onde n é o número de nós no grafo
     *
     * @param country
     */
    void AirportsNumCountry(string country);

    /**
     * @brief Função permite que o utilizador insira o código de várias companhias aereas e armazena-as numa lista
     * @details Complexidade Temporal: O(n), onde n é o número de companhias aereas escritas pelo utilizador
     *
     * @return Lista com os valores desejados
     */
    list<string> getAirlines();

    /**
     * @brief Função que retorna o número de voos
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado
     */
    int getNum();

    /**
     * @brief Função que permite ao utilizador voltar ao menu anterior
     * @details Complexidade Temporal: O(1)
     */
    static void wait_B();
    
    /**
     * @brief Função que retorna os dados de um aeroporto
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado
     */
    string getAirport();
    
    /**
     * @brief Função que retorna os dados de uma cidade
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado
     */
    string getCity();
    
    /**
     * @brief Função que retorna a latitude de um aeroporto
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado (latitude de um aeroporto)
     */
    double getLat();
    
    /**
     * @brief Função que retorna a longitude de um aeroporto
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado (longitude de um aeroporto)
     */
    double getLong();


    /**
     * @brief Função que retorna os dados de um país
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor desejado
     */
    string getCountry();

    /**
     * @brief Função que calcula uma lista de paises, cidades e aeroportos que dá para alcançar de um aeroporto com k voos
     * @details Complexidade Temporal: O((n + m) * 3) onde n é o número de nodes no grafo e m o número de edges
     *
     * @param airport
     */
    void airportReach(const string& airport);

    /**
     * @brief Função que devolve ao utilizador um menu de opções com estatísticas que poderão ser interessantes para o utilizador
     * @details Complexidade Temporal: O(1)
     */
    void networkInfo();

    /**
     * @brief Função que devolve ao utilizador um menu de opções com informações sobre um país à escolha do utilizador
     * @details Complexidade Temporal: O(1)
     */
    void countryInfo();

    /**
     * @brief Função que devolve ao utilizador um menu de escolha sobre que tipo de voos que processar
     * @details Complexidade Temporal: O(1)
     *
     * @return O valor correspondente a esse tipo de voo
     */
    int fromWhere();

    /**
     * @brief Função que pelde ao utilizador uma desterminda distância em km às coordenadas que selecionou anteriormente
     * @details Complexidade Temporal: O(1)
     */
    double getDistance();

    /**
     * @brief Função que devolve o número de aeroportos cobertos pelo progrma
     * @details Complexidade Temporal: O(1)
     */
    void goTotalAirports();

    /**
     * @brief Função que devolve o número de voos cobertos pelo progrma
     * @details Complexidade Temporal: O(1)
     */
    void goTotalFlights();

    /**
     * @brief Função que devolve o número de airlines cobertos pelo progrma
     * @details Complexidade Temporal: O(1)
     */
    void goTotalAirlines();

    /**
     * @brief Função que devolve o número de cidades cobertos pelo progrma
     * @details Complexidade Temporal: O(1)
     */
    void goTotalCities();

    /**
     * @brief Função que devolve o número de países cobertos pelo progrma
     * @details Complexidade Temporal: O(1)
     */
    void goTotalCountries();

    /**
     * @brief Função que devolve o placar de voos
     * @details Complexidade Temporal: O(n), onde n é o número de voos no flight Board
     *
     * @param airport
     */
    void flightBoard(const string &airport);
};


#endif //AED_AIR_INTERFACE_H
