#include<iostream>
#include<fstream>
using namespace std;

int main() {

	/* POINT
	1. ���� ���
	2. enter => ����
	3. �� �� �տ� ���Ⱑ ���� �ʵ��� ��
	*/

	ifstream fin("txt1.txt");
	ofstream fout("txt2.txt");
	int length;

	cout << "���� : ";
	cin >> length;


	fin.unsetf(ios::skipws); // ���⵵ ���

	char temp;
	int size = 0;
	while (fin >> temp) {	// temp�� �޾ƿð� ���� �� ����

		if (temp == '\n')	// enter�� ����� ��ȯ
			temp = ' ';

		if (size < length) {
			fout << temp;
			size++;
		}
		else {	// size == length �� ��
			if (temp == ' ')	// �� �Ǿտ� ���Ⱑ ���� �� ���� ���� ����.
				continue;

			fout << endl << temp;
			size = 1;
		}
	}


}