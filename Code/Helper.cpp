//
// Created by carra on 21/01/2023.
//

#include "Graph.h"


struct
{
    bool operator()(Airport a, Airport b) const {
        if(a.getCity() < b.getCity()){
            return true;
        }
        return false;
    }
}
        compareAirportCity;


