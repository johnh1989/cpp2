#include <iostream>
#include <limits> // provides very limited data validation
#include "aseqlist.h"
#include "employee.h"
using namespace std;

void collectData(SeqList&);
void deleteEmp(SeqList&);
void PrintByGender (const SeqList&, char, Employee&);
int InList (const SeqList&, string, Employee&);
void printAll(const SeqList&);
int main()
{
    int numItemsInList = 0; // so user can't add more then 6 items
    int choice = 1;
    int foundInlist; //holds return value for int InList()
    Employee Emp_search;//Used as reference parameter InList function
    string lname;
    char gen;
    SeqList ListOfEmployees;
    //SeqList* loe = &ListOfEmployees;

    while(choice != 0){
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Enter employee information" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Print by Gender" << endl;
        cout << "4. Search for employee" << endl;
        cout << "5. Print all employee data" << endl;
        cout << "or press 0 to exit" << endl;
        cin >> choice;

        switch(choice)
        {
            case 0: cout << "Goodbye";
                    cin.ignore().get();
                    exit(1);
                    break;

            case 1: if (numItemsInList == 6){
                        cout << "\n You Must delete items first\n";
                        break;
                    }
                    collectData(ListOfEmployees);
                    numItemsInList++;
                    break;

            case 2: deleteEmp(ListOfEmployees);
                    numItemsInList--;
                    break;

            case 3: cout << "Which gender : m/f";
                    cin >> gen;
                    PrintByGender(ListOfEmployees, gen, Emp_search);
                    break;

            case 4: cout << "Please Enter a last name to search for: ";
                    cin.ignore();
                    getline(cin, lname);
                    cout << lname << endl;
                    foundInlist = InList(ListOfEmployees,lname,Emp_search);
                    if(foundInlist == 0){
                        cout << endl << lname << " not found in list" << endl;
                    }
                    break;

            case 5: printAll(ListOfEmployees);
                    break;
        }
    }
    cin.ignore().clear();
    cin.get();
    return 0;
}

void collectData(SeqList& L)
{
    int empid, age;
    string fname, lname;
    char gender;

    cout << "\nEnter Employee Number: ";
    while(!(cin >> empid)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Must be a number: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\nEnter First Name: ";
    getline(cin, fname);

    cout << "\nEnter Last Name: ";
    getline(cin, lname);

    cout << "\nEnter age: ";
    cin >> age;

    cout << "\nEnter gender: m/f: ";
    cin >> gender;

    /*Create temporary employee object
     and insert into our list
    */
    Employee temp(empid, lname, fname, age, gender);
    L.Insert(temp);

}


void deleteEmp(SeqList& L)
{
    string lname;
    const int INDEX = L.ListSize();
    Employee empArray[INDEX];

    Employee e;
    for (int i = 0; i < L.ListSize(); i++)
    {
        /*Get data from list
          Store result in Employee e variable
          copy into empArray
        */
        e = L.GetData(i);
        empArray[i] = e;

        /*Print all last names for user to see*/
        cout << empArray[i].GetlastName() << endl;
    }
    cout << "Which employee do you want to delete?" << endl;
    cin.ignore();
    getline(cin, lname);

    for (int i = 0; i < INDEX; i++)
    {
        if(lname == empArray[i].GetlastName())
        {
            /*Delete object from seq list */
            L.Delete(empArray[i]);
            cout << "\nEmployee deleted successfully" << endl;
            break;
        }
        else
        {
            cout << "could not find a match" << endl;
        }
    }
}


void PrintByGender (const SeqList& L, char gender, Employee& Emp)
{
    int x = 0;

    const int INDEX = L.ListSize();
    Employee empArray[INDEX];

    for (int i = 0; i < L.ListSize(); i++)
    {
        /*Get data from list
          Store result in Employee e variable
          copy into empArray
        */
        Emp = L.GetData(i);
        empArray[i] = Emp;
    }
    for (int i = 0; i < L.ListSize(); i++)
    {
       if (gender == empArray[i].Getgender())
       {
           empArray[i].PrintEmployee();
       }
    }
}


int InList(const SeqList& L, string lname, Employee& Emp)
{
    int x = 0;
    Employee emp_to_search;

    const int INDEX = L.ListSize();
    Employee empArray[INDEX];
    for (int i = 0; i < L.ListSize(); i++)
    {
        /*Get data from list
          Store result in Employee e variable
          copy into empArray
        */
        Emp = L.GetData(i);
        empArray[i] = Emp;
    }
    for (int i = 0; i< L.ListSize(); i++)
    {
        if(lname == empArray[i].GetlastName()){
            /*If last names match,
                copy object in empArray
                into Employee object emp_to_search
            */
            emp_to_search = empArray[i];

            /* Check for match,
               returns 1 for true, 0 for false
            */
            x = L.Find(emp_to_search);
        }

        if(x == 1){
            /*If match was found print out
                Employee number and Last Name
            */
            cout << "__FOUND__" << endl;
            cout << empArray[i].GetemployeeNumber() << ": "
                << empArray[i].GetlastName() << endl;
            return x;
        }
    }
    return x;
}

void printAll(const SeqList& L)
{
    Employee Emp;

    const int INDEX = L.ListSize();
    Employee empArray[INDEX];
    for (int i = 0; i < L.ListSize(); i++)
    {
        Emp = L.GetData(i);
        empArray[i] = Emp;
    }
    for (int i = 0; i< L.ListSize(); i++)
    {
        empArray[i].PrintEmployee();
    }
}

