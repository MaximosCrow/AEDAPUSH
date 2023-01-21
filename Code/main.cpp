#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph("..//Data//airports.csv", "..//Data//flights.csv", "..//Data//airlines.csv");

    auto source = graph.getAirportsLocator()["OPO"];
    auto target = graph.getAirportsLocator()["DXB"];

    vector<tuple<Airport, int>> path;




    /*
    graph.sortByCity();

    cout<< graph.findCityAirports("London").size() << endl;



//FlIGHT SORTING NOT TESTED




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
