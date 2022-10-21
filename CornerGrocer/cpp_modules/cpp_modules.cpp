//
// Created by Bret Thex on 10/17/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "../header_files/cpp_modules.h"
using namespace std;

void showMenu() {
    cout << "1: Number of Item's Purchased" << endl;
    cout << "2: Lookup Item" << endl;
    cout << "3: Create Sale Histogram" << endl;
    cout << "4: Exit Program" << endl;
    cout << "Enter you selection as a number 1, 2, 3, or 4: ";
}

int collectUserInput() {
    int userSelection;

    cin >> userSelection;
    // Check for valid input
    if (!cin || userSelection < 1 || userSelection > 4) {
        cout << "Invalid Input: please select number 1, 2, 3, or 4" << endl;
    }
    return userSelection;
}

void printHistogram() {
    ifstream fileToOpen("frequency.dat");
    string itemName;
    int itemAmount;
    unsigned int i;

    vector<string> items;
    vector <int> amounts;

    cout << endl;
    if (fileToOpen.is_open()) {
        while (fileToOpen >> itemName >> itemAmount) {

            cout << itemName << ":";
            for (i = 0; i < itemAmount; i++) {
                cout << "+";
            }
            cout << endl;
        }
        fileToOpen.close();
    }
    else {
        cout << "Could not open file.";
    }
    cout << endl;
}


