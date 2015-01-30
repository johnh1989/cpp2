#include <iostream>
#include "clockType.h"
#include "extClockType.h"

using namespace std;

int main()
{
    extClockType clock(12,12,15, " Eastern");
    clock.incrementHours();
    clock.printTime();
    return 0;
}
