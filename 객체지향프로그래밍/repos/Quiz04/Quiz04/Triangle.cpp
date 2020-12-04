#include "Triangle.h"

Triangle::Triangle(int _num, int _side1, int _side2, int _side3) : Shape::Shape(_num), side1(_side1), side2(_side2), side3(_side3) {}
double Triangle::span() const {
	int temp = side1;
	if (temp < side2) {
		temp = side2;
		if (temp < side3) {
			temp = side3;
		}
	}
	else if (temp < side3)
		temp = side3;
	return double(temp);
}
double Triangle::area() const {
	double s, area;
	s = (side1 + side2 + side3) / 2;
	area = s * (s - side1) * (s - side2) * (s - side3);
	return area;
}
void Triangle::print() const {
	cout << "[Triangle]" << endl << "Span=" << span() << endl << "Area=" << area() << endl << endl;
}
