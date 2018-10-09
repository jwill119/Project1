// Jacob Williams
// COSC 2030 project 1
// Created: 10/9/2018
// Modified: 10/9/2018
//
// Class declaration for the blood sugar storage module.

// Inclusion headers
#include <iostream>
#include <cfloat>       // for overflow purposes
using std::cin;
using std::cout;
using std::endl;


// Values with possible overflow
struct numHolder {
    unsigned long int timesOver;
    double remainder;
};


class BloodSugar {
    public:
        BloodSugar();
        ~BloodSugar();

        void addToDay(double val);
        void printDay(void);
        void printWeek(void);
        void nextDay(void);


    private:
        numHolder daySum[14];
        numHolder dayMin[14];
        numHolder dayMax[14];
        unsigned long int dayCount[14];

        numHolder weekNum[2];
        numHolder weekMin[2];
        numHolder weekMax[2];
        unsigned long int weekCount[2];
        unsigned long int biggestDelta[2][2];

        int currentDay;
        int currentWeek;
};
