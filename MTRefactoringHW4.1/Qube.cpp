#include "Qube.h"
#include <iostream>

Qube::Qube(int x1_, int y1_, int z1_, int x2_, int y2_, int z2_,
	int x3_, int y3_, int z3_, int x4_, int y4_, int z4_,
	int x5_, int y5_, int z5_, int x6_, int y6_, int z6_,
	int x7_, int y7_, int z7_, int x8_, int y8_, int z8_)
{
	x1 = x1_; y1 = y1_; z1 = z1_;
	x2 = x2_; y2 = y2_; z2 = z2_;
	x3 = x3_; y3 = y3_; z3 = z3_;
	x4 = x4_; y4 = y4_; z4 = z4_;
	x5 = x5_; y5 = y5_; z5 = z5_;
	x6 = x6_; y6 = y6_; z6 = z6_;
	x7 = x7_; y7 = y7_; z7 = z7_;
	x8 = x8_; y8 = y8_; z8 = z8_;

	name = "Qube";

	a = abs(x1 - x2);
	b = abs(y1 - y2);
	c = abs(z1 - z2);

	square = 2 * a * b + 2 * a * c + 2 * b * c;
	volume = a * b * c;
}

double Qube::getSquare()
{
	return square;
}

double Qube::getVolume()
{
	return volume;
}

void Qube::make_shift(int m, int n)
{
	std::cout << "Ошибка, нужно ввести также координату z!" << std::endl;
}

void Qube::make_shift(int m, int n, int k)
{
	x1 += m; y1 += n; z1 += k;
	x2 += m; y2 += n; z2 += k;
	x3 += m; y3 += n; z3 += k;
	x4 += m; y4 += n; z4 += k;
	x5 += m; y5 += n; z5 += k;
	x6 += m; y6 += n; z6 += k;
	x7 += m; y7 += n; z7 += k;
	x8 += m; y8 += n; z8 += k;
}

void Qube::make_scaleX(int a)
{
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
	x5 *= a;
	x6 *= a;
	x7 *= a;
	x8 *= a;
}

void Qube::make_scaleY(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
	y5 *= d;
	y6 *= d;
	y7 *= d;
	y8 *= d;
}

void Qube::make_scaleZ(int e)
{
	z1 *= e;
	y2 *= e;
	z3 *= e;
	z4 *= e;
	z5 *= e;
	z6 *= e;
	z7 *= e;
	z8 *= e;
}

void Qube::make_scale(int s)
{
	x1 /= s; y1 /= s; z1 /= s;
	x2 /= s; y2 /= s; z2 /= s;
	x3 /= s; y3 /= s; z3 /= s;
	x4 /= s; y4 /= s; z4 /= s;
	x5 /= s; y5 /= s; z5 /= s;
	x6 /= s; y6 /= s; z6 /= s;
	x7 /= s; y7 /= s; z7 /= s;
	x8 /= s; y8 /= s; z8 /= s;
}

void Qube::print_shape()
{
	/*std::cout << "x1 = " << x1 << " y1 = " << y1 << " z1 = " << z1;
	
	std::cout << " x2 = " << x2 << " y2 = " << y2 << " z2 = " << z2;
	std::cout << " x3 = " << x3 << " y3 = " << y3 << " z3 = " << z3;
	std::cout << " x4 = " << x4 << " y4 = " << y4 << " z4 = " << z4;
	std::cout << " x5 = " << x5 << " y5 = " << y5 << " z5 = " << z5;
	std::cout << " x6 = " << x6 << " y6 = " << y6 << " z6 = " << z6;
	std::cout << " x7 = " << x7 << " y7 = " << y7 << " z7 = " << z7;
	std::cout << " x8 = " << x8 << " y8 = " << y8 << " z8 = " << z8 << std::endl;*/

	std::cout << "k1(" << x1 << ", " << y1 << ", " << z1 << "), ";
	std::cout << "k2(" << x2 << ", " << y2 << ", " << z2 << "), ";
	std::cout << "k3(" << x3 << ", " << y3 << ", " << z3 << "), ";
	std::cout << "k4(" << x4 << ", " << y4 << ", " << z4 << "), ";
	std::cout << "k5(" << x5 << ", " << y5 << ", " << z5 << "), ";
	std::cout << "k6(" << x6 << ", " << y6 << ", " << z6 << "), ";
	std::cout << "k7(" << x7 << ", " << y7 << ", " << z7 << "), ";
	std::cout << "k8(" << x8 << ", " << y8 << ", " << z8 << ")" << std::endl;
}
