#include<iostream>

using namespace std;

int main() {
	int num;
	do {
		cout << "number : ";
		cin >> num;
		if (num >= 1 && num <= 9) {
			for (int i = 1; i <= 9; i++) {
				int val = num * i;
				cout << num << "*" << i << " = " << val << " ";
			}
			cout << endl;
		}
		else break;
	} while (true);
	cout << "잘못된 숫자입니다." << endl;

	return 0;
}
