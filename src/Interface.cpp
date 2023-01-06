#include "Interface.h"
#include <iostream>
#include <string>
using namespace std;

Interface::Interface(){
    gestor = new Gestor();
    end_prog = false;
}

string Interface::getAirport() {
    string airport;
    bool stop_While = false;

    cout << "\nInsert Airport's code: ";
    do {
        cin >> airport;
        cin.ignore(INT16_MAX, '\n');

        if (!gestor->availableAirport(airport))
            cout << "\nThis airport doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return airport;
}


list<string> Interface::getAirlines() {
    list<string> airlines;
    bool stop_While = false;

    cout << "\nWrite 'S' when finished" << endl;
    cout<< endl;
    do {
        cout << "Insert airline's code: ";
        string airline;
        cin >> airline;
        cin.ignore(INT16_MAX, '\n');

        if(airline == "s" || airline == "S")
            stop_While = true;

        else if (!gestor->availableAirline(airline))
            cout << "\nThis airline doesn't exist, please try again";

        else{
            airlines.push_back(airline);
        }

    } while (!stop_While);

    return airlines;
}

string Interface::getCity(){
    string city;
    bool stop_While = false;

    cout << "\nInsert City's name: ";
    do {
        cin >> city;
        cin.ignore(INT16_MAX, '\n');

        if (!gestor->availableCity(city))
            cout << "\nThis city doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return city;
}

string Interface::getCountry(){
    string country;
    bool stop_While = false;

    cout << "\nInsert country's name: ";
    do {
        cin >> country;
        cin.ignore(INT16_MAX, '\n');

        if (!gestor->availableCountry(country))
            cout << "\nThis country doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return country;
}

double Interface::getLat(){
    double latitude;
    bool stop_While = false;

    cout << "\nInsert Latitude: ";
    do {
        cin >> latitude;
        cin.ignore(INT16_MAX, '\n');

        if (!(-90 <= latitude && latitude <= 90))
            cout << "\nThis latitude doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return latitude;
}

double Interface::getLong(){
    double longitude;
    bool stop_While = false;

    cout << "\nInsert Longitude: ";
    do {
        cin >> longitude;
        cin.ignore(INT16_MAX, '\n');

        if (!(-180 <= longitude && longitude <= 180))
            cout << "\nThis longitude doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return longitude;
}

int Interface::getNum(){
    int numFlights;
    bool stop_While = false;

    do {
        cin >> numFlights;
        cin.ignore(INT16_MAX, '\n');

        if (numFlights <= 0)
            cout << "\nInvalid number, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return numFlights;
}

void Interface::wait_B(){
    char button;
    bool stop_While = false;

    cout << "\n[B] Go Back\n" << endl;

    while(!stop_While){
        cin >> button;
        cin.ignore(INT16_MAX, '\n');
        if(button == 'b' || button == 'B') {
            stop_While = true;
        }
    }
}


bool Interface:: verifyExit(){
    char check;

    cout << "\nAre you sure you want to exit? Y or N: ";

    do {
        cin >> check;
        cin.ignore(INT16_MAX, '\n');

        switch(check){

            case 'Y': case 'y': return true;

            case'N': case'n': return false;

            default: cout << "\nInvalid Input, please try again" << endl;

        }

    }
    while(true);
}

void Interface::showMenu() {
    char choice;
    do {
        cout << "********** FEUP AIRPORT CONTROL ********" << endl;
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|      What are you looking for?       |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Flight Information        |" << endl;
        cout << "|        [2] Airport Information       |" << endl;
        cout << "|        [3] Country Information       |" << endl;
        cout << "|        [4] Network Information       |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [E] Exit                |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                flight_info();
                break;

            case '2':
                airport_ask();
                break;

            case '3':
                country_info();
                break;

            case '4':
                network_info();
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!end_prog);
}

void Interface::network_info() {
    char choice;
    bool stop_While = false;
    do {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|              Network Info            |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Articulation Points       |" << endl;
        cout << "|        [2] Diameter                  |" << endl;
        cout << "|        [3] Top Aiports               |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [B] Go Back             |" << endl;
        cout << "|              [E] Exit                |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                goArticulationP();
                break;

            case '2':
                goDiameter();
                break;

            case '3':
                goTopAirports();
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);

}

void Interface::goArticulationP() {

}

void Interface::goDiameter() {

}

void Interface::goTopAirports() {
    char choice;
    bool stop_While = false;
    do {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|              Top Airports            |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] By Most Flights           |" << endl;
        cout << "|        [2] By Most Airlines          |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [B] Go Back             |" << endl;
        cout << "|              [E] Exit                |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                goMostFlights();
                break;

            case '2':
                goMostAirlines();
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);
}


void Interface::goMostAirlines() {
    int k;
    int i=1;
    cout << "Insert how many aiports you would like to see listed: ";
    k= getNum();
    cout << endl;
    cout <<"====| Top "<< k <<" Airports by Airline Number |====" << endl;
    for (auto a: gestor->getTopNumberAirports(k,"airlines")){
        cout << i <<". " << a << endl;
        i++;
    }
}

void Interface::goMostFlights() {
    int k;
    int i=1;
    cout << "Insert how many aiports you would like to see listed: ";
    k= getNum();
    cout << endl;
    cout <<"====| Top "<< k <<" Airports by Flights Number |====" << endl;
    for (auto a: gestor->getTopNumberAirports(k,"flights")){
        cout << i <<". " << a << endl;
        i++;
    }

}


void::Interface::flight_info(){
    char choice;
    bool stop_While = false;
    do {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|              Flight Info             |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Travel to an airport      |" << endl;
        cout << "|        [2] Travel to a city          |" << endl;
        cout << "|        [3] Travel to a GPS location  |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [B] Go Back             |" << endl;
        cout << "|              [E] Exit                |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                goAirport();
                break;

            case '2':
                goCity();
                break;

            case '3':
                goCoords();
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);

}


void::Interface::goAirport(){
    string airport;
    list<string> wantedAirlines;
    list<Airport> path;

    cout << "\n================| Airport |================" << endl;
    cout << endl;
    airport = getAirport();
    wantedAirlines = airlines_select();

    /*path = gestor->getMinPathTwoAirports()*/

}

void Interface::goCity(){
    string city;
    list<string> wantedAirlines;
    list<Airport> path;

    cout << "\n================| City |================" << endl;
    cout << endl;
    city = getCity();
    wantedAirlines = airlines_select();


}

void Interface::goCoords(){
    string latitude, longitude;
    list<string> wantedAirlines;
    list<Airport> path;

    cout << "\n================| Coordinates |================" << endl;
    cout << endl;
    latitude = getLat();
    longitude = getLong();
    wantedAirlines = airlines_select();
}

list<string> Interface::airlines_select(){
    char choice;
    list<string> wantedAirlines = {};

    do {
        cout << endl;
        cout << "Do you wish to specify any airlines to fly on? (Y/N): ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');
        cout << endl;

        switch (choice) {

            case 'N': case 'n':
                return wantedAirlines;

            case 'Y': case 'y':
                wantedAirlines = getAirlines();
                return wantedAirlines;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(true);

}

void Interface::anyTravel(){

}

void Interface::airlineTravel(){

}

void Interface::airport_ask(){
    string airport;
    cout << endl;
    cout << "\n================| Airport |================" << endl;
    cout << endl;
    airport = getAirport();

    airport_Info(airport);

}

void Interface::airport_Info(string airport){
    char choice;
    bool stop_While = false;
    do {
        if (end_prog) break;

        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|              Airport Info            |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Number of Flights         |" << endl;
        cout << "|        [2] Airlines List             |" << endl;
        cout << "|        [3] Destinations List         |" << endl;
        cout << "|        [4] Countries List            |" << endl;
        cout << "|        [5] Airport Reach             |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [B] Go Back             |" << endl;
        cout << "|              [E] Exit                |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                flightsNum(airport);
                break;

            case '2':
                airlinesList(airport);
                break;

            case '3':
                cityList(airport); //cidades
                break;

            case '4':
                countriesList(airport);
                break;

            case '5':
                airportReach(airport);
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);

}

void Interface::airlinesList(const string& airport) {
    for (const auto& a: gestor->getAirportAirlines(airport)) {
        cout << a.get_code() << " " << a.get_name() << endl;
    }

    wait_B();

}

void Interface::countriesList(const string& airport) {
    for (const auto& a: gestor->getCountriesArrived(airport)) {
        cout << a << endl;
    }

    wait_B();
}

void Interface::cityList(const string& airport) { //cidades
    for (const auto& a: gestor->getCitiesArrived(airport)) {
        cout << a << endl;
    }

    wait_B();
}

void Interface::airportReach(const string& airport) {
    int numFlights, airportNum, cityNum, countryNum;

    cout << "\n================| Airport Reach |================" << endl;
    cout << endl;
    cout << "\nInsert Number of Flights: ";
    numFlights= getNum();
    cout << endl;

    airportNum = gestor->getPossibleFlightsAirports(airport, numFlights).size();
    cityNum = gestor->getPossibleFlightsCities(airport, numFlights).size();
    countryNum = gestor->getPossibleFlightsCountries(airport,numFlights).size();


    cout << "From this airport you can reach: " << airportNum << " airports, " << cityNum << " cities and " << countryNum << " countries with " << numFlights << " flights." << endl;

    wait_B();
}



void Interface::flightsNum(string airport){

    cout << airport << " airport has " << gestor->getNumberOfAirportFlights(airport) << " flights scheduled";

    wait_B();
}

void Interface::country_info() {

}
