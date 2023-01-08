
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
<<<<<<< HEAD
       O loop 'while(true)' será sempre executado apenas uma vez porque as condições desse loop são sempre verdadeiras.
=======
     *
>>>>>>> a6575d2c172b95ee9eeea43995eaeb1d267160b0
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

    void goArticulationP();
    void goDiameter();
    void goTopAirports();
    void goMostFlights();
    void goMostAirlines();
    list<string> airlines_select();
    void cityList(const string& airport);
    void airlinesList(const string& airport);
    void airlinesListCountry(const string& country);
    void countriesList(const string& airport);
    void airportsList(const string& airport);
    void AirportsNumCountry(string country);
    list<string> getAirlines();
    int getNum();

    /**
     * @brief Função que permite ao utilizador voltar ao menu anterior
     * @details Complexidade Temporal: O(1)
     */
    static void wait_B();
    
    /**
     * @brief Função que retorna os dados de um aeroporto
     * @details Complexidade Temporal: O(1)
     */
    string getAirport();
    
    /**
     * @brief Função que retorna os dados de uma cidade
     * @details Complexidade Temporal: O(1)
     */
    string getCity();
    
    /**
     * @brief Função que retorna a latitude de um aeroporto
     * @details Complexidade Temporal: O(1)
     */
    double getLat();
    
    /**
     * @brief Função que retorna a longitude de um aeroporto
     * @details Complexidade Temporal: O(1)
     */
    double getLong();


    /**
<<<<<<< HEAD
   * @brief Função que retorna os dados de um país
   * @details Complexidade Temporal: O(1)
   */
=======
     * @brief Função que retorna os dados de um país
     * @details Complexidade Temporal: O(1)
     */
>>>>>>> a6575d2c172b95ee9eeea43995eaeb1d267160b0
    string getCountry();

    /**
     * @brief Função que calcula uma lista de paises, cidades e aeroportos que dá para alcançar de um aeroporto com k voos
     * @details Complexidade Temporal: O((n + m) * 3) onde n é o número de nodes no grafo e m o número de edges
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
     */
    void flightBoard(const string &airport);
};


#endif //AED_AIR_INTERFACE_H
