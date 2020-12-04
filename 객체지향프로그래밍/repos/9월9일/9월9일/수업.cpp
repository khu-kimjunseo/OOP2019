#include <iostream>
#include<cmath>//log, exp, cos, sqrt
using namespace std;


//default argument: 1)선언부에서 사용, 구현부에서 사용시 오류
//					2)왼쪽부터 순차적으로 할당
void point(int x = 1000, int y = 2000); //void 자료형은 출력값이 없는 함수일 때 사용

int main() {
	point(1, 2);
	point();
	point(1);
	//point(, 1);은 2)에 의해 불가능
}

void point(int x, int y) {
	cout << x << '\t' << y << endl;
}

/* cmath 라이브러리
int main() {
	double x = 10.0;//초기화(initialization): 선언과 동시에 할당
	cout << cos(x) << endl;//코사인
	cout << log(x) << endl;//밑이 e인 로그, 즉 ln(x)
	cout << sqrt(x) << endl;//루트
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
	cout << "Enter a number: ";//문자는 작은따옴표, 문자열은 큰 따옴표
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
	return 1.0 * a / b;//1.0을 곱하는 이유는 실수형을 출력하기 위해. float(a) / b와 같은 결과
}
*/



/*
//함수를 만드는 방법
int square(int a);// 1) 선언(prototype): 함수의 원형을 만듬. 출력자료형[int], 함수이름(입력 변수)[square(int a)]


int main() {
	int x;

	x = 10;
	cout << square(x) << endl;// 3) 호출(calling)

	x = 100;
	cout << square(x) << endl;

}

// 2) 정의(구현): main함수 아래에 작성
int square(int a) {
	return a * a;
}
*/