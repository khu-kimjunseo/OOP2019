#pragma once
#include<iostream>
using namespace std;

class Shape
{protected:
	int numSides;
public:
	Shape(int _num) : numSides(_num) {}
	virtual double span() const = 0;
	virtual double area() const = 0;
	virtual void print() const = 0;
};

