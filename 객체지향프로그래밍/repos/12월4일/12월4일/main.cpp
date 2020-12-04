#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>// for_each, copy, tarnsform
using namespace std;

// for_each: 람다함수에 return 존재 X
// transform: 람다함수에 return 존재 O
int main() {
	vector<int> v1{ 1, 2, 3, 4 };

	for (int elem : v1) 
		cout << elem << '\t';
	cout << endl;

	//for_each: continer의 각 element {main body}를 수행
	//for_each(src_시작_iter, src_끝_iter, 람다함수
	//src: source(원천)의 약자, dst: destination (목적지)
	for_each(begin(v1), end(v1), [](int elem) { cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int &elem) { elem++; });
	for_each (begin(v1), end(v1), [](int elem) { cout << elem << '\t'; });
	cout << endl;

	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) { elem += a; });
	for_each(begin(v1), end(v1), [](int elem) { cout << elem << '\t'; });
	cout << endl;

	vector<int> v2(v1.size());
	//copy(src_시작_iter, src_끝_iter, dst_시작_iter);
	copy(begin(v1)+1, end(v1)-1, begin(v2)+2); //vector는 iterator에 값을 더할 수 있지만 (연산자 overloadding이 되어 있음) 다른 container는 불가능
	for_each(begin(v2), end(v2), [](int elem) { cout << elem << '\t'; });
	cout << endl;

	//transform: source container의 element값을 변형하여 destination container에 전달
	//trasnform(src_시작_iter, src_끝_iter, dst_시작_iter, 람다함수
	transform(	begin(v1), end(v1), 
				begin(v2), 
				[](int elem) { return elem * elem; });
	for_each(begin(v2), end(v2), [](int elem) { cout << elem << '\t'; });
	cout << endl;

	return 0;
}
/*
// [closure]: lambda 함수의 외부 변수를 함수 내부에서 사용가능
// -closure를 사용하는 lambda 함수를 입력으로 받는 경우
//  반드시 function 객체를 사용할 것(#include <functional>), 함수 포인터 사용 불가능
// [a]: 변수 a를 함수 내부에 call by value로 전달
// [&a]: 변수 a를 함수 내부에 call by ref로 전달
// [=]: 외부의 모든 변수를 call by value로 전달
// [&]: 외부의 모든 변수를 call by ref로 전달

int evaluate2(function<int(int, int)> f, int x, int y) { 
	return f(x, y); 
}

int main() {
	int a = 20, b = 100;
	cout << evaluate2([&](int x, int y) {a = 1000; return a + b + x + y; }, 10, 20) << endl;
	cout << "a: " << a << endl;
}
*/

/*
// 함수를 main함수 외부에서 정의할 때 장점: 어디서든지 사용가능
//									  단점: 항상 메모리 공간을 차지하고 있음 --> 이를 해결하기 위해 람다함수를 사용

int evaluate(int (*f)(int, int), int x, int y) {
	return f(x, y);
}

int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }

int main() {
	
	cout << evaluate(&sum, 3, 5) << endl;
	cout << evaluate(&mult, 3, 5) << endl;

	//sum : [](int x, int y)->int { return x + y; }
	cout << evaluate([](int x, int y)->int {return x + y; }, 3, 5) << endl;

	//mult : [](int x, int y) { return x * y; } 람다함수는 출력 datatype(->int)을 적지 않아도 상관없음
	cout << evaluate([](int x, int y) {return x * y; }, 3, 5) << endl;

	[](int x, int y) {cout << x << ", " << y << endl; }(20, 30);
	//생성하자마자 호출하는 방법

//	int(*f)(int, int) = [](int x, int y) {return x - y; };
	auto f = [](int x, int y) {return x - y; };
	cout << f(1000, 2000) << endl;



	return 0;
}
*/