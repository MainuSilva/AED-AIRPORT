
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
     * Complexidade Temporal: O(1)
     */
    Interface();
    
    /**
     * @brief Função que cria uma interface para o menu inicial, com todas as opções de navegação associadas
     * @details Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada.
     */
    void showMenu();
    
    /**
     * @brief Função que verifica se o utilizador quer de facto sair após ter pressionado "E"
     * Complexidade Temporal: O(1)
       O loop 'while(true)' será sempre executado apenas uma vez porque as condições desse loop são sempre verdadeiras.
     * @return true se o utilizador pretender sair (pressionando Y) ou false se o utilizador pretender continuar a utilizar o programa (pressionando N)
     */
    bool verifyExit();


    void airportInfo();

    /**
     * @brief Função que cria uma interface para o menu informação dos voos
     * Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada. 
     */
    void flightInfo();
    
    /**
     * @brief Função que indica as opções de voos para um aeroporto específico
     * Complexidade Temporal: O(1)
     */
    void goAirport();
    
    /**
     * @brief Função que indica as opções de voos para uma cidade específica
     * Complexidade Temporal: O(1)
     */
    void goCity();
    
    /**
     * @brief Função que devolve as coordenadas de um aeroporto
     * Complexidade Temporal: O(1)
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
     * Complexidade Temporal: O(1)
     */
    static void wait_B();
    
    /**
     * @brief Função que retorna os dados de um aeroporto
     * Complexidade Temporal: O(1)
     */
    string getAirport();
    
    /**
     * @brief Função que retorna os dados de uma cidade
     * Complexidade Temporal: O(1)
     */
    string getCity();
    
    /**
     * @brief Função que retorna a latitude de um aeroporto
     * Complexidade Temporal: O(1)
     */
    double getLat();
    
    /**
     * @brief Função que retorna a longitude de um aeroporto
     * Complexidade Temporal: O(1)
     */
    double getLong();


    /**
   * @brief Função que retorna os dados de um país
   * Complexidade Temporal: O(1)
   */
    string getCountry();


    void airportReach(const string& airport);

    void networkInfo();

    void countryInfo();

    int fromWhere();

    double getDistance();

    void goTotalAirports();

    void goTotalFlights();

    void goTotalAirlines();

    void goTotalCities();

    void goTotalCountries();

    void flightBoard(const string &airport);
};


#endif //AED_AIR_INTERFACE_H
