#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	ofstream ofs;
	ofs.open("temp.txt");
	int i = 0;
	while (i < 100) {
		ofs << setw(4) << rand() % 101;
		if (i % 10 == 9)
			ofs << endl;
		i++;
	}
	ofs.close();

	string fname;

	cout << "파일 이름 : ";
	cin >> fname;
	try {
		ifstream fin(fname);
		if (!fin)
			throw exception();

		vector<vector<int>> vec(10, vector<int> (10));
		for (vector<int>& row : vec) {
			for (int& elem : row) {
				fin >> elem;
			}
		}
		int m, n;
		cout << "출력할 행 크기 : ";
		cin >> m;
		cout << "출력할 열 크기 : ";
		cin >> n;
		try {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << vec.at(i).at(j) << " ";
				}
				cout << endl;
			}
		}
		catch (exception& e) {
			cout << endl << e.what() << endl;
		}
	}
	catch (exception& e){
		cout << "File \"" << fname << "\" not found" << endl;
	}

	

	return 0;
}