#pragma once
#include <string>
#include "Shape_transform_abstract.h"


class Line : public Shape_transform_abstract
{
public:
	Line(int x1_, int y1_, int x2_, int y2_);
	Line() = delete;

	double getSquare();
	double getVolume();

	void make_shift(int m, int n) override;
	void make_scaleX(int a) override;
	void make_scaleY(int d) override;
	void make_scale(int s) override;


	void print_shape() override;

private:
	int x1, x2, y1, y2;
	double volume;
	double square;
	std::string name;
};

