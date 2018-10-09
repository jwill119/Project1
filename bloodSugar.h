// Jacob Williams
// COSC 2030 project 1
// Created: 10/9/2018
// Modified: 10/9/2018
//
// Class declaration for the blood sugar storage module.

// Inclusion headers
#include <iostream>
#include <cfloat>       // for overflow purposes
#include <cmath>        // for absolute value
#include <string>       // for user input
#include <stdlib.h>     // for exit()
using std::cin;
using std::cout;
using std::endl;
using std::abs;
using std::string;


// Values with possible overflow
struct numHolder {
    unsigned long int timesOver;
    double remainder;
};


class BloodSugar {
    public:
        BloodSugar();
        ~BloodSugar();

        int getCurrentDay(void);

        void addToDay(double val);
        void addToWeek(double val);
        void overflowDay(double val);
        void overflowWeek(double val);
        void printDay(void);
        void printWeek(void);
        void nextDay(void);
        void nextWeek(void);

        /*
        void showCommands(void);
        */
        /*
        void endProgram(void);
        */


    private:
        numHolder daySum[14];
        double dayMin[14];
        double dayMax[14];
        unsigned long int dayCount[14];

        numHolder weekSum[2];
        double weekMin[2];
        double weekMax[2];
        unsigned long int weekCount[2];
        unsigned long int biggestDelta[2][2]; // first index: day, second index: delta

        int currentDay;
        int currentWeek;
};
