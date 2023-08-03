#pragma once
class Shape_transform_abstract
{
public:

	virtual void make_shift(int m, int n) = 0;
	//virtual void make_shift(int m, int n, int k) = 0; //Убрал потому что выдает ошибку в других классах
	virtual void make_scaleX(int a) = 0;
	virtual void make_scaleY(int d) = 0;
	virtual void make_scale(int s) = 0;
	virtual void print_shape() = 0;
};

