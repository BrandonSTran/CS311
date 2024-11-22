//
//  pathCalc.cpp
//  HW 6
//
//  Created by John Maroudas on 11/21/24.
//


#include "pathcalc.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

pathCalc::pathCalc(string cityFile, string roadFile) : map(roadFile) {
    readCities(cityFile); // Parse city data from file
}

//read in cities into vector
void pathCalc::readCities(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        City city;

        // Parse each line based on the structure in city.txt
        ss >> city.ID >> city.City_code >> city.City_name >> city.Population >> city.Elevation;

        // Add the parsed city to the vector
        cities.push_back(city);
    }

    file.close();
}

//checks if city code given is in list of cities
void pathCalc::Validate(string cityCode1, string cityCode2) {
    bool found1 = false, found2 = false;

    for (const auto &city : cities) {
        if (city.City_code == cityCode1) {
            found1 = true;
        }
        if (city.City_code == cityCode2) {
            found2 = true;
        }
    }

    if (!found1) {
        cerr << "Invalid city code: " << cityCode1 << endl;
    }
    if (!found2) {
        cerr << "Invalid city code: " << cityCode2 << endl;
    }
    if (!found1 || !found2) {
        exit(1); // Exit if invalid codes are provided
    }
}

//converts city code into id
int pathCalc::convertCode(string cityCode) {
    for (const auto &city : cities) {
        if (city.City_code == cityCode) {
            return city.ID;
        }
    }
    cerr << "Error: City code " << cityCode << " not found." << endl;
    return -1; // Return -1 if the city code does not exist
}

//calculates the shortest path from one city to another
void pathCalc::Dijkstra(string start, string end) {
    const auto &adjList = map.getAdjList(); // Access adjacency list
    int V = map.getCityCount();          // Access City count

    int fromID = convertCode(start);
    int toID = convertCode(end);

    if (fromID == -1 || toID == -1) {
        cerr << "Invalid city codes provided." << endl;
        return;
    }

    vector<int> distances(V, INT_MAX);
    vector<int> previous(V, -1);

    distances[fromID] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, fromID});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentCity = pq.top().second;
        pq.pop();

        for (const auto &edge : adjList[currentCity]) {
            int nextCity = edge.to_city;
            int edgeDist = edge.distance;

            if (currentDist + edgeDist < distances[nextCity]) {
                distances[nextCity] = currentDist + edgeDist;
                previous[nextCity] = currentCity;
                pq.push({distances[nextCity], nextCity});
            }
        }
    }

  
  string startCityName;
  string endCityName;
  for (const auto &city : cities) {
    if (city.City_code == start) {
      startCityName = city.City_name;
    }
    if (city.City_code == end) {
      endCityName = city.City_name;
    }
  }
    //checks if there is a path from start location to destination
    if (distances[toID] == INT_MAX) {
        printInfo(start, end);
        cout << "No route from " << startCityName << " and " << endCityName << endl;
        return;
    }

    // Reconstruct path
    vector<int> path;
    for (int at = toID; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // Print shortest path and total distance
    printInfo(start, end);
    cout << "The shortest distance from " << startCityName
         << " to " << endCityName << " is " 
         << distances[toID] << endl;


    cout << "through the route: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << cities[path[i]].City_name;
        if (i < path.size() - 1) cout << "->";
    }
    cout << endl;
}


//prints info about group and city
void pathCalc::printInfo(string start, string end) {
  const City* startCity = nullptr;
  const City* endCity = nullptr;

  for (const auto &city : cities) {
    if (city.City_code == start) {
      startCity = &city;
    }
    if (city.City_code == end) {
      endCity = &city;
    }
  }

  //prints group information
  cout << "Author: John Maroudas and Brandon Tran" << endl
       << "Date: 11/22/2024" << endl
       << "Course: CS311 (Data structures and Algorithms)" << endl
       << "Description: Program to find the shortest route between cities" << endl
       << "---------------------------------------------------------------" << endl;

  //print city information
  cout << "From City: " << startCity->City_name
       << ", population " << startCity->Population
       << ", elevation " << startCity->Elevation << endl;
  
  cout << "To City: " << endCity->City_name
       << ", population " << endCity->Population
       << ", elevation " << endCity->Elevation << endl;
}