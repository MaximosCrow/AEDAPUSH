//
// Created by bitor on 1/22/23.
//

#include "MenuInfo.h"

using namespace std;

void info() {
    char choice = '\0';

    do {
        cout << "\t--- DATA INFO SUB-MENU ---" << endl;
        cout << "Select any from below:" << endl;

        cout << "(P) -> Airport Flight Number" << endl;
        cout << "(L) -> Airport Airline Number" << endl;
        cout << "(F) -> Airport Destination Number" << endl;
        cout << "(N) -> Reachable Airports With N Flights" << endl;
        cout << "(Q) -> Go Back.." << endl;
        cin >> choice;
        choice = tolower(choice);

        switch (choice) {
            case '1':
                cout << "Insert Airport Code" << endl;

                break;
            case '2':
                //airline_data();
                break;
            case '3':
                //flight_data();
                break;
            case 4:

                break;
            case 'q': // break and go to return address 'menu()'
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    }while (choice != 'q');
}

