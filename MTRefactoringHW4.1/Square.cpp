#include "Square.h"
#include <iostream>

Square::Square(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_, int x4_, int y4_)
{
	x1 = x1_; y1 = y1_;
	x2 = x2_; y2 = y2_;
	x3 = x3_; y3 = y3_;
	x4 = x4_; y4 = y4_;

	name = "Square";

	a = abs(x1 - x2);
	b = abs(y1 - y2);

	square = a * b;
	volume = 0;
}

double Square::getSquare()
{

	return square;
}

double Square::getVolume()
{
	return volume;
}

void Square::make_shift(int m, int n)
{
	x1 += m; y1 += n;
	x2 += m; y2 += n;
	x3 += m; y3 += n;
	x4 += m; y4 += n;

}

void Square::make_scaleX(int a)
{
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
}

void Square::make_scaleY(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
}

void Square::make_scale(int s)
{
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
	x3 /= s; y3 /= s;
	x4 /= s; y4 /= s;
}

void Square::print_shape()
{
	std::cout << "x1 = " << x1 << " y1 = " << y1;
	std::cout << " x2 = " << x2 << " y2 = " << y2;
	std::cout << " x3 = " << x3 << " y3 = " << y3;
	std::cout << " x4 = " << x4 << " y3 = " << y4 << std::endl;
}
