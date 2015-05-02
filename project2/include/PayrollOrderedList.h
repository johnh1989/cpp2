#ifndef PAYROLLORDEREDLIST_H
#define PAYROLLORDEREDLIST_H

#include "orderedLinkedList.h"
#include "Payroll.h"

using namespace std;

template <class Payroll>
class PayrollOrderedList: public orderedLinkedList<Payroll>
{
    public:
        PayrollOrderedList();
        virtual ~PayrollOrderedList();

        bool searchEmployee(Payroll&);
        void RunPayroll(int);
        void PrintByDept(int);


    protected: //NONE
    private:   //NONE
};

/*****************************************************/

template <class Payroll>
PayrollOrderedList<Payroll>::PayrollOrderedList()
{
    //ctor
}

template <class Payroll>
PayrollOrderedList<Payroll>::~PayrollOrderedList()
{
    //dtor
}

template <class Payroll>
bool PayrollOrderedList<Payroll>::searchEmployee(Payroll& searchItem)
{
    bool found = false;
    Payroll item;
    nodeType<Payroll> *current; //pointer to traverse the list

    current = PayrollOrderedList<Payroll>::first;  //start the search at the first node

    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found){
       found = (current->info == searchItem); //test for equality
       if (found){
        searchItem = current->info;
       }

    }
    return found;
}//end search


template <class Payroll>
void PayrollOrderedList<Payroll>::RunPayroll(int department)
{
    nodeType<Payroll> *current;
    Payroll item;
    double amt;
    bool found = false;

    current = PayrollOrderedList<Payroll>::first;

    while (current != NULL){
        item = current->info;
        if (item.GetDeptNumber() == department){
            found = true;
            amt = item.CalculatePayAmount();
        }
        current = current->link;
    }
    if (found){
        cout << "processed payroll for deptartment " << department;
    }else{
        cout << "department " << department << " does not exist";
    }
}

template <class Payroll>
void PayrollOrderedList<Payroll>::PrintByDept(int department)
{
    nodeType<Payroll> *current;
    Payroll item;
    double amt;
    bool found = false;

    current = PayrollOrderedList<Payroll>::first;

    while (current != NULL){
        item = current->info;
        if (item.GetDeptNumber() == department){
            found = true;
            amt = item.CalculatePayAmount();
            cout << item;
        }
        current = current->link;
    }
    if (found){
        cout << "processed payroll for deptartment " << department;
    }else{
        cout << "department " << department << " does not exist";
    }
}
#endif // PAYROLLORDEREDLIST_H
