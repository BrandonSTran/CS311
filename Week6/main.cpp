//
//  main.cpp
//  HW 6
//
//  Created by John Maroudas on 11/19/24.
//

#include "pathcalc.h"
#include <iostream>

int main(int argc, const char *argv[]) {

  pathCalc P("city.txt", "road.txt");
  P.printInfo();
  return 0;
  P.Validate(argv[1], argv[2]);

  P.Dijkstra(argv[1], argv[2]);

  P.printInfo();

  return 0;
}
