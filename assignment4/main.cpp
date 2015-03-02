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

int main()
{
	orderedLinkedList<int> list1, list2;
	nodeType<int> temp;
	int num;
	list1.insert(5);
	list1.insert(6);
	list1.insert(7);
    list1.insert(8);

    list1.print();
    cout << endl;


    num = list1.GetNth(2);
    cout << num << endl;

    list1.DeleteNth(20);
    list1.DeleteNth(0);

    list1.print();
    list1.insert(7);

    cout << endl;
    list1.print();

	bool x = list1.isEmptyList();
	if (x == true){
        cout <<"x is true";
	}



	cin.get();
	return 0;
}
