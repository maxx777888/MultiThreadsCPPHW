#pragma once
class Circle
{
public:
	Circle(int x1_, int y1_, double R);
	Circle() = delete;
	double getVolume();
	double getSquare();
private:
	int x1, y1;
	double radius;
	double volume;
	double square;
};

