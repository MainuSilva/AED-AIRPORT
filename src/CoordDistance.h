//
// Created by manue on 29/12/2022.
//

#ifndef AED_AIR_COORDDISTANCE_H
#define AED_AIR_COORDDISTANCE_H

#include <cmath>
#include "Airport.h"

class CoordDistance {
    /**
     * Calculates the shortest distance between two coordenates.
     *
     * @details Time Complexity: O(log(n))
     *
     * @param lat1 Latitude of the first point
     * @param lat2 Latitude of the second point
     * @param long1 Longitude of the first point
     * @param long2 Longitude of the second point
     * @return Distance between the two points in Kms
     */
    static double haversine(double lat1, double lat2, double long1, double long2);

public:

    /**
     * @brief
     * Time Complexity:
     * @param airportSrc
     * @param airportDest
     * @return
     */
    static double haversine(Airport &airportSrc, Airport &airportDest);

    /**
     * @brief
     * Time Complexity:
     * @param lat
     * @param lon
     * @param airportDest
     * @return
     */
    static double haversine(double lat, double lon, Airport &airportDest);
};


#endif //AED_AIR_COORDDISTANCE_H
