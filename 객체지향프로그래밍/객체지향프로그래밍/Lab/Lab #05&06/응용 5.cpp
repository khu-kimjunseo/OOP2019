#include<iostream>
using namespace std;

int Gcd(int a, int b);

int main() {
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "gcd(" << x << "," << y << ") = " << Gcd(x, y) << endl;
}

int Gcd(int a, int b) {
	int q, r;
	q = a / b;
	r = a % b;
	if (q == 1) {
		return Gcd(b, r);
	}
	else if(r == 0) {
		return b;
	}
}