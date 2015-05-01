#include <iostream>
#include <string>
#include "Payroll.h"
#include "orderedLinkedList.h"

using namespace std;

void enterInformation(orderedLinkedList<Payroll>&);
int removeInformation(orderedLinkedList<Payroll>&);

int main()
{
    orderedLinkedList<Payroll> L;
    int choice;

    while (choice != 0){
        cout << "\nPlease choose from the following..." << endl;
        cout << "1. Enter employee information" << endl;
        cout << "2. Remove employee from the payroll" << endl;
        cout << "3. Search for an employee" << endl;
        cout << "4. Update employee information" << endl;
        cout << "5. Run payroll for department" << endl;
        cout << "6. Run entire payroll" << endl;
        cout << "7. Print department payroll information" << endl;
        cout << "0. EXIT" << endl;
        cin >> choice;

        switch (choice){
            case 1: enterInformation(L);
                    break;
            case 2: removeInformation(L);
                    break;

        }
    }


    return 0;
}

void enterInformation(orderedLinkedList<Payroll>& L){

    Payroll payroll;
    int employeeNumber;
    string lastName;
    string firstName;
    int deptNumber;
    double payRate;
    double hoursWorked;

    cout << "\nenter employee number: ";
    cin >> employeeNumber;
    payroll.SetEmployeeNumber(employeeNumber);
    cout << "emp num is " << payroll.GetEmployeeNumber() << endl;
    cin.ignore().clear();

    cout << "\nenter last name: ";
    getline(cin, lastName);
    payroll.SetLastName(lastName);

    cout << "\nenter first name: ";
    getline(cin, firstName);
    payroll.SetFirstName(firstName);

    cout << "\nenter department number: ";
    cin >> deptNumber;
    payroll.SetDeptNumber(deptNumber);

    cout << "\nenter pay rate: ";
    cin >> payRate;
    payroll.SetPayRate(payRate);

    cout << "\nenter the hours worked: ";
    cin >> hoursWorked;
    payroll.SetHoursWorked(hoursWorked);

    L.insert(payroll);

    payroll.PrintPayroll();

}

int removeInformation(orderedLinkedList<Payroll>& L){

    int employeeNumber;

    L.print();

    if ( L.isEmptyList()){
        cout << "\nThere is no payroll data to delete" << endl;
        return 1;
    }

    cout << "enter the employee number to be deleted: ";
    cin >> employeeNumber;

    Payroll p;
    p.SetEmployeeNumber(employeeNumber);
    cout << p.GetEmployeeNumber() << endl;
    L.deleteNode(p);

    return 0;
}
