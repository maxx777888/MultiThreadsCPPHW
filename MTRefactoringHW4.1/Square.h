#pragma once
#include <string>
#include "Shape_transform_abstract.h"
class Square : public Shape_transform_abstract
{
public:
	Square(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_, int x4_, int y4_);
	Square() = delete;

	double getSquare();
	double getVolume();

	void make_shift(int m, int n) override;
	void make_scaleX(int a) override;
	void make_scaleY(int d) override;
	void make_scale(int s) override;

	void print_shape() override;

private:
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int a, b;
	double volume;
	double square;
	std::string name;
};

