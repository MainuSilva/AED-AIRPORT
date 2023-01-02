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

    do {
        cin >> airport;
        cin.ignore(INT16_MAX, '\n');

        if (!gestor->availableAirport(airport))
            cout << "\nThis aiport doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return airport;
}

string Interface::getCity(){
    string city;
    bool stop_While = false;

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

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!end_prog);
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
    cout << endl;
    cout << "\n================| Airport |================" << endl;
    cout << endl;
    cout << "Insert Airport's name: ";
    airport = getAirport();

    airlines_Info();

}

void Interface::goCity(){
    string city;
    cout << endl;
    cout << "\n================| City |================" << endl;
    cout << endl;
    cout << "Insert City's name: ";
    city = getCity();

    airlines_Info();
}

void Interface::goCoords(){

    string latitude, longitude;
    cout << endl;
    cout << "\n================| Coordinates |================" << endl;
    cout << endl;
    cout << "Insert Latitude: ";
    latitude = getLat();
    cout << "Insert Longitude: ";
    longitude = getLong();

    airlines_Info();
}

void Interface::airlines_Info(){
    char choice;
    bool stop_While = false;
    do {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|                Airlines              |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Any airline               |" << endl;
        cout << "|        [2] Choose airline(s)         |" << endl;
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
                anyTravel();
                break;

            case '2':
                airlineTravel();
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

void Interface::anyTravel(){

}

void Interface::airlineTravel(){

}

void::Interface::airport_ask(){
    string airport;
    cout << endl;
    cout << "\n================| Airport |================" << endl;
    cout << endl;
    cout << "Insert Airport's name: ";
    airport = getAirport();



    airport_Info();
}

void Interface::airport_Info(){
    char choice;
    bool stop_While = false;
    do {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|              Airport Info            |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Flights                   |" << endl;
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
                flights();
                break;

            case '2':
                airlinesList();
                break;

            case '3':
                destinationsList(); //cidades
                break;

            case '4':
                countriesList();
                break;

            case '5':
                airportReach();
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

void Interface::airlinesList() {

}

void Interface::countriesList() {

}

void Interface::destinationsList() { //cidades

}


void Interface::airportReach() {

    int yFlights, airportNum, cityNum, countryNum;

    cout << "\n================| Airport Reach |================" << endl;
    cout << endl;
    cout << "Insert Number of Flights: ";
    cin >> yFlights;



    cout << "From this aiport you can reach: " << airportNum << " airports, " << cityNum << " cities and " << countryNum << " countries with " << yFlights << " flights." << endl;

    wait_B();
}

void Interface::flights(){
    char choice;
    bool stop_While = false;
    do {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|                Flights               |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Number of Flights         |" << endl;
        cout << "|        [2] Departures Board          |" << endl;
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
                flightsNum();
                break;

            case '2':
                departuresBoard();
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

void Interface::flightsNum(){
    // código para imprimir número de voos

}

void Interface::departuresBoard(){
    // código para imprimir painel com os voos :)

}

