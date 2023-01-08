//
// Created by manue on 29/12/2022.
//

#ifndef AED_AIR_COORDDISTANCE_H
#define AED_AIR_COORDDISTANCE_H

#include <cmath>
#include "Airport.h"

class CoordDistance {
    /**
     * @brief Calcula a menor distância entre duas coordenadas
     * @details Complexidade temporal: O(1)
     * 
     * @param lat1 Latitude do primeiro ponto
     * @param lat2 Latitude do segundo ponto
     * @param long1 Longitude do primeiro ponto
     * @param long2 Longitude do segundo ponto
     * @return O valor pretendido (a menor distância entre duas coordnadas)
     */
    static double haversine(double lat1, double lat2, double long1, double long2);

public:

    /**
     * @brief Calcula a distancia entre um aeroporto de origem e um de destino
     * @details Complexidade temporal: O(1)
     * 
     * @param airportSrc aeroporto de Origem
     * @param airportDest aeroporto de Destino
     * @return O valor pretendido (a distancia entre um aeroporto de origem e um de destino)
     */
    static double haversine(Airport &airportSrc, Airport &airportDest);

    /**
     * @brief Calcula a distancia entre determinadas coordenadas e um aeroporto de destino
     * @details Complexidade temporal: O(1)
     * 
     * @param lat Latitude
     * @param lon longitude
     * @param airportDest aeroporto de destino
     * @return O valor pretendido (a distancia entre determinadas coordenadas e um aeroporto de destino)
     */
    static double haversine(double lat, double lon, Airport &airportDest);
};


#endif //AED_AIR_COORDDISTANCE_H
