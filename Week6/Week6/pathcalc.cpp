#include "pathcalc.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

pathCalc::pathCalc(string cityFile, string roadFile) : map(roadFile) {
  readCities(cityFile); // loop and fill this->cities
}

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

    // Parse each line based on the structure
    ss >> city.id >> city.code >> city.name >> city.population >> city.altitude;

    // Add the parsed city to the vector
    cities.push_back(city);
  }

  file.close();

  // Debugging: Print the cities to verify
  for (const auto &city : cities) {
    cout << "ID: " << city.id << ", Code: " << city.code
         << ", Name: " << city.name << ", Population: " << city.population
         << ", Altitude: " << city.altitude << endl;
  }
}

void pathCalc::printInfo() {}
