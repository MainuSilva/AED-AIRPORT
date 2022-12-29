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

// Breadth-First Search: example implementation
void Graph::bfs(string v) {
    queue<string> q;

    // Mark the current node as visited and enqueue it
    nodes[v].visited = true;
    q.push(v);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        for (const auto& edge : nodes[curr].adj) {
            if (!nodes[edge.destination].visited) {
                nodes[edge.destination].visited = true;
                q.push(edge.destination);
            }
        }
    }
}