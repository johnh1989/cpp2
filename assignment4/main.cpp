/*

Per Programming Exercise 3 in the text
    Write a function that returns the info
     of the kth element of the linked list

    Write a function that deletes the kth element
     of the linked list

Write a program to test the Linked List
    Process integers in an Ordered Linked List object
    Provide the ability to add elements to the list
    Provide the ability to print the list
    Provide the ability to find the kth element of the list
    Provide the ability to delete the kth element of the list

*/

#include <iostream>
#include <string>
#include "orderedLinkedList.h"
using namespace std;

void addelements(orderedLinkedList<int>&);
void printElements(orderedLinkedList<int>&);
void findElement(orderedLinkedList<int>&);
void deleteElement(orderedLinkedList<int>&);

int main()
{
	orderedLinkedList<int> list1;
	int num, choice;;

    while (choice != 0){
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Add elements to list" << endl;
        cout << "2. Print elements in the list" << endl;
        cout << "3. Find element in list" << endl;
        cout << "4. Delete element in list" << endl;
        cout << "5. Show Length of list" << endl;
        cout << "0. EXIT" << endl << endl;
        cin >> choice;

        switch (choice){
        case 1: addelements(list1);
                break;

        case 2: printElements(list1);
                break;

        case 3: findElement(list1);
                break;

        case 4: deleteElement(list1);
                break;

        case 5: int length;
                length = list1.length();
                cout << length << " Items in list\n";
                break;
        }
    }

	cin.get();
	return 0;
}

void addelements(orderedLinkedList<int>& list1)
{
    int item;
    char again = 'y';

    while (again == 'y' || again == 'Y'){
        cout << "Enter number you would like to add to the list: ";
        cin >> item;
        list1.insert(item);

        cout << "Add another? y/n: ";
        cin >> again;
    }
}

void printElements(orderedLinkedList<int>& list1)
{
    cout << "\nHeres the items in the list" << endl;
    list1.print();
    cout << endl << endl;
}

void findElement(orderedLinkedList<int>& list1)
{
    int num;
    int ret_value; // use int because thats what we use in our template
    cout << "\nWhich element do you want to search for by index? : ";
    cin >> num;
    ret_value = list1.GetKth(num);
    if (ret_value == NULL){
        cout<< "\n";
    }else{
        cout << "\""  << ret_value << "\"" << " was the data stored at index " << num << endl;
    }
}

void deleteElement(orderedLinkedList<int>& list1)
{
    int num;
    cout << "\nWhich element do you want to delete by index? : ";
    cin >> num;
    list1.DeleteKth(num);
}
