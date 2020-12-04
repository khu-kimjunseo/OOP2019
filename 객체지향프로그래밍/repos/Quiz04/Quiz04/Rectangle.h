#pragma once
#include<iostream>
#include"Shape.h"
using namespace std;

class Rectangle :public Shape
{private:
	double length;
	double width;
public:
	Rectangle(int _num, int _length, int _width);
	double span() const override;
	double area() const override;
	void print() const override;
};

