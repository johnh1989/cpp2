#include <iostream>
#include "rectangletype.h"
#include "boxtype.h"


using namespace std;

int main(){
	rectangleType rect1(2, 4);
	rectangleType rect2(4, 8);
	boxType box1(5, 10, 2);
	boxType box2(2, 2, 2);
	box1.setDimension(2, 2, 2);

	cout << rect1.area() << endl;
	cout << rect2.area() << endl;

	cout << box1.volume() << endl;
	cout << box2.volume() << endl;
	system("pause");
	return 0;
}