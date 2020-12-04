#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int column = 1, row = 1;
	while (column <= 10) {
		while (row <= 10) {
			int num;
			num = (column == row ? 1 : 0);
			cout << setw(4) << num;
			row++;
		}
		cout << endl;
		column++;
		row = 1;
	}
	return 0;
}