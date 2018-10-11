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
    cout << endl << "Welcome to the blood-sugar tracker!" << endl;
    cout << "For the next two weeks, this program will track your blood sugar readings." << endl;
    cout << "(Of course, you will have to obtain these yourself via a Proprietary Medical Device (tm)." << endl;
    cout << "Some useful summary information about your blood sugar will also be stored." << endl << endl;

    cout << "Type 'h' or 'H' to see a list of commands. 'e' or 'E' will exit the program." << endl << endl;

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
            if (command == 'n' || command == 'N') {
                theBlood.nextDay();
                curr = theBlood.getCurrentDay();
            } else if (command == 'd' || command == 'D') {
                theBlood.printDay();
            } else if (command == 'w' || command == 'W') {
                theBlood.printWeek();
            } else if (command == 'h' || command == 'H') {
                theBlood.showCommands();
            } else if (command == 'e' || command == 'E') {
                theBlood.endProgram();
            } else {
                cin.clear();
                cin.ignore();
            }
        }
    }

    cout << endl << "Finished entering data. Last week's results:" << endl;
    theBlood.printWeek();

    cout << "See you around!" << endl << endl;
    return 0;
}
