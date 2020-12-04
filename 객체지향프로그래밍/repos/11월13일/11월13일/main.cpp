#include<iostream>
using namespace std;

class Base {
public:
	void f() {
		cout << "Base::f()" << endl;
	}
};

class Derived :public Base {
public:
	void g() {
		cout << "Derived::g()" << endl;
	}
};

int main() {
	Base myB;
	Derived myD;
	myB.f();
	myD.g();

	myD.f();
	return 0;
}