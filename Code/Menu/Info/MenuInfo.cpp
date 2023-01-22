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

        cout << "(P) -> Airplane Data" << endl;
        cout << "(L) -> Airline Data" << endl;
        cout << "(F) -> Fight Data" << endl;
        cout << "(Q) -> Go Back.." << endl;
        cin >> choice;
        choice = tolower(choice);

        switch (choice) {
            case '1':
                //airplane_data();
                break;
            case '2':
                info();
                break;
            case '3':
                break;
            case 'q': // break and go to return address 'menu()'
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    }while (choice != 'q');
}