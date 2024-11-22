//
//  graph.h
//  HW 6
//
//  Created by John Maroudas and Brandon Tran on 11/21/24.
//


#ifndef graph_h
#define graph_h

#include <list>
#include <string>
#include <vector>
using namespace std;

struct Edge {
    int from_city;  // Source city ID
    int to_city;    // Destination city ID
    int distance;   // Distance between the cities
};

class Graph {
private:
    int cityCount;                    // Number of cities
    vector<list<Edge>> adjList;     // Adjacency list storing edges

public:
    Graph(string fileName);           // Constructor to initialize graph from file
    Graph();                          // Default constructor
    void printGraph();                // Print adjacency list for debugging

    // Getter for adjacency list
    const vector<list<Edge>>& getAdjList() const {
        return adjList;
    }

    // Getter for city count
    int getCityCount() const {
        return cityCount;
    }
};

#endif /* graph_h */
