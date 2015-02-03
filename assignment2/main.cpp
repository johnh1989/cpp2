#include <iostream>
#include "clockType.h"
#include "extClockType.h"

// Exercise 1. on page 806
/*

    Create 2 objects of type extClockType
    Set the time of the first object and print the time
    Set the time of the second object and print the time
    Increment the time of the first object (hours, minutes and seconds and time zone) and print the time
    Increment the time of the second object (hours, minutes and seconds and time zone) and print the time
    Compare the time of the 2 objects to determine if they are equal and print an appropriate message

*/
using namespace std;

void areEqual(const extClockType&, const extClockType&);

int main()
{

    extClockType clock1(22,59,49, " Eastern");
    extClockType clock2;

    clock2.setTime(22,59,49, " Eastern");

    cout << "Clock1 ";
    clock1.printTime();
    cout << endl;

    cout << "Clock2 ";
    clock2.printTime();
    cout << endl;

    areEqual(clock1, clock2);

    cout << "\nincrementing time on clock1" << endl;
    clock1.incrementHours();
    clock1.incrementMinutes();
    clock1.incrementSeconds();

    cout << "Clock 1 " << endl;;
    clock1.printTime();
    cout << "Clock 2 " << endl;;
    clock2.printTime();

    areEqual(clock1, clock2);

    cout << "\nincrementing time on clock2" << endl;
    clock2.incrementHours();
    clock2.incrementMinutes();
    clock2.incrementSeconds();

    cout << "Clock 1 " << endl;;
    clock1.printTime();
    cout << "Clock 2 " << endl;;
    clock2.printTime();

    areEqual(clock1, clock2);
    cin.get();
    return 0;
}

void areEqual(const extClockType& clock1, const extClockType& clock2){
    bool equals;

    equals = clock1.equalTime(clock2);
    if (equals == true && (clock1.getTZ() == clock2.getTZ()) ){
        cout << "clock1 and clock2" << " are both set to "; clock1.printTime();
    }
    else{
        cout << "Clocks are not equal" << endl;
    }
}
