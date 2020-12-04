#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

// container�� generic�� �Լ� ����� :begin(), end()�� �Է��� ����
// - iterator�� datatype�� template�� ����
template<class Iter>
void print(Iter iter_begin, Iter iter_end) {
	for (auto iter = iter_begin; iter != iter_end; iter++)
		cout << *iter << '\t';
	cout << endl;
}

template<class Iter, class T>
int count_value(Iter iter_begin, Iter iter_end, T key_value) {
	int count = 0;
	for (auto iter = iter_begin; iter != iter_end; iter++)
		if (*iter == key_value)
			count++;
	return count;
}

int main() {
	vector<int>v{ 1, 2, 3, 4, 2, 2};
	list<double> l{ 1.1, 2.2, 3.3, 4.4, 4.4 };
	int ary[] = { 10, 20, 30, 40, 30, 30, 30, 30 };

	print(begin(v), end(v));
	print(begin(l), end(l));
	print(begin(ary), end(ary));
	cout << endl;

	cout << count_value(begin(v), end(v), 2) << endl;
	cout << count_value(begin(l), end(l), 4.4) << endl;
	cout << count_value(begin(ary), end(ary), 30) << endl << endl;

	struct Point {
		int x;
		int y;
		Point(int _x, int _y) :x(_x), y(_y) {}
		bool operator==(const Point& pt) {
			return (x == pt.x) && (y == pt.y);
		}
	};

	Point points[] = { {1,2},{3,4},{5,6},{1,2} };
	cout << count_value(begin(points), end(points), Point{ 1,2 });

	return 0;
}

/*
// iterator: pointer�� ������ ��ü: container�� element�� Ž��
// - key �Լ�: begin(v), end(v)
// - �ֿ� ������ : iter++, iter--, *iter, iter1 != iter2    |||||||     iter += 5 (x)
int main() {
	vector<int> v{ 1, 2, 3, 4 };

//	vector<int>::iterator iter_begin = begin(v); // v.begin();
//	auto iter_end = end(v); //v.end();
//	vector<int>::iterator => auto
//	for (auto iter = iter_begin; iter != iter_end; iter++)
//		cout << *iter << '\t';
//	cout << endl;

	for (auto iter = begin(v); iter != end(v); iter++)
		cout << *iter << '\t';
	cout << endl;

	return 0;
}
*/

/*
int main() {
	int ary[] = { 1, 2, 3 };

	int* begin = ary;
	int* end = ary + 3;

	for (auto curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	cout << endl;

	return 0;
}
*/

/*
//template: data type�� �Ϲ�ȭ�� �Լ�/Ŭ���� ���� ����
//-class template: ������ method���� template<class T>, �������� ������ �տ� <T>
template<class T>
class Point {
private:
	T x;
	T y;
public:
	Point(T _x, T _y) :x(_x), y(_y);
	void setXY(T _x, T _y);
	T getX() const;
	T getY() const;
	void print() const;
};


template<class T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}

template<class T>
void Point<T>:: setXY(T _x, T _y) { x = _x; y = _y; }

template<class T>
T Point<T>::getX() const { return x; }

template<class T>
T Point<T>::getY() const { return y; }

template<class T>
void Point<T>::print() const { cout << x << ", " << y << endl; }


int main() {
	Point<int> pt(1, 2);
	Point<double> pt2(1.1, 2.2);

	return 0;
}
*/

/*
template <class T, class U>
bool less_than(const T& a, const U& b) { return a < b; } //template�� ��ü�� �� �� �����Ƿ� const�� �ɾ��ִ°� ����

template<typename T>
T sum(const vector<T>& v) {
	T result = 0;
	for (T elem : v)
		result += elem;
	return result;
}

int main() {
	cout << less_than(2, 3) << endl;
	cout << less_than(2.1, 2.8) << endl;
	cout << less_than(2, 2.8) << endl << endl;

	vector<int> v1{ 1, 2, 3 };
	vector<double> v2{ 1.1, 2.2, 3.3 };

	cout << sum(v1) << endl;
	cout << sum(v2) << endl;


	return 0;
}
*/