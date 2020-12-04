#include<iostream>
using namespace std;
//좀 더 깔끔하게

int main() {
	int num;
	do {
		cout << "number : ";
		cin >> num;
		if (num > 0) {
			switch (num % 2) {
			case 0:
				cout << num << "은 짝수입니다." << endl;
				break;
			default:
				cout << num << "은 홀수입니다." << endl;
				break;
			}
		}
	} while (num > 0 );
	cout << "잘못된 숫자입니다." << endl;

	return 0;
}
/*
int main() {
	int num=1;
	cout << "number : ";
	cin >> num;
	while (num > 0) {
		if (num % 2 == 1)
			cout << num << "은 홀수입니다." << endl;
		else
			cout << num << "은 짝수입니다." << endl;
		cout << "number : ";
		cin >> num;
	}
	cout << "잘못된 숫자입니다." << endl;
}
*/