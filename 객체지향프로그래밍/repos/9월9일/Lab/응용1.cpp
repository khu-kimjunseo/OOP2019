#include <iostream>
using namespace std;

int myadd(int a, int b);
int mysub(int a, int b);
int mymul(int a, int b);
float mydiv(int a, int b);
int addmul(int x, int y, int z);
float muldiv(int x, int y, int z);
int addmuladd(int x, int y, int z);
float subdivsub(int x, int y, int z);

int main() {
	int x, y, z;
	cout << "Enter a number: ";
	cin >> x;
	cout << "Enter a number: ";
	cin >> y;
	cout << "Enter a number: ";
	cin >> z;
	cout << "x = " << x << ", y = " << y << ", z = " << endl;
	cout << "(x + y) * z = " << addmul(x, y, z) << endl;
	cout << "(x * y) / z = " << muldiv(x, y, z) << endl;
	cout << "(x + y) * (y + z) = " << addmuladd(x, y, z) << endl;
	cout << "(x - y) / (y - z) = " << subdivsub(x, y, z) << endl;
}

int myadd(int a, int b) {
	return a + b;
}
int mysub(int a, int b) {
	return a - b;
}
int mymul(int a, int b) {
	return a * b;
}
float mydiv(int a, int b) {
	return float(a) / b;
}
int addmul(int x, int y, int z) {
	return mymul(myadd(x, y), z);
}
float muldiv(int x, int y, int z) {
	return mydiv(float(mymul(x, y)), z);
}
int addmuladd(int x, int y, int z) {
	return mymul(myadd(x, y), myadd(y, z));
}
float subdivsub(int x, int y, int z) {
	return mydiv(float(mysub(x, y)), mysub(y, z));
}