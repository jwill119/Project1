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
    cout << "first one: " << bigFirst << endl;
    cout << "second one: " << bigSecond << endl;
    cout << "Should overflow: " << bigFirst+bigSecond << endl;
    return 0;
}
