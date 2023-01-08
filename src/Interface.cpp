#include "Interface.h"
#include <iostream>
#include <string>
#include <algorithm>

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

list<string> Interface::airlines_select(){
    char choice;
    list<string> wantedAirlines = {};

    cout << "\nDo you wish to specify any airlines to fly on? (Y/N): ";
    do {
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

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

list<string> Interface::getAirlines() {
    list<string> airlines;
    bool stop_While = false;

    cout << "\nWrite the airlines code one by one and 'S' when finished" << endl;
    do {
        cout << "\nInsert airline's code: ";
        string airline;
        cin >> airline;
        cin.ignore(INT16_MAX, '\n');
        
        
        if(airline == "s" || airline == "S" && airlines.empty())
            cout << " Must insert at least one airline";

        else if(airline == "s" || airline == "S" )
            stop_While = true;

        else if (!gestor->availableAirline(airline))
            cout << " This airline doesn't exist, please try again";

        else airlines.push_back(airline);

    } while (!stop_While);

    return airlines;
}

string Interface::getCity(){
    string city;
    bool stop_While = false;

    cout << "\nInsert City's name: ";

    do {
        getline(cin, city);

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

    cout << "\nInsert Country's name: ";

    do {
        getline(cin, country);

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
        if (!(cin >> latitude)) {
            cout << "\nInvalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (!(-90 <= latitude && latitude <= 90)) {
            cout << "\nThis latitude doesn't exist, please try again: ";
        }
        else {
            stop_While = true;
        }

    } while (!stop_While);

    return latitude;
}

double Interface::getLong(){
    double longitude;
    bool stop_While = false;

    cout << "\nInsert Longitude: ";
    do {
        if (!(cin >> longitude)){
            cout << "\nInvalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (!(-180 <= longitude && longitude <= 180))
            cout << "\nThis longitude doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return longitude;
}

double Interface::getDistance(){
    double distance;
    bool stop_While = false;

    cout << "\nInsert distance in KM: ";
    do {
        if (!(cin >> distance)){
            cout << "\nInvalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (distance <= 0)
            cout << "\nInvalid distance, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return distance;

}

int Interface::getNum(){
    int numFlights;
    bool stop_While = false;

    do {
        if (!(cin >> numFlights)){
            cout << "\nInvalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
        }
        else if (numFlights <= 0)
            cout << "\nInvalid number, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return numFlights;
}

void Interface::wait_B(){
    char button;
    bool stop_While = false;

    cout << "\n[B] Go Back" << endl;

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

    cout << "\nAre you sure you want to exit? (Y/N): ";

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
                flightInfo();
                break;

            case '2':
                airportInfo();
                break;

            case '3':
                countryInfo();
                break;

            case '4':
                networkInfo();
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


void Interface::airportInfo(){
    //get Airport
    string airport;
    airport = getAirport();

    char choice;
    bool stop_While = false;
    do {
        if (end_prog) break;

        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|          " << airport << " airport Info            |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Flight Board              |" << endl;
        cout << "|        [2] Airports List             |" << endl;
        cout << "|        [3] Airlines List             |" << endl;
        cout << "|        [4] City List                 |" << endl;
        cout << "|        [5] Countries List            |" << endl;
        cout << "|        [6] Airport Reach             |" << endl;
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
                flightBoard(airport);
                break;

            case '2':
                airportsList(airport); //lista de aeroportos que o aeroporto chega com 1 voo
                break;

            case '3':
                airlinesList(airport); //lista de airlines do aeroporto
                break;

            case '4':
                cityList(airport); //lista de cidades que o aeroporto chega com 1 voo
                break;

            case '5':
                countriesList(airport); //lista de paises que o aeroporto chega com 1 voo
                break;

            case '6':
                airportReach(airport); //lista de paises, cidades e aeroportos que o aeroporto chega com k voos
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


void Interface::flightBoard(const string& airport) {

    list <pair <string,string>> board= gestor->getDepartureBoard(airport);

    cout << "____________________________________________________" << endl;
    cout << "|                   "<< airport << " DEPARTURES                 |" << endl;
    cout << "|__________________________________________________|" << endl;
    cout << "|        Flight         |         Airline          |" << endl;
    cout << "|_______________________|__________________________|" << endl;

    for (const auto& elem: board){
        cout << "|       " << airport <<"->"<< elem.first << "        |           "<< elem.second << "            |" << endl;
        cout << "|_______________________|__________________________|" << endl;
    }

    cout<< "\nSCHEDULED FLIGHTS" << endl;
    cout << airport << " airport has " <<  board.size() << " flights scheduled" << endl;

    wait_B();
}


void Interface::airportsList(const string& airport){
    cout << "\n================| " << airport << " airport -> Airports |================\n" << endl;

    cout << "CODE  NAME"<< endl;
    for (const auto& air: gestor->getAirportsArrived(airport)) {
        cout << air.get_code() << "   " << air.get_name() << endl;
    }

    wait_B();
}

void Interface::cityList(const string& airport) { //cidades
    cout << "\n================| " << airport << " airport -> Cities |================\n" << endl;

    for (const auto& city: gestor->getCitiesArrived(airport)) {
        cout << city << endl;
    }

    wait_B();
}

void Interface::airlinesList(const string& airport) {
    cout << "\n================| " << airport << " airport Airlines |================\n" << endl;

    cout << "CODE  NAME"<< endl;
    for (const auto& airline: gestor->getAirportAirlines(airport)) {
        cout << airline.get_code() << "   " << airline.get_name() << endl;
    }

    wait_B();
}

void Interface::countriesList(const string& airport) {
    cout << "\n================| " << airport <<" airport -> Countries |================\n" << endl;

    for (const auto& country: gestor->getCountriesArrived(airport)) {
        cout << country << endl;
    }

    wait_B();
}

void Interface::airportReach(const string& airport) {
    int numFlights, airportNum, cityNum, countryNum;

    cout << "\n================| " << airport << " airport Reach |================" << endl;
    cout << "\nInsert Number of Flights: ";
    numFlights = getNum();

    airportNum = gestor->getPossibleFlightsAirports(airport, numFlights).size();
    cityNum = gestor->getPossibleFlightsCities(airport, numFlights).size();
    countryNum = gestor->getPossibleFlightsCountries(airport,numFlights).size();

    cout << "\nFrom this airport you can reach: " << airportNum << " airports, " << cityNum << " cities and " << countryNum << " countries with " << numFlights << " flights." << endl;

    wait_B();
}

void Interface::networkInfo() {
    char choice;
    bool stop_While = false;
    do {
        if(end_prog) break;

        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|              Network Info            |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Articulation Points       |" << endl;
        cout << "|        [2] Diameter                  |" << endl;
        cout << "|        [3] Top Airports              |" << endl;
        cout << "|        [4] Total Countries           |" << endl;
        cout << "|        [5] Total Cities              |" << endl;
        cout << "|        [6] Total Airports            |" << endl;
        cout << "|        [7] Total Airlines            |" << endl;
        cout << "|        [8] Total Flights             |" << endl;
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

            case '4':
                goTotalCountries();
                break;

            case '5':
                goTotalCities();
                break;

            case '6':
                goTotalAirports();
                break;

            case '7':
                goTotalAirlines();
                break;

            case '8':
                goTotalFlights();
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
    list<string> wantedAirlines;
    wantedAirlines = airlines_select();
    list<string> artPoints = gestor->getArticulationPoints(wantedAirlines);

    cout <<"\n===========| Articulation Points |===========" << endl;
    cout << "\nThe";

    if(wantedAirlines.empty()) {
        cout << " total ";
    }
    cout<< "number of articulations ";

    if(!wantedAirlines.empty()) {
        cout << "for these airlines ";
    }

    cout << "is " << artPoints.size() << endl;

    wait_B();
}

void Interface::goDiameter() {
    list<string> wantedAirlines;
    wantedAirlines = airlines_select();
    int diameter = gestor->getDiameter(wantedAirlines);

    cout <<"\n===========| Diameter |============" << endl;

    cout << "\nThe maximum diameter ";

    if(!wantedAirlines.empty()) {
        cout << "for these airlines ";
    }

    cout << "is " << diameter << endl;

    wait_B();
}

void Interface::goTotalFlights(){
    int totalFlights = gestor->getTotalNumberOfFlights();
    cout << "\n================| Total Flights |================" << endl;
    cout << "\nThere is a total total of " << totalFlights << " flights in this network." << endl;

    wait_B();
}

void Interface::goTotalAirports() {
    int totalAirports = gestor->getTotalNumberOfAirports();
    cout << "\n================| Total Airports |================" << endl;
    cout << "\nA total of " << totalAirports << " airports are covered by this network." << endl;

    wait_B();
}

void Interface::goTotalAirlines() {
    int totalAirlines = gestor->getTotalNumberOfAirlines();
    cout << "\n================| Total Airlines |================" << endl;
    cout << "\nA total of " << totalAirlines << " airlines fly in this network." << endl;

    wait_B();
}

void Interface::goTotalCities() {
    int totalCities = gestor->getTotalNumberOfCities();
    cout << "\n================| Total Cities |================" << endl;
    cout << "\nA total of " << totalCities << " cities are covered by this network." << endl;

    wait_B();
}

void Interface::goTotalCountries() {
    int totalCountries = gestor->getTotalNumberOfCountries();
    cout << "\n================| Total Countries |================" << endl;
    cout << "\nA total of " << totalCountries << " countries are covered by this network." << endl;

    wait_B();
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

            default:
                cout << "\nInvalid Input, please try again" << endl;
        }
    }
    while(!stop_While);
}

// feita não é preciso alterar
void Interface::goMostAirlines() {
    int index = 1;
    cout << "\nInsert how many airports you would like to see listed: ";
    int k = getNum();
    cout <<"\n====| Top "<< k <<" Airports by Airline Number |====" << endl;

    for (const auto& airport: gestor->getTopNumberAirports(k,"airlines")){
        cout << index++ <<". " << airport << endl;
    }

    wait_B();
}

// feita não é preciso alterar
void Interface::goMostFlights() {
    int index = 1;
    cout << "\nInsert how many airports you would like to see listed: ";
    int k = getNum();
    cout <<"\n====| Top "<< k <<" Airports by Flights Number |====" << endl;

    for (const auto& airport : gestor->getTopNumberAirports(k,"flights")){
        cout << index++ <<". " << airport << endl;
    }

    wait_B();
}


void::Interface::flightInfo(){
    char choice;
    bool stop_While = false;
    do {
        if(end_prog) break;

        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|              Flight Info             |" << endl;
        cout << "|  Shortest paths in order of distance |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|      [1] Travel to an airport        |" << endl;
        cout << "|      [2] Travel to a city            |" << endl;
        cout << "|      [3] Travel to a GPS location    |" << endl;
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


int::Interface::fromWhere(){
    char choice;
    bool stop_While = false;
    do {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|             From Where?              |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] from airport              |" << endl;
        cout << "|        [2] from city                 |" << endl;
        cout << "|        [3] from GPS location         |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [B] Go Back             |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                return 1;

            case '2':
                return 2;

            case '3':
                return 3;

            case 'B': case 'b':
                stop_While = true;
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);

}


void::Interface::goAirport(){
    string airportDest;
    list<string> wantedAirlines;
    vector<list<Airport>> paths;
    int from = fromWhere();

    if(from == 1) {
        cout << "\n================| Airport -> Airport |================" << endl;
        cout << "\nSOURCE ";
        string airportSrc = getAirport();

        cout << "\nDESTINATION ";
        airportDest = getAirport();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathTwoAirports(airportSrc, airportDest, wantedAirlines);
    }

    else if(from == 2) {
        cout << "\n================| City -> Airport |================" << endl;
        cout << "\nSOURCE";
        string citySrc = getCity();

        cout << "\nDESTINATION ";
        airportDest = getAirport();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathCityToAir( citySrc, airportDest, wantedAirlines);
    }

    else if(from == 3) {
        cout << "\n================| GPS Location -> Airport |================" << endl;
        cout << "\nSOURCE ";
        double lat = getLat();
        double lon = getLong();
        double distance = getDistance();

        cout << "\nDESTINATION ";
        airportDest = getAirport();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathLocationToAir( lat, lon, distance, airportDest, wantedAirlines);
    }
    else return;

    int index = 1;

    if(paths.empty()){
        cout << "\nNo paths found for this location" << endl;
    }

    for(const list<Airport>& path : paths){
        cout << "\n" << index << ". PATH" <<" (" << "distance:" << gestor->getPathDistance(path) << "km)" << endl;

        int count = 0;
        for(const Airport& air : path){
            count++;
            if(count == 1)
                cout << air.get_code();
            else
                cout << "->" << air.get_code();
        }
        index++;
        cout << endl;
    }

    wait_B();

}

void Interface::goCity(){
    string city;
    list<string> wantedAirlines;
    vector<list<Airport>> paths;
    int from = fromWhere();

    if(from == 1) {
        cout << "\n================| Airport -> City |================" << endl;
        cout << "\nSOURCE ";
        string airportSrc = getAirport();

        cout << "\nDESTINATION ";
        city = getCity();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathAirToCity(airportSrc, city, wantedAirlines);
    }

    else if(from == 2) {
        cout << "\n================| City -> City |================" << endl;
        cout << "\nSOURCE ";
        string citySrc = getCity();

        cout << "\nDESTINATION ";
        city = getCity();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathCityToCity( citySrc, city, wantedAirlines);
    }

    else if (from == 3) {
        cout << "\n================| GPS Location -> City |================" << endl;
        cout << "\nSOURCE ";
        double lat = getLat();
        double lon = getLong();
        double distance = getDistance();

        cout << "\nDESTINATION ";
        city = getCity();

        cout << "\nSELECT AIRLINES: ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathLocationToCity( lat, lon, distance, city, wantedAirlines);
    }
    else return;

    int index = 1;

    if(paths.empty()){
        cout << "\nNo paths found for this location" << endl;
    }

    for(const list<Airport>& path : paths){
        cout << "\n" << index << ". PATH" <<" (" << "distance:" << gestor->getPathDistance(path) << "km)" << endl;

        int count = 0;
        for(const Airport& air : path){
            count++;
            if(count == 1)
                cout << air.get_code();
            else
                cout << "->" << air.get_code();
        }
        index++;
        cout <<  endl;
    }

    wait_B();

}

void Interface::goCoords(){
    double lat, lon, distance;
    list<string> wantedAirlines;
    vector<list<Airport>> paths;
    int from = fromWhere();

    if(from == 1) {
        cout << "\n================| Airport -> GPS Location |================" << endl;
        cout << "\nSOURCE ";
        string airportSrc = getAirport();

        cout << "\nDESTINATION ";
        lat = getLat();
        lon = getLong();
        distance = getDistance();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathAirToLocation(airportSrc, lat, lon, distance, wantedAirlines);
    }

    else if(from == 2) {
        cout << "\n================| City -> GPS Location |================" << endl;
        cout << "\nSOURCE ";
        string citySrc = getCity();

        cout << "\nDESTINATION ";
        lat = getLat();
        lon = getLong();
        distance = getDistance();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathCityToLocation( citySrc, lat, lon, distance, wantedAirlines);
    }

    else if(from == 3) {
        cout << "\n================| GPS Location -> GPS Location |================" << endl;
        cout << "\nSOURCE ";
        double lat2 = getLat();
        double lon2 = getLong();
        double distance2 = getDistance();

        cout << "\nDESTINATION ";
        lat = getLat();
        lon = getLong();
        distance = getDistance();

        cout << "\nSELECT AIRLINES ";
        wantedAirlines = airlines_select();

        paths = gestor->getMinPathLocationToLocation( lat2, lon2, distance2, lat, lon, distance, wantedAirlines);
    }
    else return;

    int index = 1;

    if(paths.empty()){
        cout << "\nNo paths found for this location" << endl;
    }

    for(const list<Airport>& path : paths){
        cout << "\n" << index << ". PATH" <<" (" << "distance:" << gestor->getPathDistance(path) << "km)" << endl;

        int count = 0;
        for(const Airport& air : path){
            count++;
            if(count == 1)
                cout << air.get_code();
            else
                cout << "->" << air.get_code();
        }
        index++;
        cout <<  endl;
    }

    wait_B();
}

void Interface::countryInfo() {
    string country;
    country = getCountry();

    char choice;
    bool stop_While = false;
    do {
        if (end_prog) break;

        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|             Country Info             |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|           [1] Airports List          |" << endl;
        cout << "|           [2] Airlines List          |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [B] Go Back             |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                AirportsNumCountry(country);
                break;

            case '2':
                airlinesListCountry(country);
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);

}


void Interface::AirportsNumCountry(string country) {
    cout << "\n================| " + country +" Airports |================" << endl;
    cout << "\nNumber of airports from " + country  + ": " << gestor->getAllAirportsFromCountry(country).size() << endl;
    cout << endl;
    cout << "CODE  NAME"<< endl;
    for (const auto& airport: gestor->getAllAirportsFromCountry(country)) {
        cout << airport.get_code() << "   " << airport.get_name() << endl;
    }

    wait_B();
}

void Interface::airlinesListCountry(const string& country) {
    cout << "\n================| " + country +" Airlines |================" << endl;
    cout << "\nNumber of airlines from " + country  + ": " << gestor->getAllAirLinesFromCountry(country).size() << endl;
    cout << endl;
    cout << "CODE  NAME"<< endl;
    for (const auto& airline: gestor->getAllAirLinesFromCountry(country)) {
        cout << airline.get_code() << "   " << airline.get_name() << endl;
    }

    wait_B();
}
