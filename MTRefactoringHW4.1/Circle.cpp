#define _USE_MATH_DEFINES
#include "Circle.h"
#include<cmath>


Circle::Circle(int x1_, int y1_, double R)
{
	x1 = x1_; y1 = y1_;
	radius = R;
	square = M_PI * R * R;
	volume = 0;
}

double Circle::getVolume()
{
	return volume;
}

double Circle::getSquare()
{
	return square;
}
