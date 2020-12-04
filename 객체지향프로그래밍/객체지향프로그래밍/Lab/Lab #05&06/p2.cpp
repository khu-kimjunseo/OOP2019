#include<iostream>
#include<iomanip>//stew등 cout 표현을 멋지게
using namespace std;

int main() {
	int num = 1;
	int count = 1;
	cout.imbue(locale(""));
	while (count <= 20) {
		num = pow(2,count);
		cout << count << '\t' << setw(9) << num << endl;
		count++;
	}
	return 0;
}