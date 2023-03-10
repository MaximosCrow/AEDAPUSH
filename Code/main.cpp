
#include <iostream>
#include <fstream>
#include <string.h>

#include "Graph.h"
#include "Menu/Menu.h"


using namespace std;


int main() {

    Graph graph("..//Data//airports.csv", "..//Data//flights.csv", "..//Data//airlines.csv");
    menu(&graph);

    /*
     *
     *
     * auto source = graph.getAirportsLocator()["OPO"];
    auto target = graph.getAirportsLocator()["DXB"];


    vector<tuple<Airport, int>> path;

   graph.coordinatesRequest(source->getLatitude(), source->getLongitude(), 400, target->getLatitude(), target->getLongitude(), 400, path);

    for(auto thing : path){
        cout << get<0>(thing).getAirportCode() << ':' << get<1>(thing) << endl;
    }
*/

    /*
     *
     *
     *  for(auto airport : graph.locationRadius(source->getLatitude(), source->getLongitude(), 1000)){
        cout << airport.getAirportCode() << ':' << airport.getCountry() << endl;
    }
     *
     *
     *graph.getLimitedPath(*source, 2, path);
     *
     *  for(auto thing : path){
        cout << get<0>(thing).getAirportCode() << ':' << get<1>(thing) << endl;
    }


    for(auto  flight : source->getAirportFlights()){
        cout << flight->getTarget() << ":  " <<  flight->getAirlineCode()<< endl;
    }




     *
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
