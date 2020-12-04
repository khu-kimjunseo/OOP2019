#include <iostream>
using namespace std;

int main() {
	double x;
	cout << "Please enter Fahrenheit value: " ;
	cin >> x;

	x = 5.0 / 9.0 * (x - 32);
	cout << endl << "Celsius value is " << x << endl;

}