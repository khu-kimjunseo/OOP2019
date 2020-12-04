#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> v1 = { 1, 2, 3, 4 };
	for (int& elem : v1) {
		cout << elem << '\t';
	}
	cout << endl;

	for_each(begin(v1), end(v1), [](auto x) {cout << x << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](auto& x) { x++; });
	for_each(begin(v1), end(v1), [](auto x) {cout << x << '\t'; });
	cout << endl;

	int a = 10;
	for_each(begin(v1), end(v1), [](auto& x) { x += 10; });
	for_each(begin(v1), end(v1), [](auto x) {cout << x << '\t'; });
	cout << endl;

	vector<int> v2(v1.size());
	copy(begin(v1)+1, end(v1)-1, begin(v2)+2);
	for_each(begin(v2), end(v2), [](auto x) {cout << x << '\t'; });
	cout << endl;

	transform(begin(v1), end(v1), begin(v2), [](auto x) {return x * x; });
	for_each(begin(v2), end(v2), [](auto x) {cout << x << '\t'; });
	cout << endl;

	return 0;

}