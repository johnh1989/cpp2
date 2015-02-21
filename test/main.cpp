#include <iostream>

using namespace std;

class classA{

public:
    void print () const;
    void doublenum();
    classA (int a=0);

private:
    int x;
};

void classA::print() const{

cout << "ClassA x: " << x << endl;
}

void classA::doublenum (){

x = 2 * x;
}

classA::classA (int a){

x = a;
}

class classB: public classA{

public:
    void print () const;
    void doubleNum ();
    classB (int a = 0, int b = 0);

private:
    int y;
};

void classB::print() const{

    classA::print ();
    cout << "ClassB y: " << y << endl;
}

void classB::doubleNum(){

    classA::doublenum();
    y = 2 * y;
}

classB::classB (int a, int b) : classA(a){

y = b;
}

//What is the output of the following function main?

int main(){

    classA *ptrA;
    classA objectA(2);
    classB objectB (3,5);

    ptrA = &objectA;
    ptrA->doublenum();
    ptrA->print();
    cout << endl;

    ptrA = &objectB;
    ptrA->doublenum();
    ptrA->print();
    cout << endl;
    return 0;
}
