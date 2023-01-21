//
// Created by carra on 04/01/2023.
//

#ifndef CODE_FLIGHT_H
#define CODE_FLIGHT_H

#include <string>
#include <iostream>

using namespace std;

class Flight {
private:
    int flightID;
    string source;
    string target;
    string airlineCode;
public:
    Flight(){};
    Flight(int flightID, string source, string target, string airlineCode);
    string getSource();
    string getTarget();
    string getAirlineCode();
    void setSource(string source);
    void setTarget(string target);
    void setAirlineCode(string code);
    bool operator == (const Flight &flight) const;
    bool operator < (const Flight &flight) const;
};


#endif //CODE_FLIGHT_H
