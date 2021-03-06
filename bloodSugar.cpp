// Jacob Williams
// COSC 2030 project 1
// Created: 10/9/2018
// Modified: 10/9/2018
//
// Function definitions for the BloodSugar class.

#include "bloodSugar.h"

BloodSugar::BloodSugar() {
// Initializes pretty much everything to zero, except the mins
    for (int i = 0; i < 14; i++) {
        daySum[i].timesOver = 0;
        daySum[i].remainder = 0;

        dayMin[i] = DBL_MAX;
        dayMax[i] = 0;
        dayCount[i] = 0;
    }

    for (int i = 0; i < 2; i++) {
        weekSum[i].timesOver = 0;
        weekSum[i].remainder = 0;
        
        weekMin[i] = DBL_MAX;
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

// Get the current day and week
int BloodSugar::getCurrentDay(void) {
    return currentDay;
}

int BloodSugar::getCurrentWeek(void) {
    return currentWeek;
}

// Add value to the daily information
void BloodSugar::addToDay(double val) {
    // Ignore nonpositive values
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
}

// Incorporate new value into stored week-data.
void BloodSugar::addToWeek(double val) {
    // Ignore nonpositive values
    if (val <= 0) return;
    
    // Change the count
    weekCount[currentWeek]++;

    // Change the min and max
    if (val < weekMin[currentWeek]) {
        weekMin[currentWeek] = val;
    }

    if (val > weekMax[currentWeek]) {
        weekMax[currentWeek] = val;
    }

    // Change the sum
    if (val + weekSum[currentWeek].remainder < DBL_MAX) {
        weekSum[currentWeek].remainder += val;
    } else {
        overflowWeek(val);
    }

}

// Deal with overflows when adding to day. We know sum + val > DBL_MAX; in particular,
// sum + val = DBL_MAX + remainder. So we may define
// val = DBL_MAX - leftRem; sum = DBL_MAX - rightRem, which gives
// (DBL_MAX - leftRem) + (DBL_MAX - rightRem) = DBL_MAX + rem =>
// 2 DBL_MAX - leftRem - rightRem = DBL_MAX + rem =>
// rem = abs(DBL_MAX - leftRem - rightRem) (to ensure positivity is retained)
void BloodSugar::overflowDay(double val) {
    double leftRem = DBL_MAX - daySum[currentDay].remainder;
    double rightRem = DBL_MAX - val;
    double therem = abs(DBL_MAX - leftRem - rightRem);
    daySum[currentDay].remainder = therem;
    daySum[currentDay].timesOver++;
}

// Deal with overflows when adding to week.
void BloodSugar::overflowWeek(double val) {
    double leftRem = DBL_MAX - weekSum[currentWeek].remainder;
    double rightRem = DBL_MAX - val;
    double therem = abs(DBL_MAX - leftRem - rightRem);
    weekSum[currentWeek].remainder = therem;
    weekSum[currentWeek].timesOver++;
}

// Print daily summary all nicely-like
void BloodSugar::printDay(void) {
    cout << endl << "The current day is day #" << currentDay + 1 << " (day # " << (currentDay % 7) + 1 << " of week #" << currentWeek + 1 << ")." << endl;
    cout << "You read your blood sugar " << dayCount[currentDay] << " times today." << endl;
    cout << "Your minimum blood sugar reading today: " << dayMin[currentDay] << "." << endl;
    cout << "Your maximum blood sugar reading today: " << dayMax[currentDay] << "." << endl;
    cout << "Your sum of blood sugar: " << daySum[currentDay].timesOver << "*" << DBL_MAX << " + " << daySum[currentDay].remainder << "." << endl;
    cout << "Keep on keeping on!" << endl << endl;
}

// Print weekly summary all nice, also update the weekly biggestDelta
void BloodSugar::printWeek(void) {

    cout << endl << "The current week: week #" << currentWeek + 1 << "." << endl;
    cout << "You have read your blood sugar " << weekCount[currentWeek] << " times so far this week." << endl;
    cout << "Your weekly minimum blood sugar reading: " << weekMin[currentWeek] << "." << endl;
    cout << "Your weekly maximum blood sugar reading: " << weekMax[currentWeek] << "." << endl;
    cout << "Your weekly sum of blood sugars: " << weekSum[currentWeek].timesOver << "*" << DBL_MAX << " + " << weekSum[currentWeek].remainder << "." << endl;
    cout << "Your biggest change in number of readings this week was " << biggestDelta[currentWeek][1] << 
        " , leading up to day " << biggestDelta[currentWeek][0] << "." << endl;
    cout << "You're doing great!" << endl << endl;
}

// Increment day (and week, if called for)
// Also ends the program once 14th day is finished!
void BloodSugar::nextDay(void) {
    // Increment the day, checking first the delta
    if (currentDay < 13) {
        // Increment the delta
        if (currentDay > 0) {
            double theDelta = (dayCount[currentDay] >= dayCount[currentDay - 1]) ?
                dayCount[currentDay] - dayCount[currentDay - 1] : dayCount[currentDay - 1] - dayCount[currentDay];
            if (theDelta > biggestDelta[currentWeek][1]) {
                biggestDelta[currentWeek][1] = theDelta;
                biggestDelta[currentWeek][0] = (currentDay % 7) + 1;
            }
        }

        currentDay++;
        if (currentDay > 6 && currentWeek == 0) { currentWeek++; }

    } else {
        cout << endl << "Finished entering data. Last week's results:" << endl;
        printWeek();
        cout << "See you around!" << endl << endl;
        currentDay++;
        exit(0);
    }
}

// Help function
void BloodSugar::showCommands(void) {
    cout << endl;
    cout << "Enter a positive number (decimals are fine) to have it added to your blood sugar data." << endl;
    cout << "Type 'n' or 'N' to begin entering readings for the next day." << endl;
    cout << "Type 'd' or 'D' to see a current daily summary." << endl;
    cout << "Similarly, type 'w' or 'W' to see a weekly summary." << endl;
    cout << "Type 'h' or 'H' to see these commands again." << endl;
    cout << "Finally, type 'e' or 'E' to exit the program." << endl;

}

// Quit early
void BloodSugar::endProgram(void) {
    cout << endl << "Would you like to see final summaries?" << endl;
    cout << "Type 'y' or 'Y' if so; anything else otherwise." << endl;
    cout << "Or type 'r' or 'R' if you wish to return to the main program." << endl << endl;
    char input;
    cin >> input;
    if (input == 'y' || input == 'Y') {
        printDay();
        printWeek();
        exit(0);
    } else if (input == 'r' || input == 'R') {
        return;
    } else {
        exit(0);
    }
}
