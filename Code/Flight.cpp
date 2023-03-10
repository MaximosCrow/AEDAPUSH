//
// Created by carra on 04/01/2023.
//

#include "Flight.h"

Flight::Flight(int flightID, string source, string target, string airlineCode) {
    this->flightID = flightID;
    this->source = source;
    this->target = target;
    this->airlineCode = airlineCode;
}

string Flight::getSource() {
    return source;
}

string Flight::getTarget() {
    return target;
}

string Flight::getAirlineCode() {
    return airlineCode;
}

void Flight::setSource(string source) {
    this->source = source;
}

void Flight::setTarget(string target) {
    this->target = target;
}

void Flight::setAirlineCode(string code) {
    this->airlineCode = code;
}

bool Flight::operator==(const Flight &flight) const {
    if(this->flightID == flight.flightID)
        return true;
    cout << "returned false on flight id operator ==" <<  endl;
    return false;
}

bool Flight::operator<(const Flight &flight) const {
            if(this->airlineCode < flight.airlineCode){
                return true;
            }
            return false;
        }


