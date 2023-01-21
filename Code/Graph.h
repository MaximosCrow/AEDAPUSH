//
// Created by carra on 21/01/2023.
//

#ifndef CODE_GRAPH_H
#define CODE_GRAPH_H

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <tuple>

#include "Airport.h"
#include "Airline.h"
#include "Flight.h"

using namespace std;

class Graph {
private:
    map<string, Airport*> airportsLocator;
    vector<Airport> airports;
    vector<Airline> airlines;
    vector<Flight> flights;
public:
    Graph(){};
    Graph(string airportFile, string flightFile, string airlineFile);
    map<string, Airport*> getAirportsLocator();
    vector<Airport> getAirports();
    vector<Airline> getAirlines();
    vector<Flight> getFlights();
    bool airportsLocatorBuilder(string airportFile);
    bool flightsBuilder(string flightsFile);
    bool airlinesBuilder(string airlinesFile);
    vector<string> split (const string& s, const string& delimiter);
    
    int getShortestPath(Airport source, Airport target, vector<tuple<Airport, int>> &path);
};




#endif //CODE_GRAPH_H
