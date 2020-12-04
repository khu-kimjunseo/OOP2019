#include<iostream>
#include<fstream>
using namespace std;

int main() {

	/* POINT
	1. 띄어쓰기 사용
	2. enter => 띄어쓰기
	3. 줄 맨 앞에 띄어쓰기가 오지 않도록 함
	*/

	ifstream fin("txt1.txt");
	ofstream fout("txt2.txt");
	int length;

	cout << "길이 : ";
	cin >> length;


	fin.unsetf(ios::skipws); // 띄어쓰기도 사용

	char temp;
	int size = 0;
	while (fin >> temp) {	// temp에 받아올게 있을 때 까지

		if (temp == '\n')	// enter를 띄어쓰기로 변환
			temp = ' ';

		if (size < length) {
			fout << temp;
			size++;
		}
		else {	// size == length 일 때
			if (temp == ' ')	// 줄 맨앞에 띄어쓰기가 오면 그 다음 글자 받음.
				continue;

			fout << endl << temp;
			size = 1;
		}
	}


}