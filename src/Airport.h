//
// Created by manue on 28/12/2022.
//

#ifndef AED_AIR_AIRPORT_H
#define AED_AIR_AIRPORT_H

#include <string>

using namespace std;

class Airport {
private:
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;

public:
    Airport();

    Airport(string code, string name, string callsign, string country, double latitude, double longitude);
    string get_code() const;
    string get_name() const;
    string get_city() const;
    string get_country() const;
    double get_latitude() const;
    double get_longitude() const;

};


#endif //AED_AIR_AIRPORT_H
