#include <iostream>
#include <iomanip>
using namespace std;

// while : ���ǹ� -> block -> ���ǹ�
// do{}while(); : block -> ���ǹ� -> block
// for(�ʱ�ȭ; �ݺ�����; ������Ʈ){}

//switch():case�� default�� ����, break�� ���� ��������

int main() {
	char input;
	cout << "Enter a key: ";
	cin >> input;
	switch (input) {
	case 'P': //���� ������ �ϴ� case���� ������ �� ����
	case 'p':
		cout << "Pause" << endl;
		break;
	case 'q':
	case 'Q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
		break; // default ������ break�� ����� ��.
	}
	return 0;
}
/*
int main() {
	int size;
	cout << "Enter a size: " ;
	cin >> size;

	for (int row = 1; row <= size; row++) {
		for (int col = 1; col <= size; col++) {
			int val = row * col;
			cout << setw(6) << val;
		}
		cout << endl;
	}
}
*/

/*
int main() {
	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
	}
	
	for (�ʱ�ȭ; �ݺ�����; ������Ʈ) {
		statement
	}
	int i = 1; // �ʱ�ȭ(initialization)
	while (i <= 100) {// �ݺ�����(condition)
		sum += i; //sum = sum + i;  // block, statement, body
		i++; // ������Ʈ(modification)
	}
	
	cout << sum << endl;
	
	return 0;
}
*/

/*
int main() {
	int input;
	do {
		cout << "Enter a number [0, 10] :";
		cin >> input;
	} while ( !(input >= 0 && input <= 10) );
	cout << "Output: " << input << endl;
	
	return 0;
}
*/

/*
int main() {
	int sum = 0;
	int input;
	while (true) {
		cout << "Enter a number: ";
		cin >> input;
		if (input < 0)
			break;
//			continue;

		sum += input;
		cout << "Sum :" << sum << endl;
	}

	return 0;
}
*/