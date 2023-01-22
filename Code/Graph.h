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
#include <cmath>
#include <algorithm>

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
    void sortByCity();
    int getShortestPath(Airport source, Airport target, vector<tuple<Airport, int>> &path);
    int getLimitedPath(Airport source, int maxFlights, vector<tuple<Airport, int>> &path);
    vector<Airport> findCityAirports(string city);
    double haversine(double lat1, double lon1, double lat2, double lon2);
    vector<Airport> locationRadius(double latitude, double longitude, int tolerance);
    void cityRequest(string source, string target, vector<tuple<Airport, int>> &path);
    void coordinatesRequest(double sourceLatitude, double sourceLongitude, int sourceTolerance, double targetLatitude, double targetLongitude, int targetTolerance, vector<tuple<Airport, int>> &path);
    set<string> countryCount(Airport airport);
};




#endif //CODE_GRAPH_H
