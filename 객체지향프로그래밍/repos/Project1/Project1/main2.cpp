#include <iostream>
using namespace std;

int main() {
	cout << (7 >= 5) << endl;//참 1
	cout << (7 == 5) << endl;//거짓 0
	cout << (7 != 5) << endl;//참 1

	cout << (7 >= 5 ? '참' : '거짓') << endl;//참일때는 '참' 거짓일때는 '거짓'
	cout << (7 >= 5 ? 1000 : -1000) << endl;//참일때는 1000 거짓일때는 -1000

}

/*
int main() {
	int x = 10, int y = 20; //초기화
	x += y; //= x + y
	x %= y; //= x % y (compound assignment)

	x = 20;
	cout << x++ << endl; //전위증가연산자 : stat를 실행 후 x를 1증가
	cout << ++x << endl; //후의증가연산자 : x를 1증가 후 stat를 실행

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

	cout << x << '\t' << y << '\n'; //\t는 문자(tab 특수문자), \n은 endl
	cout << sum << endl;
	cout << mult << endl;
	cout << div << endl; // 0이 출력, 이유는 x, y가 정수이기 때문
	cout << mod << endl;

}*/