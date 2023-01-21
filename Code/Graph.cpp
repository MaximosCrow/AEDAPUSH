//
// Created by carra on 21/01/2023.
//



#include "Graph.h"

Graph::Graph(string airportFile, string flightFile, string airlineFile) {
    if(!airportsLocatorBuilder(airportFile))
        cout << "Graph Constructor Failed on Airport Locator Builder" << endl;

    if(!flightsBuilder(flightFile))
        cout << "Graph Constructor Failed on Flight Builder" << endl;

    if(!airlinesBuilder(airlineFile))
        cout << "Graph Constructor Failed on Airline Builder" << endl;
}

map<string, Airport *> Graph::getAirportsLocator() {
    return this->airportsLocator;
}

vector<Airport> Graph::getAirports() {
    return this->airports;
}

vector<Airline> Graph::getAirlines() {
    return this->airlines;
}

vector<Flight> Graph::getFlights() {
    return this->flights;
}

bool Graph::airportsLocatorBuilder(string airportFile) {
    ifstream file;
    string stringBuffer;
    vector<string> stringSplit;

    file.open(airportFile);
    if(!file.is_open()){
        cout << "Unable to Open File" << endl;
        return false;
    }

    getline(file, stringBuffer);
    while(getline(file, stringBuffer)) {
        vector<string> splitString = split(stringBuffer, ",");
        Airport *airport = new Airport(splitString[0], splitString[1], splitString[2], splitString[3], stod(splitString[4]),stod(splitString[5]));

        airportsLocator[airport->getAirportCode()] = airport;
        airports.push_back(*airport);
    }

    file.close();
    return true;
}

bool Graph::flightsBuilder(string flightsFile) {
    ifstream file;
    string stringBuffer;
    vector<string> stringSplit;
    unsigned count = 0;

    file.open(flightsFile);
    if(!file.is_open()){
        cout << "Unable to Open File" << endl;
        return false;
    }

    getline(file, stringBuffer);
    while(getline(file, stringBuffer)) {
        vector<string> splitString = split(stringBuffer, ",");
        Flight *flight = new Flight(count,splitString[0], splitString[1], splitString[2]);
        flights.push_back(*flight);
        airportsLocator[flight->getSource()]->addFlightToAirport(flight);
        count++;
    }
    file.close();
    return true;
}

bool Graph::airlinesBuilder(string airlinesFile) {
    ifstream file;
    string stringBuffer;
    vector<string> stringSplit;

    file.open(airlinesFile);
    if(!file.is_open()){
        cout << "Unable to Open File" << endl;
        return false;
    }

    getline(file, stringBuffer);
    while(getline(file, stringBuffer)){
        vector<string> splitString = split(stringBuffer, ",");
        Airline airline = Airline(splitString[0], splitString[1], splitString[2], splitString[3]);
        airlines.push_back(airline);
    }
    file.close();
    return true;
}



vector<string> Graph::split(const string &s, const string &delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    return res;
}








