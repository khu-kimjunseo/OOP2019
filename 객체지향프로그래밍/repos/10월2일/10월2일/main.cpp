#include<iostream>
using namespace std;

//swap(int a, int b): pass by value (�ܼ��� �� ����)
//swap(int &a, int &b): pass by reference (x, a�� ���� �޸� ������ ���)
//swap(int* a, int* b): pass by address
void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}
int main() {
	int x = 10, y = 2000;
	cout << x << '\t' << y << endl;

	swap(&x, &y);
	cout << x << '\t' << y << endl;



	return 0;
}
/*
// &x: x�� �ּҰ��� ��ȯ
// int* px: ������ ����(�ּҰ��� �����ϴ� ����) ����, �ּҰ��� �������̸� int*, �Ǽ����̸� double*
// *px: px�� ����� �ּҰ����� jump in


int main() {
	int x = 10;
	int* px = &x;

	cout << x << '\t' << &x << endl;
	cout << *px << '\t' << px << '\t' << &px << endl;



	return 0;
}
*/