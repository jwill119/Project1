// Jacob Williams
// COSC 2030 project 1
// Created: 10/9/2018
// Modified: 10/9/2018
//
// Function definitions for the BloodSugar class.

#include "bloodSugar.h"

BloodSugar::BloodSugar() {
// Initializes pretty much everything to zero.
    for (int i = 0; i < 14; i++) {
        daySum[i].timesOver = 0;
        daySum[i].remainder = 0;

        dayMin[i] = 0;
        dayMax[i] = 0;
        dayCount[i] = 0;
    }

    for (int i = 0; i < 2; i++) {
        weekSum[i].timesOver = 0;
        weekSum[i].remainder = 0;
        
        weekMin[i] = 0;
        weekMax[i] = 0;
        weekCount[i] = 0;

        biggestDelta[i][0] = 0;
        biggestDelta[i][1] = 0;
    }

    currentDay = 0;
    currentWeek = 0;
}

// Empty destructor unless I realize I need to do something about something
BloodSugar::~BloodSugar() {
}

// Get the current day
int BloodSugar::getCurrentDay(void) {
    return currentDay;
}

// Add value to the daily information
void BloodSugar::addToDay(double val) {
    if (val <= 0) return;
    
    // Change the count
    dayCount[currentDay]++;

    // Change the min and max
    if (val < dayMin[currentDay]) {
        dayMin[currentDay] = val;
    }

    if (val > dayMax[currentDay]) {
        dayMax[currentDay] = val;
    }

    // Change the sum
    if (val + daySum[currentDay].remainder < DBL_MAX) {
        daySum[currentDay].remainder += val;
    } else {
        overflowDay(val);
    }

   // cout << "Exiting function addToDay()." << endl;       // seems happy

}

// Incorporate new value into stored week-data.
void BloodSugar::addToWeek(double val) {
    if (val <= 0) return;
    
    // Change the count
    weekCount[currentWeek]++;

    // Change the min and max
    if (val < weekMin[currentWeek]) {
        dayMin[currentWeek] = val;
    }

    if (val > weekMax[currentWeek]) {
        weekMax[currentWeek] = val;
    }

    // Change the sum
    if (val + daySum[currentWeek].remainder < DBL_MAX) {
        weekSum[currentWeek].remainder += val;
    } else {
        overflowWeek(val);
    }

    //cout << "Exiting function addToWeek()." << endl;      // seems happy
}

// Deal with overflows when adding to day.
void BloodSugar::overflowDay(double val) {
    double therem = abs(daySum[currentDay].remainder - val);
    daySum[currentDay].remainder = therem;
    daySum[currentDay].timesOver++;
}

// Deal with overflows when adding to week.
void BloodSugar::overflowWeek(double val) {
    double therem = abs(weekSum[currentWeek].remainder - val);
    weekSum[currentWeek].remainder = therem;
    weekSum[currentWeek].timesOver++;
}

void BloodSugar::printDay(void) {
    cout << endl << "The current day is day #" << currentDay + 1 << " (of week #" << currentWeek + 1 << ")." << endl;
    cout << "You read your blood sugar " << dayCount[currentDay] << " times today." << endl;
    cout << "Your minimum blood sugar reading today: " << dayMin[currentDay] << "." << endl;
    cout << "Your maximum blood sugar reading today: " << dayMax[currentDay] << "." << endl;
    cout << "Your sum of blood sugar: " << daySum[currentDay].timesOver << "*" << DBL_MAX << " + " << daySum[currentDay].remainder << "." << endl;
    cout << "Keep on keeping on!" << endl << endl;
}

void BloodSugar::printWeek(void) {
    cout << endl << "The current week: week #" << currentWeek + 1 << "." << endl;
    cout << "You have read your blood sugar " << weekCount[currentWeek] << " times so far this week." << endl;
    cout << "Your weekly minimum blood sugar reading: " << weekMin[currentDay] << "." << endl;
    cout << "Your weekly maximum blood sugar reading today: " << weekMax[currentDay] << "." << endl;
    cout << "Your weekly sum of blood sugars: " << weekSum[currentWeek].timesOver << "*" << DBL_MAX << " + " << weekSum[currentWeek].remainder << "." << endl;
    cout << "You're doing great!" << endl << endl;
}

void BloodSugar::nextDay(void) {
    currentDay++;
}

void BloodSugar::nextWeek(void) {
    currentWeek++;
}

/*
void showCommands(void) {
    cout << endl;
    cout << "Enter a positive number (decimals are fine) to have it added to your blood sugar data." << endl;
    cout << "Type 'n' or 'next' to begin entering readings for the next day." << endl;
    cout << "Type 'd' or 'day' to see a current daily summary." << endl;
    cout << "Similarly, type 'w' or 'week' to see a weekly summary." << endl;
    cout << "Type 'h' or 'help' to see these commands again." << endl;
    cout << "Finally, type 'e' or 'exit' to exit the program." << endl;

}
*/

/*
void endProgram(void) {
    cout << endl << "Are you sure you want to exit?" << endl;
    cout << "Type 'y', 'Y', or 'yes' if so; anything else otherwise." << endl;
    string input;
    cin >> input;
    if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "YES") {
        cout << "Program exits. Goodbye!" << endl;
        exit(0);
    } else {
        return;
    }
}
*/
