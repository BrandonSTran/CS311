//
//  main.cpp
//  HW 6
//
//  Created by John Maroudas and Brandon Tran on 11/21/24.
//


#include "pathcalc.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <start_city_code> <end_city_code>" << endl;
        return 1; // Exit with error code
    }

    // Retrieve the city codes from command-line arguments
    string startCode = argv[1];
    string endCode = argv[2];

    // Initialize pathCalc with city and road files
    pathCalc P("city.txt", "road.txt");

    // Validate the city codes
    P.Validate(startCode, endCode);

    // Find and display the shortest path if the codes are valid
    P.Dijkstra(startCode, endCode);

    return 0;
}