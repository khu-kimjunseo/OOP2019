#include <iostream>
#include <iomanip>
using namespace std;

// while : 조건문 -> block -> 조건문
// do{}while(); : block -> 조건문 -> block
// for(초기화; 반복조건; 업데이트){}

//switch():case와 default로 구성, break를 통해 빠져나감

int main() {
	char input;
	cout << "Enter a key: ";
	cin >> input;
	switch (input) {
	case 'P': //같은 동작을 하는 case문은 묶어줄 수 있음
	case 'p':
		cout << "Pause" << endl;
		break;
	case 'q':
	case 'Q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
		break; // default 에서는 break를 안적어도 됨.
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
	
	for (초기화; 반복조건; 업데이트) {
		statement
	}
	int i = 1; // 초기화(initialization)
	while (i <= 100) {// 반복조건(condition)
		sum += i; //sum = sum + i;  // block, statement, body
		i++; // 업데이트(modification)
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