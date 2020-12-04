#include<iostream>
using namespace std;
//sizeof()함수는 변수크기를 byte단위로 return
int main() {
	unsigned short siX;
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}