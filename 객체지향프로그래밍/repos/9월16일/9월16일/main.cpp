#include<iostream>
using namespace std;

int factorial(int n) {
	//termination condition
	if (n == 0)
		return 1;

	//base condition
	return n * factorial(n - 1);
}
int main() {
	int x = 5;
	cout << factorial(x) << endl;

	return 0;
}
/*
//int& : reference value
int main() {
	int x = 10;
	int& y = x; //y�� x�� reference value
	cout << x << '\t' << y << endl;
	x = 1000;
	cout << x << '\t' << y << endl;


	return 0;
}
*/

/*
//call by value, pass by value: �Լ��� �Է� ���ڿ� ���縦 ���� ����
//call by refernece, pass by reference: �Լ��� �Է� ���ڸ� reference value�� ����
//pass by value(int a), pass by reference(int& a)
void swap(int& a, int& b) {
	int temp = a;
		a = b;
		b = temp;
}
int main() {
	int x = 10, y = 1000;
	
	cout << x << '\t' << y << endl;
	swap(x, y);
	cout << x << '\t' << y << endl;
		
	return 0;
}
*/

/*
//local variable: �Լ� �ȿ����� ����, �Լ��� ����Ǹ� �����
//global variable: �Լ� �ܺο� ����Ǿ� ��� �Լ����� ���������� ��밡��
//�켱����: local variable >>> global variable

int gVar;

void print() {
	gVar = 1000;
}

int main() {
	int gVar; 
	gVar = 10;
	cout << gVar << endl;
	print();
	cout << gVar << endl;


	return 0;
}
*/

/*
void increase(int x) {
	x++;
}

int main() {
	int x = 10;
	cout << x << endl;
	increase(x);
	cout << x << endl;


	return 0;
}
*/

	
