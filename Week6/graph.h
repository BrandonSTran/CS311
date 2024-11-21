//
//  graph.h
//  HW 6
//
//  Created by John Maroudas on 11/19/24.
//

#ifndef graph_h
#define graph_h

#include <string>
#include <vector>
#include <list>
using namespace std;


using namespace std;

struct Vertex {
    int ID; // id of city
    int weight; // weight
};



class graph {
private:
    int V; // number of vertices
    vector<list<Vertex>> G; // adjacency list
   
public:
    //Purpose: constructor for adjacency list
    //Parameters: road.txt (list of adjacencies)
    graph(string fileName);

};






#endif /* graph_h */

