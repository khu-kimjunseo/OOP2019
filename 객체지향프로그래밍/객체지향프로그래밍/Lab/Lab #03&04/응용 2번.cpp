#include<iostream>
using namespace std;

void print_DOB(int x = 1900, int y = 1, int z = 1);

int main() {
	print_DOB();
	int x, y, z;
	cout << "year 입력 : ";
	cin >> x;
	cout << "month 입력 : ";
	cin >> y;
	cout << "day 입력 : ";
	cin >> z;
	print_DOB(x, y, z);
	
	return 0;
}

void print_DOB(int x, int y, int z) {
	cout << "생년월일은 "<<x<<"년 "<<y<<"월 "<<z<<"일입니다." << endl;
}