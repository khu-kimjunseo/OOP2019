#include<iostream>
using namespace std;
//�� �� ����ϰ�

int main() {
	int num;
	do {
		cout << "number : ";
		cin >> num;
		if (num > 0) {
			switch (num % 2) {
			case 0:
				cout << num << "�� ¦���Դϴ�." << endl;
				break;
			default:
				cout << num << "�� Ȧ���Դϴ�." << endl;
				break;
			}
		}
	} while (num > 0 );
	cout << "�߸��� �����Դϴ�." << endl;

	return 0;
}
/*
int main() {
	int num=1;
	cout << "number : ";
	cin >> num;
	while (num > 0) {
		if (num % 2 == 1)
			cout << num << "�� Ȧ���Դϴ�." << endl;
		else
			cout << num << "�� ¦���Դϴ�." << endl;
		cout << "number : ";
		cin >> num;
	}
	cout << "�߸��� �����Դϴ�." << endl;
}
*/