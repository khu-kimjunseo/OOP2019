#include<iostream>
#include<iomanip>//stew�� cout ǥ���� ������
using namespace std;

int main() {
	int num = 1;
	int count = 1;
	cout.imbue(locale(""));
	while (count <= 20) {
		num = pow(2,count);
		cout << count << '\t' << setw(9) << num << endl;
		count++;
	}
	return 0;
}