#include <algorithm>
#include <set>
#include <stack>
#include "Graph.h"
#include "CoordDistance.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(){}

void Graph::addNode( const Airport& airport) {
    nodes.insert({ airport.get_code(), {airport, {} }});
}

void Graph::addAirline(const Airline& airline){
    airlines.insert({airline.get_code(),airline});
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(const string& src, const string& dest, const string& airline) {
    auto src_airport = nodes.find(src);
    auto dest_airport = nodes.find(dest);

    if (src_airport == nodes.end() || dest_airport == nodes.end() || src_airport == dest_airport) return;

    nodes[src].allAirlines.insert(airline);

    for (Edge &e: src_airport->second.adj){
        if (e.destination == dest) {
            e.airlines.push_back(airline);
            return;
        }
    }

    src_airport->second.adj.push_back({dest, {airline}});
}

void Graph::restart(){
    for(auto &node: nodes) {
        node.second.visited = false;
        node.second.inStack = false;
        node.second.inArt = false;
        node.second.pred = "dummy";
        node.second.distance = INT_MAX;
        node.second.num = INT_MAX;
        node.second.low = INT_MAX;
    }
}

void Graph::bfs(const string& v) {
    restart();

    queue<string> q;
    q.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;


    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        for (const auto& edge : nodes[curr].adj) {
            auto w = edge.destination;
            if (!nodes[w].visited) {
                nodes[w].visited = true;
                nodes[w].distance = nodes[curr].distance + 1;

                q.push(w);
            }
        }
    }
}

int Graph::bfsDiameter(const string& v, const list<string> &wantedAirlines = {}) {
    restart();
    int diameter = 0;
    queue<string> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        string u = q.front();
        q.pop();
        for (const auto& e : nodes[u].adj) {
            string w = e.destination;
            if (nodes[w].visited) continue;
            if (!wantedAirlines.empty() && !hasCommonAirlines(e.airlines, wantedAirlines)) continue;

            q.push(w);
            nodes[w].visited = true;
            nodes[w].distance = nodes[u].distance + 1;
            diameter = max(diameter, nodes[w].distance);

        }
    }
    return diameter;
}

//determinar o as de articulações da rede de determinadas companhias
void Graph::dfsArticulations(const string& v, stack<string>& s, const list<string>& wantedAirlines, list<string>& result, int index){
    nodes[v].visited = true;
    nodes[v].num = index;
    nodes[v].low = index;
    index++;
    nodes[v].inStack = true;
    s.push(v);

    int count = 0;
    for(auto e: nodes[v].adj){
        auto w = e.destination;
        if(!wantedAirlines.empty() && !hasCommonAirlines(e.airlines, wantedAirlines)) continue;

        if(!nodes[w].visited){
            count++;
            dfsArticulations(w, s, wantedAirlines, result, index);
            nodes[v].low = min(nodes[v].low, nodes[w].low);

            if(nodes[v].num != 1 && !nodes[v].inArt && nodes[w].low >= nodes[v].num){
                result.push_back(v);
                nodes[v].inArt = true;
            }
            else if(!nodes[v].inArt && nodes[v].num == 1 && count > 1) {
                result.push_back(v);
                nodes[v].inArt = true;
            }
        }
        else if(nodes[w].inStack)
            nodes[v].low = min (nodes[v].low, nodes[w].num);

    }
    nodes[s.top()].inStack = false;
    s.pop();
}


//the list of the min Paths possible for a local -> airportDestination
vector<list<Airport>> Graph::findMinPathsAirportsBfs(const string& airportSrc, const string& airportDest, const list<string>& wantedAirlines = {}) {
    restart();

    int min = INT_MAX;
    vector<list<Airport>> result;
    queue<string> q;

    nodes[airportSrc].distance = 0;
    nodes[airportSrc].visited = true;
    q.push(airportSrc);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == airportDest) {
            auto path = constructPath(curr);

            if (path.size() < min && path.size() > 1) {
                result.clear();
                result.push_back(path);
                min = path.size();
            }
            else if (path.size() == min) {
                result.push_back(path);
            }

            continue;
        }

        for (const auto& edge : nodes[curr].adj) {
            auto w = edge.destination;
            if (nodes[w].visited) continue;
            if (!wantedAirlines.empty() && !hasCommonAirlines(edge.airlines, wantedAirlines)) continue;

            nodes[w].visited = true;
            nodes[w].distance = nodes[curr].distance + 1;
            nodes[w].pred = curr;
            q.push(edge.destination);
        }
    }
    return result;
}


//utilizar getLocationAirports ou getCityAirports para determinar a lista de aeroportos e depois determinar o aeroporto com o caminho mais rapido
vector<list<Airport>> Graph::findMinPathsAirToLocationBfs(const string& airportSrc, const list<string>& wantedAirports , const list<string>& wantedAirlines = {}) {
    restart();

    int min = INT_MAX;
    vector<list<Airport>> result;
    queue<string> q;

    nodes[airportSrc].distance = 0;
    nodes[airportSrc].visited = true;
    q.push(airportSrc);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (find(wantedAirports.begin(), wantedAirports.end(), curr) != wantedAirports.end()) {
            auto path = constructPath(curr);

            if (path.size() < min && path.size() > 1) {
                result.clear();
                result.push_back(path);
                min = path.size();
            }
            else if (path.size() == min) {
                result.push_back(path);
            }

            continue;
        }

        for (const auto& edge : nodes[curr].adj) {
            auto w = edge.destination;
            if (nodes[w].visited) continue;
            if (!wantedAirlines.empty() && !hasCommonAirlines(edge.airlines, wantedAirlines)) continue;

            nodes[w].visited = true;
            nodes[w].distance = nodes[curr].distance + 1;
            nodes[w].pred = curr;
            q.push(edge.destination);
        }
    }
    return result;
}

//utilizar getLocationAirports ou getCityAirports para determinar a lista de aeroportos e depois determinar os aeroportos com caminho mais rapido
vector<list<Airport>> Graph::findMinPathsLocationsBfs(const list<string>& airportSrcs, const list<string>& wantedAirports , const list<string>& wantedAirlines = {}) {
    restart();
    int min = INT_MAX;
    vector<list<Airport>> result;
    queue<string> q;

    for (const auto& airportSrc : airportSrcs) {
        nodes[airportSrc].distance = 0;
        nodes[airportSrc].visited = true;
        q.push(airportSrc);
    }

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (find(wantedAirports.begin(), wantedAirports.end(), curr) != wantedAirports.end()) {
            auto path = constructPath(curr);

            if (path.size() < min && path.size() > 1) {
                result.clear();
                result.push_back(path);
                min = path.size();
            }
            else if (path.size() == min) {
                result.push_back(path);
            }
            continue;
        }

        for (const auto& edge : nodes[curr].adj) {
            auto w = edge.destination;
            if (nodes[w].visited) continue;
            if (!wantedAirlines.empty() && !hasCommonAirlines(edge.airlines, wantedAirlines)) continue;

            nodes[w].visited = true;
            nodes[w].distance = nodes[curr].distance + 1;
            nodes[w].pred = curr;
            q.push(edge.destination);
        }
    }
    return result;
}

//utilizar getLocationAirports ou getCityAirports para determinar a lista de aeroportos e depois determinar os aeroportos com caminho mais rapido
vector<list<Airport>> Graph::findMinPathsLocationToAirBfs(const list<string>& airportSrcs, const string& airportDest, const list<string>& wantedAirlines = {}) {
    restart();

    int min = INT_MAX;
    vector<list<Airport>> result;
    queue<string> q;

    for (const auto& airportSrc : airportSrcs) {
        nodes[airportSrc].distance = 0;
        nodes[airportSrc].visited = true;
        q.push(airportSrc);
    }

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == airportDest) {
            auto path = constructPath(curr);

            if (path.size() < min && path.size() > 1) {
                result.clear();
                result.push_back(path);
                min = path.size();
            }
            else if (path.size() == min) {
                result.push_back(path);
            }

            continue;
        }

        for (const auto& edge : nodes[curr].adj) {
            auto w = edge.destination;
            if (nodes[w].visited) continue;
            if (!wantedAirlines.empty() && !hasCommonAirlines(edge.airlines, wantedAirlines)) continue;

            nodes[w].visited = true;
            nodes[w].distance = nodes[curr].distance + 1;
            nodes[w].pred = curr;
            q.push(edge.destination);
        }
    }
    return result;
}

int Graph::getTotalNumberOfAirlines(){
    return airlines.size();
}

int Graph::getTotalNumberOfAirports() {
    return nodes.size();
}

int Graph::getTotalNumberOfFlights(){
    int result= 0;
    for(auto node: nodes){
        result += node.second.adj.size();
    }
    return result;
}

list<Airline> Graph::getAirportAirlines(const string& airport){
    list<Airline> result;
    for(const auto& airline: nodes[airport].allAirlines){
        result.push_back(airlines[airline]);
    }
    return result;
}

//get airports that you can reach with one flight
list<Airport> Graph::getAirportsArrived(const string& airport){
    list<Airport> result;

    for(const auto& e: nodes[airport].adj){
        auto w = e.destination;
        result.push_back(nodes[w].airport);
    }

    return result;
}

//obter uma lista de aeroportos que consegue atingir com um determinado número de voos
list<Airport> Graph::getPossibleFlightsAirports(const string& airportSrc, int flights){
    list<Airport> result;

    bfs(airportSrc);

    for(const auto& node: nodes){
        if(node.second.distance <= flights && node.second.distance > 0)
            result.push_back(node.second.airport);
    }

    return result;
}

// Constructs a path from the destin airport to the src airport
list<Airport> Graph::constructPath(string curr) {
    list<Airport> path;
    while (nodes[curr].distance != 0) {
        path.push_back(nodes[curr].airport);
        curr = nodes[curr].pred;
    }
    path.push_back(nodes[curr].airport);
    path.reverse();
    return path;
}

// Returns true if the given lists of airlines have at least one common element
bool Graph::hasCommonAirlines(const list<string>& airlines1, const list<string>& airlines2) {
    list<string> intersection;
    set_intersection(airlines1.begin(), airlines1.end(), airlines2.begin(), airlines2.end(), back_inserter(intersection));
    return !intersection.empty();
}

list<string> Graph::getArticulationPoints(const list<string>& wantedAirlines = {}){
    restart();
    list<string> result;
    stack<string> s;

    for(const auto& node : nodes){
        if(!node.second.visited)
            dfsArticulations(node.first, s, wantedAirlines, result, 1);
    }

    return result;
}

//determinar os aeroportos a Xkm de uma determinada coordenada
list<string> Graph::getLocationAirports(double lat, double lon, double kmdistance){
    list<string> result;

    for(auto node : nodes) {
        double resultDist = CoordDistance::haversine(lat, lon, node.second.airport);

        if(resultDist <= kmdistance)
            result.push_back(node.first);
    }
    return result;
}

//obter uma lista de aeroportos de uma cidade
list<string> Graph::getCityAirports(const string& city){
    list<string> result;

    for(const auto& node: nodes) {
        if(node.second.airport.get_city() == city)
            result.push_back(node.first);
    }

    return result;
}

//calcula a distancia de um path completo
int Graph::pathDistance(list<Airport> airports){
    int distance = 0;
    auto it = airports.begin();
    Airport curr = *it;
    it++;
    while(it != airports.end()){
        Airport next = *it;
        distance += CoordDistance::haversine(curr, next);
        curr = next;
        it++;
    }
    return distance;
}


int Graph::getDiameter(const list<string> &wantedAirlines = {}) {
    int diameter = 0;
    for(const auto& node: nodes){
        string w = node.first;
        diameter = max(diameter, bfsDiameter(w, wantedAirlines));
    }
    return diameter;
}

//get the best *number* airports
vector<string> Graph::getTopAirports(int number, string sortingWay) {
    vector<string> airports;
    for (const auto &node: nodes) {
        airports.push_back(node.first);
    }

    if (sortingWay == "flights"){
        sort(airports.begin(), airports.end(), [&](const string &a, const string &b) {
            // Sort by number of flights
            return nodes[a].adj.size() > nodes[b].adj.size();
        });
    }

    if (sortingWay == "airlines") {
        sort(airports.begin(), airports.end(), [&](const string &a, const string &b) {
            // Sort by number of airlines
            return nodes[a].allAirlines > nodes[b].allAirlines;
        });
    }

    return vector<string>(airports.begin(), airports.begin() + number);
}

bool Graph::availableAirport(const string& airport){
    auto result = nodes.find(airport);
    if(result == nodes.end() )
        return false;
    return true;
}

bool Graph::availableAirline(const string& airline){
    auto result = airlines.find(airline);
    if(result == airlines.end())
        return false;
    return true;
}

list<Airline> Graph::getAirlinesFromCountry(const string& country){
    list<Airline> result;
    for(const auto& airline: airlines){
        if (airline.second.get_country() == country) {
            result.push_back(airline.second);
        }
    }
    return result;
}

list<Airport> Graph::getAirportsFromCountry(const string& country){
    list<Airport> result;
    for(const auto& node: nodes){
        if (node.second.airport.get_country() == country) {
            result.push_back(node.second.airport);
        }
    }
    return result;
}

list<pair<string,string>> Graph::getDepartureBoard(const string& airport) {
    list<pair<string,string>> result;
    for (const auto& flight : nodes[airport].adj){
        for (const auto& airline: flight.airlines)
            result.push_back({flight.destination,airline});
    }
    return result;
}
Airport Graph::getAirport(const string& airport){
    return nodes[airport].airport;
}