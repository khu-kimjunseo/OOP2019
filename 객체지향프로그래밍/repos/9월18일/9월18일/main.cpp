#include <iostream>
#include <iomanip>
using namespace std;

// while: ��ȣ( )���� ���̸� block����, ������ ������ �ٽ� ��ȣ�� ��/���� �˻�
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
//if-else if-else: ���������� ��ȣ���� ������ Ž���� ���� '��' �κ��� block�� ����
// 1) �ݵ�� ó������ if�� �����ش�.
// 2) else�� ���� �ִ� ��� ������ ������ ��� �ڵ� ����(default)
// 3) block�� ������ �ϳ��� ��� �߰�ȣ{}�� ���� ����

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
	bool c = 1000; //0�� �ƴϸ� �׻� 1
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