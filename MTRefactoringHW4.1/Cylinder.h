#pragma once
class Cylinder
{
public:
	Cylinder(int x1_, int y1_, double R, double H);
	Cylinder() = delete;

	double getVolume();
	double getSquare();

private:
	int x1, y1;
	double radius, height;
	double volume;
	double square;
};

