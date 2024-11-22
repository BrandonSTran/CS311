//
//  pathCalc.h
//  HW 6
//
//  Created by John Maroudas on 11/19/24.
//

#ifndef pathCalc_h
#define pathCalc_h

#include "graph.h"
#include <string>
#include <vector>
using namespace std;


struct City {
  int id; //id of city
  string code; //code of city
  string name;  //name of city
  int population; //population of city
  int altitude; //
};

class pathCalc {
private:
  Graph map; // adjacency list of all cities
  // Distance Table d
  // Visited Set S

  vector<City> cities; // contains data for all cities

public:
  // Purpose: constructor for intitializing adjacency list and vector of cities
  // Parameters: city.txt (list of cities with data)
  //             road.txt (list of adjacencies)
  pathCalc(string cityFile, string roadFile);

  // Purpose: parses city.txt and fills cities vector with data
  // Paramters: city.txt
  void readCities(string filename);
  // Purpose:  finds shortest path between the given cities using
  //           Dijkstra's algorithm
  // Paramters: City codes for starting point and destination
  void Dijkstra(string start, string end);

  // Purpose: Checks if a city code exists in the list, returns true if found
  // Parameters: city code (two characters)
  void Validate(string cityCode1, string cityCode2);

  // Purpose: prints message and shortest path between given cities
  //  Parameters:
  void printInfo();

  // Purpose: converts string city code to integer Id and returns Id
  // paramters: city code (two characters)
  int convertCode(string cityCode);
};

#endif /* pathCalc_h */
