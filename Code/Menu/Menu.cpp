//
// Created by bitor on 1/21/23.
//

#include "Menu.h"
#include <iostream>

using namespace std;


void menu(Graph* graph) {

    char choice = '\0';
    do {
        cout << "\t--- MENU ---" << endl;
        cout << "Select any from below:" << endl;
        cout << "(N) -> Navigation" << endl;
        cout << "(I) -> Data Info" << endl;
        cout << "(Q) -> Exit" << endl;

        cin >> choice; // grab input from user
        choice = (char)tolower(choice); // make sure that both upper and lower case letters are handled

        switch (choice) {
            case 'n':
                nav(graph);
                break;
            case 'i':
                info(graph);
                break;
            case 'q':
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while(choice != 'q');

}

