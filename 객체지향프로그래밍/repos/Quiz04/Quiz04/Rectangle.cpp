#include "Rectangle.h"

Rectangle::Rectangle(int _num, int _length, int _width) : Shape::Shape(_num), length(_length), width(_width) {}
double Rectangle::span() const { 
	if (length > width)
		return double(length);
	else
		return double(width);
}
double Rectangle::area() const {
	return double(length * width);
}
void Rectangle::print() const {
	cout << "[Rectangle]" << endl << "Span=" << span() << endl << "Area=" << area() << endl << endl;
}