//
//  graph.cpp
//  HW 6
//
//  Created by John Maroudas and Brandon Tran on 11/21/24.
//


#include "graph.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor to initialize graph from a file
Graph::Graph(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }

    int maxCityID = 0;
    vector<Edge> edges; // Temporary storage for edges
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        int from, to, dist;
        ss >> from >> to >> dist;

        edges.push_back({from, to, dist});
        maxCityID = max(maxCityID, max(from, to));
    }

    // Initialize adjacency list
    cityCount = maxCityID + 1;
    adjList.resize(cityCount);

    // Populate adjacency list
    for (const auto& edge : edges) {
        adjList[edge.from_city].push_back(edge);
    }

    file.close();
}

// Default constructor
Graph::Graph() : cityCount(0) {
    adjList.clear();
}

// Print graph for debugging
void Graph::printGraph() {
    for (int i = 0; i < adjList.size(); i++) {
        cout << "City " << i << ":";
        for (const auto& edge : adjList[i]) {
            cout << " -> " << edge.to_city << " (distance: " << edge.distance << ")";
        }
        cout << endl;
    }
}
