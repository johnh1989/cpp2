#include <iostream>
#include "employee.h"

using namespace std;

//default constructor
Employee::Employee()
{
    employeeNumber = 0;
    lastName = "";
    firstName = "";
    age = 0;
    gender = 'x';
}

//constructor w/ params
Employee::Employee(int en, string ln, string fn, int a, char g)
{
    employeeNumber = en;
    lastName = ln;
    firstName = fn;
    age = a;
    gender = g;
}

//virtual destructor
Employee::~Employee(){}


int Employee::GetemployeeNumber()
{
    return employeeNumber;
}


void Employee::SetemployeeNumber(int val)
{
    employeeNumber = val;
}


string Employee::GetlastName()
{
    return lastName;
}


void Employee::SetlastName(string val)
{
    lastName = val;
}


string Employee::GetfirstName()
{
    return firstName;
}


void Employee::SetfirstName(string val)
{
    firstName = val;
}


int Employee::Getage()
{
    return age;
}


void Employee::Setage(int val)
{
    age = val;
}


char Employee::Getgender()
{
    return gender;
}


void Employee::Setgender(char val)
{
    gender = val;
}


bool Employee::operator==(const Employee& e) const
{
    return lastName == e.lastName;
}


void Employee::PrintEmployee() const
{
    cout << "ID:" << employeeNumber
         << ", First Name:" << firstName
         << ", Last Name:" << lastName
         << ", Age:" << age
         << ", Gender:" << gender << endl;
}


void Employee::ReadEmployee(int en, string ln, string fn, int a, char g)
{

}
