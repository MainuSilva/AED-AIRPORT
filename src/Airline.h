#ifndef AED_AIR_AIRLINE_H
#define AED_AIR_AIRLINE_H

#include <string>

using namespace std;

/**
 * @brief Classe que representa uma companhia aerea
 */

class Airline {

private:
    /// Código da companhia aerea
    string code;
    
    /// Nome da companhia aerea
    string name;
    
    /// Alcunha da companhia aerea
    string callsign;
    
    /// País de origem da companhia aerea
    string country;

public:
    /**
    * @brief Construtor Default
    */    
    Airline();
    
    /**
    * @brief Função que cria um novo objeto 'Airline' com os valores especificados para os seus campos
    * Complexidade temporal O(1)
    * @param code
    * @param name
    * @param callsign
    * @param country
    */
    Airline(string code, string name, string callsign, string country);
    
    /**
    * @brief Função que retorna o código da companhia aérea
    * Complexidade temporal O(1)
    * @return O valor desejado (código da companhia)
    */
    string get_code() const;
    
    /**
    * @brief Função que retorna o nome da companhia aérea
    * Complexidade temporal O(1)
    * @return O valor desejado (nome da companhia)
    */
    string get_name() const;
    
    /**
    * @brief Função que retorna a alcunha da companhia aérea
    * Complexidade temporal O(1)
    * @return O valor desejado (alcunha da companhia)
    */
    string get_callsign() const;
    
    /**
    * @brief Função que retorna o país de origem da companhia aérea
    * Complexidade temporal O(1)
    * @return O valor desejado (país de origem da companhia)
    */
    string get_country() const;

};


#endif //AED_AIR_AIRLINE_H
