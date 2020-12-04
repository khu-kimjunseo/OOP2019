#include<iostream>
#include<vector>
using namespace std;

/*
int main() {
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;	// (int*) *ppa = &pa; 포인터의 포인터
						// &ppa == 0x02, ppa == 0x01, *ppa == 0x00, **ppa == 10


	return 0;
}
*/


int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int evaluate(int(*func)(int, int), int a, int b) {
	return func(a, b);
}


int main() {
	int (*func)(int, int);

	func = sum;
	cout << func(10, 20) << endl;

	func = mult;
	cout << func(10, 20) << endl;

	cout << evaluate(&sum, 10, 20) << endl;
	cout << evaluate(&mult, 10, 20) << endl;

	return 0;
}


/*
void print(const vector<int>& v) { 
	for (unsigned i = 0; i < v.size(); i++) 
		cout << v[i] << '\t';
	cout << endl;
}

int main() {
	vector<int> vec_a(5);	// { 0, 0, 0, 0, 0 }
	vector<int> vec_b(5, 8);// { 8, 8, 8, 8, 8 }
	vector<int> vec_c{ 10, 20, 30, 40, 50 };
	//					0	1	2	3	4

	vec_c.at(0) = 1000; // .at은 vector의 method이고 [i]는 c++ 자체함수
	vec_c[1] = 2000;
	print(vec_c);

	
//	for (unsigned i = 0; i < vec_c.size(); i++) 
//		cout << vec_c[i] << '\t';
//	cout << endl;
	
	vec_c.push_back(60);
	print (vec_c);

	vec_c.pop_back();
	print(vec_c);

	// int& elem = vec_c[0] -> body ->
	// int& elem = vec_c[1] -> body

	for (int& elem : vec_c)
		cin >> elem;

	// int elem = vec_c[0] -> body ->
	// int elem = vec[1] -> body

	for (int ele : vec_c)
		cout << ele << '\t';
	cout << endl;


	return 0;
}
*/