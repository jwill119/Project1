// Jacob Williams
// COSC 2030 project 1 (adjacent)
// Oct 9 2018
//
// Some numeric limits printed out.

#include <iostream>
#include <climits>
#include <cfloat>

using std::cout;
using std::endl;

int main() {
    cout << "Max float:  " << FLT_MAX << endl;
    cout << "Max double:  " << DBL_MAX << endl;
    cout << "Max long double:  " << LDBL_MAX << endl << endl;
    

    cout << "Testing float overflow." << endl;
    float bigFirst = 0.5*FLT_MAX;
    float bigSecond = 0.75*FLT_MAX;

    // Allowing us to get the remainder, yo
    float firstLeftover = 0;
    float secondLeftover = 0;
    float remainder = 0;

    cout << "first one: " << bigFirst << endl;
    cout << "second one: " << bigSecond << endl;
    cout << "Should overflow: " << bigFirst+bigSecond << endl;

    // How can we return the remainder of bigFirst + bigSecond?
    // bigFirst + bigSecond = FLT_MAX + remainder
    // (FLT_MAX - firstLeftover) + (FLT_MAX - secondLeftover) = FLT_MAX + remainder
    // FLT_MAX - firstLeftover - secondLeftover = remainder
    //
    // BETTER: Whenever bigSecond > FLT_MAX - bigFirst, we have
    // bigFirst + bigSecond = bigSecond + (FLT_MAX - bigFirst) = FLT_MAX + remainder
    // so, FLT_MAX - bigSecond - (FLT_MAX - bigFirst) = remainder = bigFirst - bigSecond (provided bigFirst > bigSecond)
    // in particular remainder = abs(bigFirst - bigSecond)
 
    unsigned long int howManyOverflows = 0;
    if (bigFirst + bigSecond >= FLT_MAX) {
        cout << "overflowed" << endl;
        firstLeftover = FLT_MAX - bigFirst;
        secondLeftover = FLT_MAX - bigSecond;
        remainder = FLT_MAX - firstLeftover - secondLeftover;
        howManyOverflows++;
    }

    cout << bigFirst << " + " << bigSecond << " = " << howManyOverflows << "* " << FLT_MAX << " + " << remainder << endl << endl;

    // We should be able to extend this to work on overflows.
    // In particular, if we store howManyOverflows as (say) unsigned long int,
    // we should be pretty confident (I hope, anyway O_o) that it won't overflow
    return 0;
}
