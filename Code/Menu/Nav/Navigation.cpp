//
// Created by bitor on 1/22/23.
//

#include "Navigation.h"

void nav(Graph* graph) {

    char choice = '\0';
    do {
        cout << "\t--- NAVIGATION SUB-MENU ---" << endl;
        cout << "Choose how you may filter flights:" << endl;

        cout << "(A) -> By Airport" << endl;
        cout << "(C) -> By City" << endl;
        cout << "(I) -> By Coordinates" << endl;
        cout << "(Q) -> Go Back.." << endl;

        cin >> choice;
        choice = (char)tolower(choice);

        switch (choice) {
            case 'a':
                filter_by_airport(graph);
                break;
            case 'c':
                filter_by_city(graph);
                break;
            case 'i':
                cout << "By coordinates" << endl;
                break;
            case 'q': // break and go to return address 'menu()'
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    }while (choice != 'q');

}

void filter_by_airport(Graph* graph) {
    cout << "\t--- AIRPORT FILTER ---" << endl;

    auto source = airport_code(graph->getAirportsLocator(), SOURCE);
    auto dest = airport_code(graph->getAirportsLocator(), DESTINATION);
    auto airline = choose_airline(airlines(graph->getFlights(), source, dest));

    cout << "Source: " << source << endl << "Dest: " << dest << endl;
    if (!airline.empty()) {
        cout << "Airline: " << airline << endl;
        // TODO: show shortest path with airline

    }else{
        // TODO: show shortest path
        vector<tuple<Airport, int>> path;
        graph->getShortestPath(*graph->getAirportsLocator()[source], *graph->getAirportsLocator()[dest], path);
        for(auto tup: path){
            cout << get<0>(tup).getAirportCode() << ": " <<  get<0>(tup).getAirportName() << endl;
        }
    }


}

string airport_code(map<string, Airport*> airports, SOURCE_DEST option) {
    string code;
    while (true) {

        switch (option) {
            case SOURCE:
                cout << "Source Airport [CODE][MAX 3 LETTERS]: ";
                break;
            case DESTINATION:
                cout << "Destination Airport [CODE][MAX 3 LETTERS]: ";
                break;
        }

        cin >> code;
        code = to_upper(code);
        if (code.length() == 3 && airports[code] != nullptr) {
            cout << "Valid Code!" << endl;
            break;
        }
        cout << "Invalid Airport Code.." << endl;
    }
    return code;
}

vector<string> airlines(vector<Flight> flights, const string& source, const string& dest){

    vector<string> airlines;
    char choice = '\0';
    cout << "Any airline in particular?" << endl;
    cout << "(Y) -> Yay" << endl;
    cout << "(N) -> Nay" << endl;

    cin >> choice;

    switch (choice) {
        case 'y':
            // list airlines choices
            for (auto & flight : flights) {
                if (flight.getSource() == source && flight.getTarget() == dest) {
                    airlines.push_back(flight.getAirlineCode()); // found airline
                }
            }
            break;
        case 'n':
            cout << "No Airline Specified." << endl;
            break;
        default:
            break;
    }
    return airlines;
}

string choose_airline(vector<string> airlines) {
    if (airlines.empty()) {
        return "";
    }
    char choice;
    while(true) {
        cout << "Select any from below:" << endl;
        int i;
        for (i = 0; i < airlines.size(); i++) {
            cout << "(" << i << ")" << airlines[i] << " ";
        }
        cout << endl;

        cin >> choice;

        if (isdigit(choice) && (choice - '0') <= i && (choice - '0') >= 0) break;
        cout << "Invalid input.." << endl;
    }
    return airlines[(choice - '0')];
}

void filter_by_city(Graph* graph) {
    cout << "\t--- CITY FILTER ---" << endl;
    auto source = find_city(graph->getAirports(), SOURCE);
    auto dest = find_city(graph->getAirports(), DESTINATION);
    // TODO: bug on getshortestpath
    vector<tuple<Airport, int>>path;
    graph->cityRequest(source, dest, path);
}

string find_city(vector<Airport> airports, SOURCE_DEST option) {
    string city;
    int flag = 0;
    while (true) {
        switch (option) {
            case SOURCE:
                cout << "Source City: ";
                break;
            case DESTINATION:
                cout << "Destination City: ";
                break;
        }
        cin >> city;
        auto tmp_city = to_upper(city);
        for (auto & airport : airports) {
            if (tmp_city == to_upper(airport.getCity())) {
                cout << "Valid City" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
        cout << "Invalid City.." << endl;
    }
    return city;
}