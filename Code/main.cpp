#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph("..//Data//airports.csv", "..//Data//flights.csv", "..//Data//airlines.csv");


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
    return 0;
}
