#ifndef AED_AIR_AIRLINE_H
#define AED_AIR_AIRLINE_H

#include <string>

using namespace std;

class Airline {

private:
    string code;
    string name;
    string callsign;
    string country;

public:
    Airline(string code, string name, string callsign, string country);
    string get_code() const;
    string get_name() const;
    string get_callsign() const;
    string get_country() const;

};


#endif //AED_AIR_AIRLINE_H
