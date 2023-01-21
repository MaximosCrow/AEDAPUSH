#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph("..//Data//airports.csv", "..//Data//flights.csv", "..//Data//airlines.csv");

    auto source = graph.getAirportsLocator()["OPO"];
    auto target = graph.getAirportsLocator()["DXB"];

    vector<tuple<Airport, int>> path;

    cout << source->getAirportFlights().size()<<endl;
    cout << target->getAirportFlights().size()<<endl;
    cout << graph.getShortestPath(*source, *target, path);





/*
    for(auto &kv : graph.getAirportsLocator()){
        auto f = kv.first;
        auto s = kv.second;

        cout << "____________" << endl;
        cout << f << endl;
        cout << s->getAirportName() << endl;

        for (auto flight : s->getAirportFlights()) {
            cout << flight->getSource() << "------>" << flight->getTarget() << endl;
        }
        cout << "____________" << endl;
    }
    */
    return 0;
}
