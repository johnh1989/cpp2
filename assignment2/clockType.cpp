//Implementation File for the class clockType

#include <iostream>
#include "clockType.h"

using namespace std;

clockType::clockType()  //default constructor
{
    hr = 0;
    minutes = 0;
    sec = 0;
}

clockType::clockType(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;

    if (0 <= minutes && minutes < 60)
        this->minutes = minutes;
    else
        this->minutes = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}

void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
	    hr = hours;
	else
	    hr = 0;

	if (0 <= minutes && minutes < 60)
	    this->minutes = minutes;
	else
	    this->minutes = 0;

	if (0 <= seconds && seconds < 60)
	    sec = seconds;
	else
	    sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = this->minutes;
	seconds = sec;
}

void clockType::printTime() const
{
	if (hr < 10)
	    cout << "0";
	cout << hr << ":";

	if (minutes < 10)
	    cout << "0";
	cout << minutes << ":";

	if (sec < 10)
	   cout << "0";
	cout << sec;
}

void clockType::incrementHours()
{
	hr++;
	if(hr > 23)
 	   hr = 0;
}

void clockType::incrementMinutes()
{
	minutes++;
	if (minutes > 59)
	{
	    minutes = 0;
	    incrementHours();
	}
}

void clockType::incrementSeconds()
{
	sec++;

	if (sec > 59)
	{
	    sec = 0;
	    incrementMinutes();
	}
}


bool clockType::equalTime(const clockType& otherClock) const
{
	return (hr == otherClock.hr
		    && minutes == otherClock.minutes
		    && sec == otherClock.sec);
}
