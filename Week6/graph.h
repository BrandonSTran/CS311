//
//  graph.h
//  HW 6
//
//  Created by John Maroudas on 11/19/24.
//

#ifndef graph_h
#define graph_h

#include <list>
#include <string>
#include <vector>
using namespace std;

// object for holding city data

struct City {
  int id; //id of city
  string code; //code of city
  string name;  //name of city
  int population; //population of city
  int altitude; //
};

struct Vertex {
  int ID;     // id of city
  int weight; // weight
};

class Graph {
private:
  int V;                  // number of vertices
  vector<list<Vertex>> adjList; // adjacency list

public:
  // Purpose: constructor for adjacency list
  // Parameters: road.txt (list of adjacencies)
  Graph(string fileName);
  Graph();
  void printList();
};

#endif /* graph_h */
