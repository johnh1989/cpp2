#include <iostream>
#include "linkedQueue.h"

using namespace std;

int main()
{

    linkedQueueType<int> m1;

    m1.addQueue(5);
    m1.addQueue(6);
    int x = m1.front();
    cout << x << endl;
    return 0;
}
