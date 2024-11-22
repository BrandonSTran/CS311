#include "graph.h"
#include <fstream>
#include <iostream>
#include <sstream>

Graph::Graph(string fileName) {
  // Open the file
  ifstream file(fileName);
  if (!file.is_open()) {
    cerr << "Error: Could not open file " << fileName << endl;
    return;
  }

  // Find the maximum vertex ID to determine the size of the adjacency list
  int maxVertex = 0;
  string line;
  vector<tuple<int, int, int>> edges; // Temporary storage for edges
  while (getline(file, line)) {
    stringstream ss(line);
    int u, v, weight;
    ss >> u >> v >> weight;

    edges.push_back({u, v, weight});
    maxVertex = max(maxVertex, max(u, v));
  }

  // Initialize adjacency list
  V = maxVertex + 1;
  G.resize(V);

  // Populate adjacency list
  for (const auto &[u, v, weight] : edges) {
    G[u].push_back({v, weight});
    // Uncomment the following line if the graph is undirected:
    // G[v].push_back({u, weight});
  }

  printList();
  file.close();
}

Graph ::Graph() : V(0) { G.clear(); }

void Graph::printList() {
  // Print the adjacency list
  for (size_t i = 0; i < G.size(); ++i) {
    cout << "Vertex " << i << ": ";
    for (const auto &neighbor : G[i]) {
      cout << "(ID: " << neighbor.ID << ", Weight: " << neighbor.weight << ") ";
    }
    cout << endl;
  }
}
