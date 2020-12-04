#include <iostream>
#include <iomanip>
using namespace std;

// while: 괄호( )안이 참이면 block수행, 수행이 끝나면 다시 괄호안 참/거짓 검사
int main() {
	int row = 1, col = 1;
	int n;
	cin >> n;
	while (row <= n) {
		while (col <= n) {
//			int val = row * col;
//			int val = (row > col ? row : col);
			int val = 0;
			if (row == col)
				val = 1;
			cout << setw(4) <<val ;
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}
}


/*
int main() {
	int x = 0, i = 1;
	int n;
	cin >> n;
	
	while (i <= n) {
		x += i;
		cout << i << '\t' << x << endl;
		i++;
	}
	
	return 0;
}
*/

/*
//if-else if-else: 순차적으로 괄호안의 조건을 탐색한 다음 '참' 부분의 block을 수행
// 1) 반드시 처음에는 if를 적어준다.
// 2) else는 위에 있는 모든 조건이 거짓일 경우 자동 수행(default)
// 3) block안 문장이 하나일 경우 중괄호{}는 생략 가능

int main() {
	int score;
	char grade;
	cout << "Enter the score(0-100): ";
	cin >> score;
	if (score >= 0 && score <= 100) {
		if (score >= 90)
			grade = 'A';
		else if (score >= 80)
			grade = 'B';
		else if (score >= 70)
			grade = 'C';
		else
			grade = 'F';
		cout << "Your grade is " << grade << endl;
	}
	else 
		cout << "Invalid range" << endl;
	

	return 0;
}
*/

/*
int main() {
	bool a = true;
	bool b = (10 >= 5);
	bool c = 1000; //0이 아니면 항상 1
	bool d = 0;
	bool e = -0.0000000000000001;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	



	return 0;
}
*/