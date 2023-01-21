//
// Created by carra on 04/01/2023.
//

#include "Airport.h"

Airport::Airport(string airportCode, string airportName, string city, string country, double latitude, double longitude) {
    this->airportCode = airportCode;
    this->airportName = airportName;
    this->airportCity = city;
    this->airportCountry = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

string Airport::getAirportCode() {
    return airportCode;
}

string Airport::getAirportName() {
    return airportName;
}

string Airport::getCity() {
    return airportCity;
}

string Airport::getCountry() {
    return airportCountry;
}

double Airport::getLatitude() {
    return latitude;
}

double Airport::getLongitude() {
    return longitude;
}


vector<Flight*> Airport::getAirportFlights() {
    return this->airportFlights;
}

void Airport::setAirportCode(string code) {
    this->airportCode = code;
}

void Airport::setAirportName(string name) {
    this->airportName = name;
}

void Airport::setCity(string city) {
    this->airportCity = city;
}

void Airport::setCountry(string country) {
    this->airportCountry = country;
}

void Airport::setLatitude(double latitude) {
    this->latitude = latitude;
}

void Airport::setLongitude(double longitude) {
    this->longitude = longitude;
}

bool Airport::addFlightToAirport(Flight *flight) {
    int nFlights = airportFlights.size();

    airportFlights.push_back(flight);
    if(airportFlights.size() <= nFlights){
        cout << "Flight Add Failed" << endl;
        return false;
    }
    return true;
}

bool Airport::operator==(const Airport &airport) const {
    if(this->airportCode == airport.airportCode) return true;
    return false;
}



/*
 *  To make OSTREAM Operator
 *
 * Airport airport = Airport("lol","lol","lol","lol",1,1);
    cout << airport.getAirportCode() << endl;
    cout << airport.getAirportName() << endl;
    cout << airport.getCity() << endl;
    cout << airport.getCountry() << endl;
    cout << airport.getLatitude() << endl;
    cout << airport.getLongitude() << endl;
 *
 *
 *
 * */
