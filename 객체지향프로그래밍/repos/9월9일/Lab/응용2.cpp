#include<iostream>
using namespace std;

void print_DOB(int year = 1990, int month = 1, int day = 1);

int main() {
	int x, y, z;
	print_DOB();
	cout << "year �Է� : ";
	cin >> x;
	cout << "month �Է� : ";
	cin >> y;
	cout << "day �Է� : ";
	cin >> z;
	print_DOB(x, y, z);

	return 0;

}

void print_DOB(int year, int month, int day) {
	cout << "��������� " << year << "�� " << month << "�� " << day << "���Դϴ�." << endl;
}