#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> list{ 10, 20, 30, 40, 50 };
	int num;
	while (1) {
		try {
			cout << "출력 할 숫자의 수" << endl;
			cin >> num;
			if (num > 0) {
				for (int i = 0; i < num; i++) {
					cout << list.at(i) << ' ';
				}
				cout << endl;
			}
			else
				break;
		}
		catch (exception& e) {
			cout << endl << "Index is out of range. Please try again." << endl;
		}
	}
	cout << "Program exit..." << endl;
	return 0;
}