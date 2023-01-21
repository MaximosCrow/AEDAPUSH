//
// Created by carra on 04/01/2023.
//

#ifndef CODE_AIRLINE_H
#define CODE_AIRLINE_H

#include <string>

using namespace std;

class Airline {
private:
    string airlineCode;
    string airlineName;
    string airlineCallsign;
    string airlineCountry;
public:
    Airline(){};
    Airline(string airlineCode, string airlineName, string airlineCallsign, string airlineCountry);
    string getAirlineCode();
    string getAirlineName();
    string getAirlineCallsign();
    string getAirlineCountry();
    void setAirlineCode(string code);
    void setAirlineName(string name);
    void setAirlineCallsign(string callsign);
    void setAirlineCountry(string country);

};


#endif //CODE_AIRLINE_H
