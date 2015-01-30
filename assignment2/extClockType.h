#ifndef EXTCLOCKTYPE_H_INCLUDED
#define EXTCLOCKTYPE_H_INCLUDED
#include <iostream>
#include <clockType.h>
#include <string>

using namespace std;

class extClockType : public clockType{
public:
    extClockType();
        //Default constructor
    extClockType(int hours, int minutes, int seconds, string tz);
        //constructor, arguments to set time and timezone
    void printTime() const;
        /*
        This function will print the hr min sec and timezone
        */
    void setTime(int hours, int minutes, int seconds, string tz);
        /*Set hr min sec and timezone*/
    string getTZ() const;
        /*return timezone*/
private:
    string tz;

};


#endif // EXTCLOCKTYPE_H_INCLUDED
