// Jacob Williams
// COSC 2030 project 1
// Created: 10/9/2018
// Modified: 10/9/2018
//
// Main file for blood sugar project.

#include "bloodSugar.h"

int main() {

    // Initialize the data structure
    BloodSugar theBlood;

    // Introductory remarks
    cout << "Welcome to the blood-sugar tracker!" << endl;
    cout << "For the next two weeks, this program will track your blood sugar readings." << endl;
    cout << "(Of course, you will have to obtain these yourself via a Proprietary Medical Device (tm)." << endl;
    cout << "Some useful summary information about your blood sugar will also be stored." << endl << endl;

    cout << "Type 'help' or 'h' to see a list of commands. 'exit' or 'e' will exit the program." << endl << endl;

    // We can use cin to read into either of these, as we like.
    double val;
    char command;

    int curr = theBlood.getCurrentDay();

    while (curr < 14) {
        if (cin >> val) {
            theBlood.addToDay(val);
            theBlood.addToWeek(val);
        } else {
            cin.clear();
            cin >> command;
            if (val == 'n' || val == 'N') {
            } else if (val == 'd' || val == 'D') {
                theBlood.printDay();
            } else if (val == 'w' || val == 'W') {
                theBlood.printWeek();
            } else if (val == 'h' || val == 'H') {
                // theBlood.showCommands();
            } else if (val == 'e' || val == 'E') {
                cout << "Exiting." << endl;
                return 0;
            } else {
                cin.clear();
                cin.ignore();
            }
        }
    }

    return 0;
}
