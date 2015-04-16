#include "Payroll.h"

Payroll::Payroll()
{
    //ctor
}

Payroll::~Payroll()
{
    //dtor
}

Payroll::Payroll(const Payroll& other)
{
    //copy ctor
}

Payroll& Payroll::operator=(const Payroll& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

bool Payroll::operator>=(const Payroll &other){
    return EmployeeNumber >= other.EmployeeNumber;
}

bool Payroll::operator==(const Payroll &other){
    return EmployeeNumber == other.EmployeeNumber;
}
