//
// Created by manue on 28/12/2022.
//

#ifndef AED_AIR_AIRPORT_H
#define AED_AIR_AIRPORT_H

#include <string>

using namespace std;

/**
 * @brief Classe que representa um aeroporto
 */

class Airport {
private:
    /// Código do aeroporto
    string code;

    /// Nome do aeroporto
    string name;

    /// Cidade do aeroporto
    string city;

    /// País do aeroporto
    string country;

    /// Coordenadas do aeroporto : latitude
    double latitude;

    /// Coordenadas do aeroporto : longitude
    double longitude;

public:
    /**
    * @brief Construtor Default
    */
    Airport();

    /**
    * @brief Função que cria um novo objeto 'Airport' com os valores especificados para os seus campos
    * Complexidade temporal O(1)
    * @param code
    * @param name
    * @param city
    * @param country
    * @param latitude
    * @param longitude
    */
    Airport(string code, string name, string city, string country, double latitude, double longitude);

    /**
    * @brief Função que retorna o código do aeroporto
    * Complexidade temporal O(1)
    * @return O valor desejado (código do aeroporto)
    */
    string get_code() const;

    /**
    * @brief Função que retorna o nome do aeroporto
    * Complexidade temporal O(1)
    * @return O valor desejado (nome do aeroporto)
    */
    string get_name() const;

    /**
    * @brief Função que retorna a cidade do aeroporto
    * Complexidade temporal O(1)
    * @return O valor desejado (cidade do aeroporto)
    */
    string get_city() const;

    /**
    * @brief Função que retorna o país do aeroporto
    * Complexidade temporal O(1)
    * @return O valor desejado (país do aeroporto)
    */
    string get_country() const;

    /**
    * @brief Função que retorna a latitude do aeroporto
    * Complexidade temporal O(1)
    * @return A coordenada desejada (latitude)
    */
    double get_latitude() const;

    /**
    * @brief Função que retorna a longitude do aeroporto
    * Complexidade temporal O(1)
    * @return A coordenada desejada (longitude)
    */
    double get_longitude() const;

};


#endif //AED_AIR_AIRPORT_H
