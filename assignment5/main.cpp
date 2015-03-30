#include <iostream>
#include "linkedQueue.h"

/*
Do Programming Exercise 16 on Page 1264 of the textbook.
Follow the directions in Programming Exercise 16.
Redefine the linkedQueueType class to add a variable
count which will keep track of the number of elements
in the queue.
Modify the addQueue and deleteQueue methods

Write a program to use the Linked Queue.
Create a menu to provide the following options:

    Add elements to the Linked Queue
    Delete items from the Linked Queue
    Return the number of nodes in the Linked Queue
    Print the contents of the Queue

*/

using namespace std;

void add(linkedQueueType<int>&);
void del(linkedQueueType<int>&);
void getCount(linkedQueueType<int>&);
void printContents(linkedQueueType<int>&);

int main()
{
    linkedQueueType<int> q1;
    int choice;
    while (choice != 5){
        cout << "What would you like to do" << endl;
        cout << "1. add element to queue" << endl;
        cout << "2. Delete element from queue" << endl;
        cout << "3. Get count" << endl;
        cout << "4. Print contents of the queue" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch(choice){
            case 1: add(q1);
                    break;

            case 2: del(q1);
                    break;

            case 3: getCount(q1);
                    break;

            case 4: printContents(q1);
                    break;
        }
    }
    cout << "goodbye" << endl;
    cin.get();
    return 0;
}

void add(linkedQueueType<int>& q1){
    int num;
    char again = 'Y';
    while (again != 'N'){
        cout << "\nPlease enter the number ";
        cout << "you'd like to add to the queue: ";
        cin >> num;
        q1.addQueue(num);

        cout << "\nadd another? y/n: ";
        cin >> again;
        again = toupper(again);
    }
}

void del(linkedQueueType<int>& q1){
    q1.deleteQueue();
    cout << "\nfirst item deleted\n" << endl;
}

void getCount(linkedQueueType<int>& q1){
    cout << "\n" << q1.queueCount() << " items in the queue\n" << endl;
}

void printContents(linkedQueueType<int>& q1){
    cout << "\nPrint all items in queue..." << endl;
    q1.printAll();
}
