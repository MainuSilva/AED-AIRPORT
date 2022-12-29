//
// Created by manue on 29/12/2022.
//

#include "CoordDistance.h"

double CoordDistance::haversine(double lat1, double lat2,double lon1, double lon2){

    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLong = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLong / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));

    return rad * c;
}
