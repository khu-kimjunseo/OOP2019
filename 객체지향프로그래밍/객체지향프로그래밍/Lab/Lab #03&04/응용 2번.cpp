#include<iostream>
using namespace std;

void print_DOB(int x = 1900, int y = 1, int z = 1);

int main() {
	print_DOB();
	int x, y, z;
	cout << "year �Է� : ";
	cin >> x;
	cout << "month �Է� : ";
	cin >> y;
	cout << "day �Է� : ";
	cin >> z;
	print_DOB(x, y, z);
	
	return 0;
}

void print_DOB(int x, int y, int z) {
	cout << "��������� "<<x<<"�� "<<y<<"�� "<<z<<"���Դϴ�." << endl;
}