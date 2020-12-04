#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

void get_num(int& num) {
	cout << "Enter a number: ";
	cin >> num;
}

void get_filename(ifstream& fin, string filename) {
	cout << "Enter a file name: ";
	cin >> filename;
}

void open_file(ifstream& fin, string filename) {
	fin.open(filename);
	if (!fin) {
		cout << "Error: file open failed" << endl;
		exit(100);
	}
}

void CountSameNum(ifstream& fin, int num, int& count) {
	count = 0;
	int temp;
	while (true) {
		fin >> temp;
		if (!fin)
			break;
		else {
			if (temp == num)
				count++;
		}
	}
}

int main() {

	return 0;
}