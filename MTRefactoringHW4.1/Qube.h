#pragma once
#include <string>
#include "Shape_transform_abstract.h"
class Qube : public Shape_transform_abstract
{
public:
	Qube(int x1_, int y1_, int z1_, int x2_, int y2_, int z2_,
		int x3_, int y3_, int z3_, int x4_, int y4_, int z4_,
		int x5_, int y5_, int z5_, int x6_, int y6_, int z6_,
		int x7_, int y7_, int z7_, int x8_, int y8_, int z8_);
	Qube() = delete;

	double getSquare();
	double getVolume();

	void make_shift(int m, int n, int k);
	void make_scaleX(int a) override;
	void make_scaleY(int d) override;
	void make_scaleZ(int e);
	void make_scale(int s) override;

	void print_shape() override;

	//Сделал потому что выдает ошибку "использование объекта абстрактного типа класса не допускается:"
	void make_shift(int m, int n) override;

private:
	int x1, x2, x3, x4, x5, x6, x7, x8;
	int y1, y2, y3, y4, y5, y6, y7, y8;
	int z1, z2, z3, z4, z5, z6, z7, z8;
	int a, b, c;
	double volume;
	double square;
	std::string name;
};

