//
//  pathCalc.h
//  HW 6
//
//  Created by John Maroudas and Brandon Tran on 11/21/24.
//

#ifndef pathCalc_h
#define pathCalc_h

#include "graph.h"
#include <string>
#include <vector>
using namespace std;

// Struct to represent a city
struct City {
    int ID;         // ID of the city
    string City_code;    // Code of the city 
    string City_name;    // Full name of the city
    int Population; // Population of the city
    int Elevation;   // Altitude of the city
};

class pathCalc {
private:
    Graph map;                // Graph representing the adjacency list of all cities
    vector<City> cities;      // Vector containing data for all cities

public:
    // Constructor: Initializes the adjacency list and vector of cities
    // Parameters:
    //   - cityFile: File containing city information
    //   - roadFile: File containing road adjacency information
    pathCalc(string cityFile, string roadFile);

    // Parses the city file and populates the `cities` vector
    void readCities(string filename);

    // Validates if the given city codes exist in the `cities` vector
    // Parameters:
    //   - cityCode1: Code of the first city
    //   - cityCode2: Code of the second city
    void Validate(string cityCode1, string cityCode2);

    // Converts a city code to its corresponding city ID
    // Parameters:
    //   - cityCode: Code of the city
    // Returns: City ID if found, or -1 if not found
    int convertCode(string cityCode);
    
    // Finds the shortest path between two cities using Dijkstra's algorithm
    // Parameters:
    //   - start: City code for the starting point
    //   - end: City code for the destination
    void Dijkstra(string start, string end);

    // Prints information about the graph and cities
    //Parameters:
    //  -start: city code for starting point
    //  -end: city code for destination
    void printInfo(string start, string end);
};

#endif /* pathCalc_h */
