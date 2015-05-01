#include <iostream>
#include "Payroll.h"

using namespace std;

Payroll::Payroll()
{

}

Payroll::Payroll(int en, string ln, string fn, int dn, double pr, double hw)
{
    EmployeeNumber = en;
    LastName = ln;
    FirstName = fn;
    DeptNumber = dn;
    PayRate = pr;
    HoursWorked = hw;
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

void Payroll::PrintPayroll() const{
    cout << "Employee #: " << EmployeeNumber
         << "First Name: " << FirstName
         << "Last Name: " << LastName
         << "Dept #: " << DeptNumber
         << "Rate: " << PayRate
         << "Hours: " << HoursWorked
         << "Amount: " << PayAmount << endl;
}

double Payroll::CalculatePayAmount(){
    return (HoursWorked * PayRate);
}

ostream& operator<<(ostream &stream, const Payroll& ob){
            ob.PrintPayroll();
            return stream;
}
