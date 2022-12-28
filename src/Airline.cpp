//
// Created by manue on 28/12/2022.
//

#include "Airline.h"

#include <string>

using namespace std;

Airline::Airline(string code_, string name_, string callsign_, string country_) {
    code = code_;
    name = name_;
    callsign = callsign_;
    country = country_;
}

string Airline::get_code() const { return code; }

string Airline::get_name() const { return name; }

string Airline::get_callsign() const { return callsign; }

string Airline::get_country() const { return country; }