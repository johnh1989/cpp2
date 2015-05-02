#include <iostream>
#include <string>
#include <iomanip>
#include "Payroll.h"
#include "PayrollOrderedList.h"

using namespace std;

void enterInformation(PayrollOrderedList<Payroll>&);
int removeInformation(PayrollOrderedList<Payroll>&);
int searchForEmployee(PayrollOrderedList<Payroll>&);
int updateInformation(PayrollOrderedList<Payroll>&);
void RunPayroll(PayrollOrderedList<Payroll>&);
void PrintByDepartment(PayrollOrderedList<Payroll>&);

int main()
{
    PayrollOrderedList<Payroll> L;
    int choice  = 1;

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

            case 3: searchForEmployee(L);
                    break;

            case 4: if (L.isEmptyList()){
                        cout << "\nThere is no payroll data\n";
                    }else{
                        updateInformation(L);
                    }
                    break;

            case 5: RunPayroll(L);
                    break;

            case 6: if (L.isEmptyList()){
                        cout << "\nThere is no payroll data\n";
                    }else{
                        L.print();
                    }
                    break;

            case 7: if (L.isEmptyList()){
                        cout << "\nThere is no payroll data\n";
                    }else{
                        PrintByDepartment(L);
                    }
                    break;

            case 0: break;

        }
    }
    cout << "\nGoodbye!";
    cin.get();cin.get();
    return 0;
}

void enterInformation(PayrollOrderedList<Payroll>& L){

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

    L.print();

}

int removeInformation(PayrollOrderedList<Payroll>& L){

    int employeeNumber;

    L.print();

    if ( L.isEmptyList()){
        cout << "\nThere is no payroll data to delete\n";
        return 1;
    }

    cout << "\nenter the employee number to be deleted: ";
    cin >> employeeNumber;

    Payroll p;
    p.SetEmployeeNumber(employeeNumber);
    L.deleteNode(p);

    return 0;
}

int searchForEmployee(PayrollOrderedList<Payroll>& L){

    Payroll payroll;
    int EmployeeNumber = NULL;
    bool found = false;

    if (L.isEmptyList()){
        return 1;
    }

    cout << "\nenter the employee number to search: ";
    cin >> EmployeeNumber;

    payroll.SetEmployeeNumber(EmployeeNumber);
    found = L.searchEmployee(payroll);

    if (found){
        cout << "FOUND" << endl;
        cout << payroll << endl;
    }else{
        cout << "NOT FOUND" << endl;
    }

    return 0;
}


int updateInformation(PayrollOrderedList<Payroll>& L){

    Payroll payroll;
    int EmployeeNumber = NULL;
    bool found = false;
    char choice;
    double payrate;
    double hoursworked;

    cout << "Enter the employee number you wish to update information for: ";
    cin >> EmployeeNumber;

    payroll.SetEmployeeNumber(EmployeeNumber);
    found = L.searchEmployee(payroll);

    if (found){
        cout << "FOUND" << endl;
        cout << payroll << endl;
        cout << "Do you want to update this information y/n: ";
        cin >> choice;

        choice = toupper(choice);
        if (choice == 'Y'){
            L.deleteNode(payroll);
            cout << "\nEnter new pay rate: ";
            cin >> payrate;
            payroll.SetPayRate(payrate);

            cout << "\nEnter hours worked: ";
            cin >> hoursworked;
            payroll.SetHoursWorked(hoursworked);

            L.insert(payroll);
        }
    }else{
        cout << "NOT FOUND" << endl;
    }

    return 0;
}

void RunPayroll(PayrollOrderedList<Payroll>& L){

    int department;

    char run;

    cout << "\nDo you want to run payroll for a department y/n: ";
    cin >> run;
    run = toupper(run);

    if (run == 'Y'){

        cout << "\nenter the department you would like to run payroll for: ";
        cin >> department;
        L.RunPayroll(department);
    }

}

void PrintByDepartment(PayrollOrderedList<Payroll>& L){

    int department;

    cout << "\nenter department number to print payroll for: ";
    cin >> department;

    L.PrintByDept(department);

}
