#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;
class Employee
{
    public:
        Employee();
        Employee(int, string, string, int, char);
        virtual ~Employee();
        int GetemployeeNumber();
        void SetemployeeNumber(int);
        string GetlastName();
        void SetlastName(string);
        string GetfirstName();
        void SetfirstName(string);
        int Getage();
        void Setage(int);
        char Getgender();
        void Setgender(char);
        bool operator==(const Employee&) const;
    protected:
    private:
        int employeeNumber;
        string lastName;
        string firstName;
        int age;
        char gender;
};

#endif // EMPLOYEE_H

