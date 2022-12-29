#include "Graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(){}

void Graph::addNode( const Airport& airport) {
    nodes.insert({ airport.get_code(), {{}, false }});
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(const string& src, const string& dest, const string& airline) {
    auto src_airport = nodes.find(src);
    auto dest_airport = nodes.find(dest);

    if (src_airport == nodes.end() || dest_airport == nodes.end()) return;

    for (Edge &e: src_airport->second.adj){
        if (e.destination == dest) {
            e.airlines.push_back(airline);
            return;
        }
    }
    src_airport->second.adj.push_back({dest, {airline}});

}

// Depth-First Search: example implementation
void Graph::dfs(const string& v) {
    nodes[v].visited = true;

    // Recursively visit all unvisited adjacent nodes
    for (const auto& edge : nodes[v].adj) {
        if (!nodes[edge.destination].visited) {
            dfs(edge.destination);
        }
    }
}
void Graph::restart(){
    for(auto &node: nodes) {
        node.second.visited = false;
        node.second.distance = INT_MAX;
    }
}

// Breadth-First Search: example implementation
list<string> Graph::findMinPathBfs(const string& airportSrc, const string& airportDest) {
    restart();

    queue<string> q;

    nodes[airportSrc].distance = 0;
    nodes[airportSrc].visited = true;
    q.push(airportSrc);

    // Create a map to store the predecessor of each node
    unordered_map<string, string> pred;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == airportDest) {
            list<string> path;
            string curr_node = curr;
            while (curr_node != airportSrc) {
                path.push_back(curr_node);
                curr_node = pred[curr_node];
            }
            path.push_back(airportSrc);
            path.reverse();
            return path;
        }

        for (const auto& edge : nodes[curr].adj) {
            auto w = edge.destination;
            if (!nodes[w].visited) {
                nodes[w].visited = true;
                nodes[w].distance = nodes[curr].distance + 1;

                pred[w] = curr;
                q.push(edge.destination);
            }
        }
    }

    // Return an empty path if we have not reached the end node
    return {};
}
