#pragma once
#include<iostream>
#include"Shape.h"
using namespace std;

class Triangle : public Shape
{private:
	double side1;
	double side2;
	double side3;
public:
	Triangle(int _num, int _side1, int _side2, int _side3);
	double span() const override;
	double area() const override;
	void print() const override;
};

