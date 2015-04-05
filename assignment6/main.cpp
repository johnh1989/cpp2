#include <iostream>
#include "binarySearchTree.h"
#include "Employee.h"
#include <Limits>

/*
Programming Assignment 6 is due Wednesday April 8.  Use the BinaryTree and BinarySearchTree class files posted on the Angel site under the Programming Assignment 6 folder under the Programming Assignments folder to write the following program:

    You will process Employee objects in the Binary Search Tree
    Use the Employee class you created with project 1
        You will need to overload the "<" and ">" operators in the Employee class as these operations are used in the Binary Search Tree
            Use the Employee Number data member in defining the "<" and ">" operators
        Update the "==" operator overload in the Employee class to use the Employee Number rather than Last Name

Write the following program:

    Add Employee object elements to the Binary Search Tree
    Delete Employee object elements from the Binary Search Tree
    Return the number of nodes in the Binary Search Tree
    Search and Print an employee in the Binary Search Tree

*/

void addEmployee(bSearchTreeType<Employee>&);
void deleteEmployee(bSearchTreeType<Employee>&);
void searchForEmployee(bSearchTreeType<Employee>&);
using namespace std;

int main(){

	bSearchTreeType<Employee> tree;

	int choice;

	while (choice != 6){
        cout << "\nMain Menu..." << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Delete employee" << endl;
        cout << "3. Get number of nodes in binary tree" << endl;
        cout << "4. Search for employee by id" << endl;
        cout << "5. Show all employees" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;

        switch (choice){
            case 1: addEmployee(tree);
                    break;

            case 2: deleteEmployee(tree);
                    break;

            case 3: cout << "\n" << tree.treeNodeCount() << " nodes in tree" << endl;
                    break;

            case 4: searchForEmployee(tree);
                    break;

            case 5: cout << endl;
                    cout << "\nAll Employees" << endl;
                    cout << " ";
                    tree.inorderTraversal();
                    break;
        }
	}
	cout << "\nGoodBye..";
	cin.ignore().get();
	return 0;
}

void addEmployee(bSearchTreeType<Employee>& tree){
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
    while(!(cin >> age)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Must be a number: ";
    }

    cout << "\nEnter gender: m/f: ";
    cin >> gender;
    while (gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F'){
        cout << "\nPlease enter m or f: ";
        cin >> gender;
    }

    /*Create temporary employee object
     and insert into our tree
    */
    Employee temp(empid, lname, fname, age, gender);
    tree.insert(temp);

}

void deleteEmployee(bSearchTreeType<Employee>& tree){
    Employee temp;
    int employeeNumber;
    bool found = false;
    cout << " \nList of all Employees..." << endl;
    cout << " ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Enter employee number to delete ";
    cin >> employeeNumber;
    temp.SetemployeeNumber(employeeNumber);
    found = tree.search(temp);
    if (found){
        tree.deleteNode(temp);
    }else{
        cout << "\nCould find that employee..." << endl;
    }
}

void searchForEmployee(bSearchTreeType<Employee>& tree){
    int employeeNumber;
    Employee temp;
    cout << "Enter the employee number you would like to search for: ";
    cin >> employeeNumber;
    temp.SetemployeeNumber(employeeNumber);
    tree.printElement(temp);
}

