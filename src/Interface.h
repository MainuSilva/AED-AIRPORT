//
// Created by manue on 30/12/2022.
//

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
     * Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada. 
     */
    void showMenu();
    
    /**
     * @brief Função que verifica se o utilizador quer de facto sair após ter pressionado "E"
     * Complexidade Temporal: O(1)
       O loop 'while(true)' será sempre executado apenas uma vez porque as condições desse loop são sempre verdadeiras.
     * @return true se o utilizador pretender sair (pressionando Y) ou false se o utilizador pretender continuar a utilizar o programa (pressionando N)
     */
    bool verifyExit();
    
    /**
     * @brief Função que 
     * Complexidade Temporal: O(1)
     */
    void airport_ask();
    
    /**
     * @brief Função que cria uma interface para o menu informação dos aeroportos
     * Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada. 
     */
    void airport_Info();
    
    /**
     * @brief Função que cria uma interface para o menu informação dos voos
     * Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada. 
     */
    void flight_info();
    
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
    
    /**
     * @brief Função que imprime um painel com os voos
     * Complexidade Temporal: O(1)
     */
    void departuresBoard();
    
    /**
     * @brief Função que 
     * Complexidade Temporal: O(1). Isto porque a função realiza um número constante de operações, independentemente do tamanho da entrada. 
     */
    void airlines_Info();
    
    /**
     * @brief Função que 
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void destinationsList();
    
    /**
     * @brief Função que retorna as diferentes cidades
     * Complexidade Temporal: O(1) 
     */
    void airlinesList();
    
    /**
     * @brief Função que os diferentes países
     * Complexidade Temporal: O(1) 
     */
    void countriesList();
    
    /**
     * @brief Função que apresenta o menu de seleção dos voos
     * Complexidade Temporal: O(1)
     */
    void flights();
    
    /**
     * @brief Função que imprime o número de voos
     * Complexidade Temporal: O(1)
     */
    void flightsNum();
    
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
    static double getLat();
    
    /**
     * @brief Função que retorna a longitude de um aeroporto
     * Complexidade Temporal: O(1)
     */
    static double getLong();
    
    /**
     * @brief Função que 
     * Complexidade Temporal: O(1)
     */
    void airlineTravel();
    
    /**
     * @brief Função que 
     * Complexidade Temporal: O(1)
     */
    void anyTravel();
    
    /**
     * @brief Função que retorna os aeroportos que o utilizador pode alcançar através de um certo número de voos
     * Complexidade Temporal: O(1)
     */
    void airportReach();
    
    /**
     * @brief Função que retorna os dados de um país
     * Complexidade Temporal: O(1)
     */
    string getCountry();
};


#endif //AED_AIR_INTERFACE_H
