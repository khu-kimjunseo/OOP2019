#include<iostream>
using namespace std;

void get_data(int& x, int& y);
void swap_call_by_value(int x, int y);
void swap_call_by_reference(int& x, int& y);

int main() {
	int x, y;
	get_data(x, y);

	cout << "\nswap_call_by_value 함수 사용 전" << endl;
	cout << "x = " << x << ", y = " << y << endl;
	swap_call_by_value(x, y);
	cout << "swap_call_by_value 함수 사용 후" << endl;
	cout << "x = " << x << ", y = " << y << endl;

	cout << "\nswap_call_by_reference 함수 사용 전" << endl;
	cout << "x = " << x << ", y = " << y << endl;
	swap_call_by_reference(x, y);
	cout << "swap_call_by_reference 함수 사용 후" << endl;
	cout << "x = " << x << ", y = " << y << endl;


	return 0;
}

void get_data(int& x, int& y) {
	cout << "x 입력 : ";
	cin >> x;
	cout << "y 입력 : ";
	cin >> y;
}

void swap_call_by_value(int x, int y) {
	int temp = x;
		x = y;
		y = temp;
}

void swap_call_by_reference(int& x, int& y) {
	int temp = x;
		x = y;
		y = temp;
}