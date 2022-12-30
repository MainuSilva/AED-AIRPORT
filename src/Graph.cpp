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

// Add edge from source to destination with a certain weight
void Graph::addEdge(const string& src, const string& dest, const string& airline) {
    auto src_airport = nodes.find(src);
    auto dest_airport = nodes.find(dest);

    if (src_airport == nodes.end() || dest_airport == nodes.end() || src_airport == dest_airport) return;

    for (Edge &e: src_airport->second.adj){
        if (e.destination == dest) {
            e.airlines.push_back(airline);
            return;
        }
    }

    double kmDistance = CoordDistance::haversine(src_airport->second.airport, dest_airport->second.airport);

    src_airport->second.adj.push_back({dest, {airline}, kmDistance});

}

void Graph::restart(){
    for(auto &node: nodes) {
        node.second.visited = false;
        node.second.pred = nullptr;
        node.second.distance = INT_MAX;
        node.second.num = INT_MAX;
        node.second.low = INT_MAX;
    }
}

void Graph::bfs(const string& v ) {
    restart();

    queue<string> q;
    q.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;


    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        for (const auto& edge : nodes[curr].adj) {º
            auto w = edge.destination;
            if (!nodes[w].visited) {
                nodes[w].visited = true;
                nodes[w].distance = nodes[curr].distance + 1;

                q.push(w);
            }
        }
    }
}

//the list of the min Paths possible for a local -> airportDestination
list<list<Airport>> Graph::findMinPathsBfs(const string& airportSrc, const string& airportDest, const list<string>& wantedAirlines = {}) {
    restart();

    int min = INT_MAX;
    list<list<Airport>> result = {};
    queue<string> q;

    nodes[airportSrc].distance = 0;
    nodes[airportSrc].visited = true;
    q.push(airportSrc);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == airportDest) {

            list<Airport> path;
            string curr_node = curr;

            while (curr_node != airportSrc) {
                path.push_back(nodes[curr_node].airport);
                curr_node = nodes[curr_node].pred;
            }

            path.push_back(nodes[airportSrc].airport);
            path.reverse();

            // Add the path to the result list if it is a minimum path
            if(path.size() < min){
                result.clear();
                result.push_back(path);
                min = path.size();
            }
            else if (path.size() == min)
                result.push_back(path);
        }

        for (const auto& edge : nodes[curr].adj) {
            bool valid_path = true;
            auto w = edge.destination;

            if(!wantedAirlines.empty()) {
                list<string> intersection;

                auto existingAirlines = edge.airlines;

                set_intersection(existingAirlines.begin(), existingAirlines.end(), wantedAirlines.begin(), wantedAirlines.end(), back_inserter(intersection));

                if (intersection.empty()) {
                    valid_path = false;
                }
            }

            if (!nodes[w].visited && valid_path) {
                nodes[w].visited = true;
                nodes[w].distance = nodes[curr].distance + 1;


                nodes[w].pred = curr;
                q.push(edge.destination);
            }
        }
    }
    // Return an empty path if we have not reached the end node
    return result;
}

int Graph::dfsArticulations(string v){
    int sum = 0;
    restart();
    int index = 1;
    stack<string> s;
    nodes[v].num = index;
    nodes[v].low = index;
    index++;
    nodes[v].inStack = true;
    s.push(v);

    for(const auto& e: nodes[v].adj){
        auto w = e.destination;
        if(!nodes[w].visited){
            sum += dfsArticulations(w);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
            if(nodes[w].low >= nodes[v].num)
                sum++;
        }
        else if(nodes[w].inStack)
            nodes[v].low = min (nodes[v].low, nodes[w].num);
    }
    s.pop();
    return sum;
}

//utilizar closestAirports ou cityAirports para determinar a lista de aeroportos
list<list<Airport>> Graph::minPathsAirportsBfs(const string& airportSrc, const list<string>& wantedAirports , const list<string>& wantedAirlines = {}) {
    list<list<Airport>> result;

    for(const string& airportDest: wantedAirports){
        auto minPaths = findMinPathsBfs(airportSrc, airportDest, wantedAirlines);
        result.insert(result.end(), minPaths.begin(), minPaths.end());
    }

    return result;
}

//determinar os aeroportos a Xkm de uma determinada coordenada
list<string> Graph::closestAirports(double lat, double lon, double kmdistance){
    list<string> result;

    for(auto node : nodes) {
        double resultDist = CoordDistance::haversine(lat, lon, node.second.airport);

        if(resultDist <= kmdistance)
            result.push_back(node.first);
    }

    return result;
}

list<string> Graph::cityAirports(const string& city){
    list<string> result;

    for(const auto& node: nodes) {
        if(node.second.airport.get_city() == city)
            result.push_back(node.first);
    }

    return result;
}

//obter uma lista de aeroportos que consegue atingir com um determinado número de voos
list<Airport> Graph::possibleAirports(const string& airportSrc, int flights){
    list<Airport> result;

    bfs(airportSrc);

    for(const auto& node: nodes){
        if(node.second.distance <= flights)
            result.push_back(node.second.airport);
    }

    return result;
}

set<string> Graph:: possibleCities(const string& airportSrc, int flights){
    set<string> result;

    list<Airport> airports = possibleAirports(airportSrc, flights);

    for(const Airport& airport : airports){
        result.insert(airport.get_city());
    }
}

set<string> Graph:: possibleCountries(const string& airportSrc, int flights){
    set<string> result;

    list<Airport> airports = possibleAirports(airportSrc, flights);

    for(const Airport& airport : airports){
        result.insert(airport.get_country());
    }
}

