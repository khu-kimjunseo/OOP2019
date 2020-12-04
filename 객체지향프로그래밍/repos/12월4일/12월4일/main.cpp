#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>// for_each, copy, tarnsform
using namespace std;

// for_each: �����Լ��� return ���� X
// transform: �����Լ��� return ���� O
int main() {
	vector<int> v1{ 1, 2, 3, 4 };

	for (int elem : v1) 
		cout << elem << '\t';
	cout << endl;

	//for_each: continer�� �� element {main body}�� ����
	//for_each(src_����_iter, src_��_iter, �����Լ�
	//src: source(��õ)�� ����, dst: destination (������)
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
	//copy(src_����_iter, src_��_iter, dst_����_iter);
	copy(begin(v1)+1, end(v1)-1, begin(v2)+2); //vector�� iterator�� ���� ���� �� ������ (������ overloadding�� �Ǿ� ����) �ٸ� container�� �Ұ���
	for_each(begin(v2), end(v2), [](int elem) { cout << elem << '\t'; });
	cout << endl;

	//transform: source container�� element���� �����Ͽ� destination container�� ����
	//trasnform(src_����_iter, src_��_iter, dst_����_iter, �����Լ�
	transform(	begin(v1), end(v1), 
				begin(v2), 
				[](int elem) { return elem * elem; });
	for_each(begin(v2), end(v2), [](int elem) { cout << elem << '\t'; });
	cout << endl;

	return 0;
}
/*
// [closure]: lambda �Լ��� �ܺ� ������ �Լ� ���ο��� ��밡��
// -closure�� ����ϴ� lambda �Լ��� �Է����� �޴� ���
//  �ݵ�� function ��ü�� ����� ��(#include <functional>), �Լ� ������ ��� �Ұ���
// [a]: ���� a�� �Լ� ���ο� call by value�� ����
// [&a]: ���� a�� �Լ� ���ο� call by ref�� ����
// [=]: �ܺ��� ��� ������ call by value�� ����
// [&]: �ܺ��� ��� ������ call by ref�� ����

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
// �Լ��� main�Լ� �ܺο��� ������ �� ����: ��𼭵��� ��밡��
//									  ����: �׻� �޸� ������ �����ϰ� ���� --> �̸� �ذ��ϱ� ���� �����Լ��� ���

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

	//mult : [](int x, int y) { return x * y; } �����Լ��� ��� datatype(->int)�� ���� �ʾƵ� �������
	cout << evaluate([](int x, int y) {return x * y; }, 3, 5) << endl;

	[](int x, int y) {cout << x << ", " << y << endl; }(20, 30);
	//�������ڸ��� ȣ���ϴ� ���

//	int(*f)(int, int) = [](int x, int y) {return x - y; };
	auto f = [](int x, int y) {return x - y; };
	cout << f(1000, 2000) << endl;



	return 0;
}
*/