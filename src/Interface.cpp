#include "Interface.h"
#include <iostream>
#include <string>
using namespace std;

Interface::Interface(){
    end_prog = false;
}

void wait_B(){

    char button;
    bool stop_While = false;

    cout << "\n[B] Go Back\n" << endl;

    while(!stop_While){
        cin >> button;
        if(button == 'b' || button == 'B') {
            stop_While = true;
        }
    }
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
                flight_Info();
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


void::Interface::flight_Info(){
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
    cout << "Insert Airport's name: " << endl;
    airport = findAirport();



    airlines_Info();

}

string Interface::findAirport() {
    string airport;
    bool stop_While = false;

    do {
        cin >> airport;
        //cin.ignore(INT16_MAX, '\n'); não sei se aqui também se põe isto ou não, deixei comentado caso se precise


        //procurar airport lá no grafo

        if (/* Erro de aeroporto */)
            cout << "\nThis aiport doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return airport;
}

void Interface::goCity(){
    string city;
    cout << endl;
    cout << "\n================| City |================" << endl;
    cout << endl;
    cout << "Insert City's name: " << endl;
    city= findCity();





    airlines_Info();
}

string Interface::findCity(){
    string city;
    bool stop_While = false;

    do {
        cin >> city;
        //cin.ignore(INT16_MAX, '\n'); não sei se aqui também se põe isto ou não, deixei comentado caso se precise


        //procurar city lá no grafo

        if (/* Erro de cidade */)
            cout << "\nThis city doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return city;
}

void Interface::goCoords(){

    string latitude, longitude;
    cout << endl;
    cout << "\n================| Coordinates |================" << endl;
    cout << endl;
    cout << "Insert Latitude: " << endl;
    latitude = findLat();
    cout << "Insert Longitude: " << endl;
    longitude = findLong();




    airlines_Info();
}

double Interface::findLat(){
    double latitude;
    bool stop_While = false;

    do {
        cin >> latitude;
        //cin.ignore(INT16_MAX, '\n'); não sei se aqui também se põe isto ou não, deixei comentado caso se precise

        //procurar latitude lá no grafo

        if (/* Erro de latitude */)
            cout << "\nThis latitude doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return latitude;
}

double Interface::findLong(){
    double longitude;
    bool stop_While = false;

    do {
        cin >> longitude;
        //cin.ignore(INT16_MAX, '\n'); não sei se aqui também se põe isto ou não, deixei comentado caso se precise


        //procurar longitude lá no grafo

        if (/* Erro de longitude */)
            cout << "\nThis longitude doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return longitude;
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
    cout << endl;
    cout << "\n================| Airport |================" << endl;
    cout << endl;
    cout << "Insert Airport's name: " << endl;
    airport = findAirport();



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
    cout << "Insert Number of Flights: " << endl;
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

