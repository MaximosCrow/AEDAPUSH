//
// Created by carra on 04/01/2023.
//

#include "Airline.h"

Airline::Airline(string airlineCode, string airlineName, string airlineCallsign, string airlineCountry) {
    this->airlineCode = airlineCode;
    this->airlineName = airlineName;
    this->airlineCallsign = airlineCallsign;
    this->airlineCountry = airlineCountry;
}

string Airline::getAirlineCode() {
    return airlineCode;
}

string Airline::getAirlineName() {
    return airlineName;
}

string Airline::getAirlineCallsign() {
    return airlineCallsign;
}

string Airline::getAirlineCountry() {
    return airlineCountry;
}

void Airline::setAirlineCode(string code) {
    this->airlineCode = code;
}

void Airline::setAirlineName(string name) {
    this->airlineName = name;
}

void Airline::setAirlineCallsign(string callsign) {
    this->airlineCallsign = callsign;
}

void Airline::setAirlineCountry(string country) {
    this->airlineCountry = country;
}



/* OSTREAM
 *
 *
 *
 * Airline airline = Airline("lol","LOL","lol","lol");
    cout << airline.getAirlineCode() << endl;
    cout << airline.getAirlineName() << endl;
    cout << airline.getAirlineCallsign() << endl;
    cout << airline.getAirlineCountry() << endl;
 *
 *
 *
 * */