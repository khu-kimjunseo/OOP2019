#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

void get_num(int& num) {
	cout << "Enter a number: ";
	cin >> num;
}

void get_filename(string& filename) {
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

void countSameNum(ifstream& fin, int num, int& count) {
	char ch;
	int i = 0;
	count = 0;
	string temp = "";
	while (true) {
		fin.get(ch);
		temp = temp + ch;
		if (!fin)
			break;
	}
	
	while(temp.find(num, i) == string::npos) {
		if (num < 10) {
			int index = temp.find(num, i);

			if (temp[index - 1] != ('\t' || '\n') && temp[index+1] != ('\t' || '\n')) 
				i++;

			else {
				count++;
				i++;
			}

		}
		else {
			count++;
			i++;
		}
	}
}

int main() {
	int num, count;
	string filename;
	ifstream fin;
	ofstream fout;

	get_filename(filename);
	get_num(num);
	open_file(fin, filename);
	countSameNum(fin, num, count);

	cout << "Output: " << count << endl;

	fin.close();
	return 0;
}
