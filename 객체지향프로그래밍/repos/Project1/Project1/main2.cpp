#include <iostream>
using namespace std;

int main() {
	cout << (7 >= 5) << endl;//�� 1
	cout << (7 == 5) << endl;//���� 0
	cout << (7 != 5) << endl;//�� 1

	cout << (7 >= 5 ? '��' : '����') << endl;//���϶��� '��' �����϶��� '����'
	cout << (7 >= 5 ? 1000 : -1000) << endl;//���϶��� 1000 �����϶��� -1000

}

/*
int main() {
	int x = 10, int y = 20; //�ʱ�ȭ
	x += y; //= x + y
	x %= y; //= x % y (compound assignment)

	x = 20;
	cout << x++ << endl; //�������������� : stat�� ���� �� x�� 1����
	cout << ++x << endl; //�������������� : x�� 1���� �� stat�� ����

}
*/

/*
int main() {
	int x, y, sum, mult, mod;
	float div;
	cin >> x >> y;
	sum = x + y;
	mult = x * y;
	div = float(x) / y;
	mod = x % y;

	cout << x << '\t' << y << '\n'; //\t�� ����(tab Ư������), \n�� endl
	cout << sum << endl;
	cout << mult << endl;
	cout << div << endl; // 0�� ���, ������ x, y�� �����̱� ����
	cout << mod << endl;

}*/