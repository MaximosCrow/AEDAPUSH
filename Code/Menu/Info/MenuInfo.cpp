

#include "MenuInfo.h"



using namespace std;

void info(Graph* graph) {
    char choice = '\0';

    do {
        cout << "\t--- DATA INFO SUB-MENU ---" << endl;
        cout << "Select any from below:" << endl;

        cout << "(1) -> Airport Information" << endl;
        cout << "(2) -> Airport Airline Number" << endl;
        cout << "(Q) -> Go Back.." << endl;
        cin >> choice;
        choice = tolower(choice);

        switch (choice) {
            case '1':
                airport_info(graph);
                break;
            case '2':
                possible_locations(graph);
                break;
            case 'q': // break and go to return address 'menu()'
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    }while (choice != 'q');
}

void airport_info(Graph *pGraph) {
    string airportCode;
    Airport airportSearched;

    cout << "Input the Airport Code: ";
    cin >> airportCode;

    airportSearched = *pGraph->getAirportsLocator()[airportCode];

    cout << "________________" << airportSearched.getAirportName() << "________________" << endl;
    cout << "Number of Flights: " << airportSearched.getAirportFlights().size() << endl;
    cout << "Number of Airlines: " << airportSearched.airlineCount().size() << endl;
    cout << "Number of Countries: " << pGraph->countryCount(airportSearched).size() << endl;
    cout << "Number of Destinations: " << airportSearched.destinationCount().size() << endl;
}

void possible_locations(Graph* graph){
    string airportCode;
    string buffer;
    int maxFlights = 0;
    vector<tuple<Airport, int>> path;
    cout << "To Check All Possible places in a Given Number of Flights" << endl;
    cout << " Please Type Departure Airport Code" << endl;
    cin >> airportCode;

    cout << "Please Type Maximum Flight Number" << endl;
    cin >> buffer;
    maxFlights = stoi(buffer);

    graph->getLimitedPath(*graph->getAirportsLocator()[airportCode], maxFlights, path);

    for(auto tup: path){
        auto airport = get<0>(tup);
        auto distance = get<1>(tup);

        cout << airport.getAirportCode() << ": " << airport.getAirportName() << " At a Distance Of "<< distance << " flights" << endl;
    }

}
