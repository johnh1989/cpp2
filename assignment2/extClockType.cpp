#include "clockType.h"
#include "extClockType.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor
extClockType::extClockType(){
    clockType::setTime(0,0,0);
    tz = "";
}

//constructor sets time and timezone
extClockType::extClockType(int hours, int minutes, int seconds, string tz)
    :clockType(hours, minutes, seconds)
{
    this->tz = tz;
}

//function allows  time and timezone to be set
void extClockType::setTime(int hours, int minutes, int seconds, string tz){
    clockType::setTime(hours, minutes, seconds);
    this->tz = tz;
}

//returns time and timezone
void extClockType::getTime(int& hours, int& minutes, int& seconds, string tz) const{
    clockType::getTime(hours, minutes, seconds);
    tz = this->tz;
 }

/*This function prints time and timezone*/
void extClockType::printTime() const{
    int hr, minutes, sec;
    clockType::getTime(hr, minutes, sec);
	if (hr < 10)
	    cout << "0";
	cout << hr << ":";

	if (minutes < 10)
	    cout << "0";
	cout << minutes << ":";

	if (sec < 10)
	   cout << "0";
	cout << sec;

	cout << extClockType::getTZ() << endl;
}

//returns timezone
string extClockType::getTZ() const{
    return tz;
}


