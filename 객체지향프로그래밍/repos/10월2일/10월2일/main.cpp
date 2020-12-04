#include<iostream>
using namespace std;

//swap(int a, int b): pass by value (단순히 값 복사)
//swap(int &a, int &b): pass by reference (x, a는 같은 메모리 공간을 사용)
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
// &x: x의 주소값을 반환
// int* px: 포인터 변수(주소값을 저장하는 변수) 선언, 주소값이 정수형이면 int*, 실수형이면 double*
// *px: px에 저장된 주소값으로 jump in


int main() {
	int x = 10;
	int* px = &x;

	cout << x << '\t' << &x << endl;
	cout << *px << '\t' << px << '\t' << &px << endl;



	return 0;
}
*/