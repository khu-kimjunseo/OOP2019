#include <iostream>
using namespace std;

int main() {
	int num, i = 1, x = 0;
	cout << "number : ";
	cin >> num;
	while (i <= num) {
		x += i;
		i++;
	}
	cout << x << endl;
	return 0;
}