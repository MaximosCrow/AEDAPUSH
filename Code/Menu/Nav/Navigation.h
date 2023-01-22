//
// Created by bitor on 1/22/23.
//

#ifndef CODE_NAVIGATION_H
#define CODE_NAVIGATION_H
#include "../../Graph.h"
#include "../../Helpers/StringHelpers.h"


enum SOURCE_DEST{
    SOURCE,
    DESTINATION
};

string find_city(vector<Airport>, enum SOURCE_DEST);

void filter_by_city(Graph* graph);

/*
 *
 */
void filter_by_airport(Graph*);

/*
 * get airport code
 */
string airport_code(map<string, Airport*>, enum SOURCE_DEST);

/*
 * choose airline to take
 */
string choose_airline(vector<string>);

/*
 * return list of airlines capable of performing flight
 */
vector<string> airlines(vector<Flight>, const string& source, const string& dest);

/*
 *
 */
void nav(Graph*);

#endif //CODE_NAVIGATION_H
