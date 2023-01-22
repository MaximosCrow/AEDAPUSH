//
// Created by carra on 04/01/2023.
//

#ifndef CODE_AIRPORT_H
#define CODE_AIRPORT_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Flight.h"



using namespace std;

class Airport {
private:
    string airportCode;
    string airportName;
    string airportCity;
    string airportCountry;
    double latitude;
    double longitude;
    vector<Flight*> airportFlights;
public:
    Airport(){};
    Airport(string airportCode, string airportName, string city, string country, double latitude, double longitude);
    string getAirportCode();
    string getAirportName();
    string getCity();
    string getCountry();
    double getLatitude();
    double getLongitude();
    vector<Flight*> getAirportFlights();
    void setAirportCode(string code);
    void setAirportName(string name);
    void setCity(string city);
    void setCountry(string country);
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    bool addFlightToAirport(Flight *flight);
    void sortByAirline();
    set<string> airlineCount();
    set<string> destinationCount();
    bool operator == (const Airport &airport) const;

};



#endif //CODE_AIRPORT_H
