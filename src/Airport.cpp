//
// Created by manue on 28/12/2022.
//

#include "Airport.h"

#include <string>

using namespace std;

Airport::Airport() {}

Airport::Airport(string code_, string name_, string city_, string country_, double latitude_, double longitude_) {
    code = code_;
    name = name_;
    city = city_;
    country = country_;
    latitude = latitude_;
    longitude = longitude_;
}

string Airport::get_code() const { return code; }

string Airport::get_name() const { return name; }

string Airport::get_city() const { return city; }

string Airport::get_country() const { return country; }

double Airport::get_latitude() const { return latitude; }

double Airport::get_longitude() const { return longitude; }
