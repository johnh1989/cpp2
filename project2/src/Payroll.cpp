#include <iostream>
#include <iomanip>
#include "Payroll.h"

using namespace std;

Payroll::Payroll()
{
    EmployeeNumber = 0;
    LastName = "";
    FirstName = "";
    DeptNumber = 0;
    PayRate = 0.00;
    HoursWorked = 0.00;
    PayAmount = 0.00;
}

Payroll::Payroll(int en, string ln, string fn, int dn, double pr, double hw)
{
    EmployeeNumber = en;
    LastName = ln;
    FirstName = fn;
    DeptNumber = dn;
    PayRate = pr;
    HoursWorked = hw;
    PayAmount = 0.00;
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

    EmployeeNumber = rhs.EmployeeNumber;
    LastName = rhs.LastName;
    FirstName = rhs.FirstName;
    DeptNumber = rhs.DeptNumber;
    PayRate = rhs.PayRate;
    HoursWorked = rhs.HoursWorked;
}


bool Payroll::operator>=(const Payroll &other){
    return EmployeeNumber >= other.EmployeeNumber;
}

bool Payroll::operator==(const Payroll &other){
    return EmployeeNumber == other.EmployeeNumber;
}

void Payroll::PrintPayroll() {
    cout << endl;
    cout << "*****************" << endl;
    cout << "Employee #: " << EmployeeNumber
         << "\nFirst Name: " << FirstName
         << "\nLast Name : " << LastName
         << "\nDept #    : " << DeptNumber
         << setprecision(2) << fixed
         << "\nRate      : $" << PayRate
         << "\nHours     : " << HoursWorked
         << "\nAmount    : $" << CalculatePayAmount() << endl;
    cout << "*****************" << endl;
}

double Payroll::CalculatePayAmount(){
    PayAmount = HoursWorked * PayRate;
    return PayAmount;
}

ostream& operator<<(ostream &stream, Payroll& ob){
            ob.PrintPayroll();
            return stream;
}
