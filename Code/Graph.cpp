//
// Created by carra on 21/01/2023.
//


#include "Graph.h"


struct comparator
{
    bool operator()(Airport a, Airport b) const {
        if(a.getCity() < b.getCity()){
            return true;
        }
        return false;
    }
}compareAirportCity;



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

double Graph::haversine(double lat1, double lon1,
                        double lat2, double lon2)
{
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
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


        for(auto neighbor : airport.getAirportFlights()){
            if(visited.find(neighbor->getTarget()) == visited.end()){
                visited.insert(neighbor->getTarget());
                finder.push(make_tuple(*airportsLocator[neighbor->getTarget()], numberOfFlights + 1)); //missing dist
            }
        }
        temp = current;
    }
    return -1;
}

void Graph::sortByCity() {
    sort(this->airports.begin(), this->airports.end(), compareAirportCity);
}

vector<Airport> Graph::findCityAirports(string city) {
    map<string, vector<Airport>> countriesMap;
    string selected;
    vector<Airport> singleLookUp;

    sortByCity();
    for(auto airport: airports){
        if(airport.getCity() == city){
            vector<Airport> tempOld = countriesMap[airport.getCountry()];
            tempOld.push_back(airport);
            countriesMap[airport.getCountry()] = tempOld;
            singleLookUp.push_back(airport);
        }
    }

    cout << selected << endl;

    if(countriesMap.size() > 1){
        cout << "Specify Country" << endl;
        for(auto &kv : countriesMap){
            cout << kv.first << endl;
        }
        getline(cin, selected);
    }else if(countriesMap.size() == 1){
        cout << city << ": Has Only One Airport --> "<< singleLookUp[0].getAirportCode() << " " << singleLookUp[0].getAirportName() <<endl;
    } else{
        vector<Airport> emptyVec;
        cout <<  "Empty Vector" << endl;
    }

    for(auto source: countriesMap[selected]){
        cout << source.getAirportCode() << ": " << source.getAirportName() << "--->" << source.getCity() << endl;
    }
/*
    for(auto it: countriesMap){
        cout << it.first << endl;
        for(auto s : it.second){
            cout << s.getAirportCode() << endl;
            cout << "_____________" << endl;
        }
    }
*/
    return countriesMap[selected];
}

void Graph::getLimitedPath(Airport source, int maxFlights, vector<tuple<Airport, int>> &path) {
    queue<tuple<Airport, int>> finder;
    set<string> visited;

    tuple<Airport, int>  temp = make_tuple(source,0); //opo

    visited.insert(source.getAirportCode());

    finder.push(make_tuple(source,0));

    while(get<1>(temp) <= maxFlights){
        auto current = finder.front();
        finder.pop();

        auto airport = get<0>(current);
        auto numberOfFlights = get<1>(current);

        if(numberOfFlights > maxFlights) break;

        path.push_back(temp);

        for(auto neighbor : airport.getAirportFlights()){
            if(visited.find(neighbor->getTarget()) == visited.end()){
                visited.insert(neighbor->getTarget());
                finder.push(make_tuple(*airportsLocator[neighbor->getTarget()], numberOfFlights + 1)); //missing dist
            }
        }
        temp = current;
    }
    path.erase(path.begin() +1);
}

vector<Airport> Graph::locationRadius(double latitude, double longitude, int tolerance) {
    vector<Airport> airportsNear;
    for(auto airport: airports){
        auto result = haversine(latitude, longitude, airport.getLatitude(), airport.getLongitude());
        if(result <= tolerance){   //COMPARING DOUBLE TO INT
            airportsNear.push_back(airport);
        }
    }

    for(auto source: airportsNear){
        cout << source.getAirportCode() << ": " << source.getAirportName() << "--->" << source.getCity() << endl;
    }
    return airportsNear;
}

void Graph::cityRequest(string source, string target, vector<tuple<Airport, int>> &path) {
    string departure, destination;

    vector<Airport> sourceAirports = this->findCityAirports(source);
    cout << "Please Choose the Airport Code of a Departure Point" << endl;
    getline(cin, departure);


    vector<Airport> targetAirports = this->findCityAirports(target);
    cout << "Please Choose the Airport Code of a Destination Point" << endl;
    getline(cin, destination);

    getShortestPath(*airportsLocator[departure], *airportsLocator[destination], path);

}


void Graph::coordinatesRequest(double sourceLatitude, double sourceLongitude, int sourceTolerance, double targetLatitude, double targetLongitude, int targetTolerance, vector<tuple<Airport, int>> &path){
    string departure, destination;

    auto sourceAirports = locationRadius(sourceLatitude, sourceLongitude, sourceTolerance);
    cout << "Please Choose the Airport Code of a Departure Point" << endl;
    getline(cin, departure);

    auto targetAirports = locationRadius(targetLatitude, targetLongitude, targetTolerance);
    cout << "Please Choose the Airport Code of a Destination Point" << endl;
    getline(cin, destination);

    getShortestPath(*airportsLocator[departure], *airportsLocator[destination], path);
}


/*

 for(auto target: targetAirports){
        cout << target.getAirportCode() << ": " << target.getAirportName() << "--->" << target.getCity() << endl;
    }


vector<vector<tuple<Airport, int>>> allPaths;
    vector<tuple<Airport, int>> path;

    for(auto source : sourceAirports){
        for(auto target : targetAirports){
            getShortestPath(source, target, path);
            if(allPaths.empty()){
                allPaths.push_back(path);
                continue;
            }
            if(path < *allPaths.crend()){
                allPaths.push_back(path);
            }
        }
    }

    cout <<  "These are the best Paths" << endl;
    for(auto vec : allPaths){
        for(auto lastPath : vec){
            cout << '(' << get<0>(lastPath).getAirportCode() << ',' << get<1>(lastPath) <<')' << "->";
        }
        cout << "___________________________________________" << endl;
    }

 *string selectedCountry;
    set<string> countries;
    vector<Airport> cityAirports;
    vector<Airport> finalAirports;
    auto it = airports.begin();

    while(it != airports.end()){
        if(it->getCity() == city){
            cityAirports.push_back(*it);
            countries.insert(it->getCountry());


        }
        it++;
    }

    if(countries.size() > 1){
        cout << "Specify Country" << endl;
        for(auto country : countries){
            cout << country << endl;
        }
        cin >> selectedCountry;
    }

    for(auto airport : cityAirports){
        cout << airport.getCountry() << " 2 ";
        if(airport.getCountry() == selectedCountry){
            finalAirports.push_back(airport);
            cout << airport.getAirportCode() << endl;
        }
    }
 *
 *
 *vector<Airport> cityAirports;

    int count = 0;

    while (auto it = find_if(airports.begin(), airports.end(), predicate) != airports.end()){
        cityAirports.push_back(it))
        it++;
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









