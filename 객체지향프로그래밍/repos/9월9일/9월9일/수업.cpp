#include <iostream>
#include<cmath>//log, exp, cos, sqrt
using namespace std;


//default argument: 1)����ο��� ���, �����ο��� ���� ����
//					2)���ʺ��� ���������� �Ҵ�
void point(int x = 1000, int y = 2000); //void �ڷ����� ��°��� ���� �Լ��� �� ���

int main() {
	point(1, 2);
	point();
	point(1);
	//point(, 1);�� 2)�� ���� �Ұ���
}

void point(int x, int y) {
	cout << x << '\t' << y << endl;
}

/* cmath ���̺귯��
int main() {
	double x = 10.0;//�ʱ�ȭ(initialization): ����� ���ÿ� �Ҵ�
	cout << cos(x) << endl;//�ڻ���
	cout << log(x) << endl;//���� e�� �α�, �� ln(x)
	cout << sqrt(x) << endl;//��Ʈ
	cout << exp(x) << endl;//e^x


	return 0;
}
*/

/*
int get_data();
int sum(int a, int b);
int subt(int a, int b);
int mult(int a, int b);
float idiv(int a, int b);

int main() {
	int x, y;
	x = get_data();
	y = get_data();

	cout << "x + y = " << sum(x, y) << endl;
	cout << "x - y = " << subt(x, y) << endl;
	cout << "x * y = " << mult(x, y) << endl;
	cout << "x / y = " << idiv(x, y) << endl;

	return 0;
}

int get_data() {
	int a;
	cout << "Enter a number: ";//���ڴ� ��������ǥ, ���ڿ��� ū ����ǥ
	cin >> a;
	return a;
}

int sum(int a, int b) {
	return a + b;
}

int subt(int a, int b) {
	return a - b;
}

int mult(int a, int b) {
	return a * b;
}

float idiv(int a, int b) {
	return 1.0 * a / b;//1.0�� ���ϴ� ������ �Ǽ����� ����ϱ� ����. float(a) / b�� ���� ���
}
*/



/*
//�Լ��� ����� ���
int square(int a);// 1) ����(prototype): �Լ��� ������ ����. ����ڷ���[int], �Լ��̸�(�Է� ����)[square(int a)]


int main() {
	int x;

	x = 10;
	cout << square(x) << endl;// 3) ȣ��(calling)

	x = 100;
	cout << square(x) << endl;

}

// 2) ����(����): main�Լ� �Ʒ��� �ۼ�
int square(int a) {
	return a * a;
}
*/