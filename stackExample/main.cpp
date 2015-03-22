#include <iostream>
#include "linkedStack.h"
#include <string>


using namespace std;


void mystery(linkedStackType<int>& s, linkedStackType<int>& t);

int main(){

    int list[] = {5,10,15,20,25}; //should be braces not parentasees here

    linkedStackType<int> s1;
    linkedStackType<int> s2;

    for (int i = 0; i < 5; i++) // should be semicolons, no commas
        s1.push(list[i]);

    mystery (s1, s2);

    while (!s2.isEmptyStack()){

        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}
//multiplies top value from stack1 by 2, pushes it onto stack2, then pops from stack1 while the stack is not empty
void mystery(linkedStackType<int>& s, linkedStackType<int>& t){

    while (!s.isEmptyStack()){

       t.push(2 * s.top()); //added semicolon
       s.pop();
    }

}


/*
The output is 10,20,30,40,50.

mystery function takes the top value from stack1 (s1), multiples it by 2 and pushes on to stack2, then pops that value from the stack

and continues until the stack is empty

 corrected code with comments

void mystery(linkedStackType<int>& s, linkedStackType<int>& t);

int main(){

    int list[] = {5,10,15,20,25}; //should be braces not parentasees here

    linkedStackType<int> s1;
    linkedStackType<int> s2;

    for (int i = 0; i < 5; i++) // should be semicolons, not commas
        s1.push(list[i]);

    mystery (s1, s2);

    while (!s2.isEmptyStack()){

        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}

void mystery(linkedStackType<int>& s, linkedStackType<int>& t){

    while (!s.isEmptyStack()){

       t.push(2 * s.top()); //added semicolon
       s.pop();
    }

}

*/
