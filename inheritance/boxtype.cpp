#include <iostream>
#include "rectangleType.h"
#include "boxtype.h"

using namespace std;

void boxType::setDimension(double l, double w, double h){
	rectangleType::setDimension(l, w);
	height = h;
}
double boxType::getHeight() const
{
	return height;
}

double boxType::area() const
{
	return  2 * (getLength() * getWidth()
		+ getLength() * height
		+ getWidth() * height);
}

double boxType::volume() const
{
	return rectangleType::area() * height;
}


boxType::boxType()
{
	height = 0.0;
}

boxType::boxType(double l, double w, double h)
	: rectangleType(l, w)
{
	if (h >= 0)
		height = h;
	else
		height = 0;
}