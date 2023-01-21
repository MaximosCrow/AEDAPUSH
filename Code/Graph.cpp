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

int Graph::getShortestPath(Airport source, Airport target, vector<tuple<Airport, int>> &path) {
    queue<tuple<Airport, int>> finder;
    set<string> visited;


    tuple<Airport, int>  temp = make_tuple(source,0); //opo

    //visited.clear();
    visited.insert(source.getAirportCode());

    finder.push(make_tuple(source,0));

    while(finder.size() > 0){
        auto current = finder.front();
        finder.pop();

        auto airport = get<0>(current);
        auto numberOfFlights = get<1>(current);

        if(get<1>(temp) < numberOfFlights){
            path.push_back(temp);
        }

        //cout << '(' << airport.getAirportCode() << ',' << numberOfFlights <<')' << " ";

        if(airport == target){

            //cout << "MAAATTCCH" << endl;

            path.push_back(make_tuple(target,numberOfFlights));
            for(auto it : path){
                //cout << get<0>(it).getAirportCode() << endl;
            }
            return numberOfFlights;

        }

        //cout << airport.getAirportCode() << endl;



        for(auto neighbor : airport.getAirportFlights()){
            if(visited.find(neighbor->getTarget()) == visited.end()){


                //cout << neighbor->getTarget() << endl;
                //cout << "___________________________" << endl;


                visited.insert(neighbor->getTarget());
                finder.push(make_tuple(*airportsLocator[neighbor->getTarget()], numberOfFlights + 1)); //missing dist

            }
        }
        temp = current;
    }
/*
    for(auto it : visited){
        cout << it << '/' ;
    }
    cout<< visited.size() << endl;
*/
    return -1;
}




    /*
     *
     *
     *
     *
     *
     *
     *
     * list<string> path;
    queue<tuple<Airport, int>> finder;
    int distance = 1;

    tuple<Airport, int> node = make_tuple(source,distance);

    if(get<0>(node) == target) return get<1>(node);
    if(visited.find(get<0>(node).getAirportCode()) != visited.end()) return 0;

    visited.insert(get<0>(node).getAirportCode());


    for(Flight *flight: get<0>(node).getAirportFlights()){
        if(1 < getShortestPath(*airportsLocator[flight->getTarget()], target, visited))
            return get<1>(node);



    }

    return -1;




    vector<Airport> path;
    set<string> visited;
    queue<Airport> finder;
    int numberOfFlights = 0;

    finder.push(source);
    visited.insert(source.getAirportCode());


    while(!finder.empty()){
        source = finder.front();
        finder.pop();

        if(source == target){
            return numberOfFlights;
        }

        for(Flight *flight: source.getAirportFlights()){
            if(visited.find(flight->getTarget()) == visited.end()){
                finder.push(*airportsLocator[flight->getTarget()]);
                visited.insert(flight->getTarget());
                numberOfFlights++;
                path.push_back(*airportsLocator[flight->getSource()]); // nao sei se esta certo
            }
        }
    }








    list<Airport> path;
    set<Airport> visited;
    queue<tuple<Airport, int>> finder;
    int distance = 1;

    tuple<Airport, int> node = make_tuple(a,distance);

    finder.push(node);
    visited.insert(a);


    while(finder.size() > 0){
        finder.pop(); // nao essquecer de no fim add a queue
        if(a == b){
            return get<1>(node);
        }



        for(Flight flight: airports[get<0>(node)]){
            if(visited.find(airportsLocator[get<0>(node).airportCode]) == visited.end()){
                visited.insert(get<0>(node));
                finder.push(make_tuple(airportsLocator[flight.getAirlineCode()], distance++));
                path.push_back(airportsLocator[flight.getAirlineCode()]);
            }
        }
    }





    list<Flight> path;
    set<tuple<Airport, list<Flight>>> visited;
    queue<tuple<Airport, list<Flight>>> queue;

    for (auto i = airports.begin(); i != airports.end(); i++) {
        queue.push(tuple<Airport, list<Flight>>{i->first, i->second});

        while (queue.size() > 0) {
            auto [currentNode, path] = queue.front();
            queue.pop();

            if (currentNode == b) {
                return path;
            }
            auto j = i++;
            if (visited.size() >= 0) {
                visited.insert(tuple<Airport, list<Flight>>{j->first, j->second});
                queue.push(tuple<Airport, list<Flight>>{j->first, path});
            }
            visited.insert(tuple<Airport, list<Flight>>{i->first, i->second});
        }
    //visited.insert(i->first);

}


    for(auto &kv : airportsLocator) {
        auto f = kv.first;
        auto s = kv.second;

        cout << f << endl;
        cout << s << endl;
    }
     */









