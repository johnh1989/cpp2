#include <iostream>
#include <math.h>
//first 25 elements should be eual to square of index
//second 25 should be equal to 3 times the index variable

using namespace std;

int main()
{
    const int INDEX = 50;
    double alpha[INDEX];
    for (int i = 0; i <=25; i++){
        alpha[i] = pow(i, 2);
    }
    for (int i = 25; i < INDEX; i++){
        alpha[i] = i*3;
    }
    for (int i = 0; i < INDEX; i++) {
        cout << alpha[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    return 0;
}
