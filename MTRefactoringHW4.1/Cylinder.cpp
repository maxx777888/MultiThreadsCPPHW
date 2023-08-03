#define _USE_MATH_DEFINES
#include "Cylinder.h"
#include<cmath>

Cylinder::Cylinder(int x1_, int y1_, double R, double H)
{
	x1 = x1_; y1 = y1_;
	radius = R;
	height = H;

	square = M_PI * R * R + 2 * R * height;
	volume = M_PI * R * R * height;
}

double Cylinder::getVolume()
{
	return volume;
}

double Cylinder::getSquare()
{
	return square;
}
