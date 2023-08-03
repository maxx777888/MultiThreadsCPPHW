#include "Line.h"
#include <iostream>

Line::Line(int x1_, int y1_, int x2_, int y2_)
{
	x1 = x1_;
	x2 = x2_;
	y1 = y1_;
	y2 = y2_;
	name = "Line";

	square = 0;
	volume = 0;
}

double Line::getSquare()
{
	return square;
}

double Line::getVolume()
{
	return volume;
}

void Line::make_shift(int m, int n)
{
	x1 += m; y1 += n;
	x2 += m; y2 += n;
}

void Line::make_scaleX(int a)
{
	x1 *= a;
	x2 *= a;
}

void Line::make_scaleY(int d)
{
	y1 *= d;
	y2 *= d;
}

void Line::make_scale(int s)
{
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
}

void Line::print_shape()
{
	std::cout << "x1 = " << x1 << " y1 = " << y1;
	std::cout << " x2 = " << x2 << " y2 = " << y2 << std::endl;
}




