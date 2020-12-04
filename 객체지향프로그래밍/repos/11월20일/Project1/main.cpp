#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main() {
	ofstream fout("fooditem.txt");
	fout << "F1002" << setw(10) << "계란빵" << setw(10) << "1000" << setw(10) << 20181120 << endl;
	fout << "F1003" << setw(10) << "사발면" << setw(10) << "1500" << setw(10) << 20201100 << endl;
	fout.close();

	fout.open("officeitem.txt");
	fout << "C1001" << setw(10) << "계산기" << setw(10) << "14000" << setw(10) << "Sharp" << endl;
	fout << "C1002" << setw(10) << "샤프" << setw(10) << "1000" << setw(10) << "Monami" << endl;
	fout << "C1003" << setw(10) << "지우개" << setw(10) << "500" << setw(10) << "Evergreen" << endl;
}