#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

/*
int main() { // cout, cin ��ſ� fout, fin ���� ��밡��
	double a = 12.347;

	cout.width(15); //iomanip::setw()�� ������ ����� ��
	cout << a << endl;
	
	cout.precision(4);
	cout.width(14);
	cout.fill('*');
	cout << a << endl;

	char ch;
	cin.unsetf(ios::skipws);
	cin >> ch;
	cout << '(' << ch << ')' << endl;
	cin.setf(ios::skipws);

	






	return 0;
}
*/
bool readStu(ifstream& fin, int& id, int& score1, int& score2, int& score3) {
	fin >> id >> score1 >> score2 >> score3;
	if (!fin)
		return false;
	else
		return true;
}

void calcGrade(int score1, int score2, int score3, int& avg, char& grade) {
	avg = (score1 + score2 + score3) / 3;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else if (avg >= 70)
		grade = 'C';
	else if (avg >= 60)
		grade = 'D';
	else
		grade = 'F';

}

void writeStu(ofstream& fout, int id, int avg, char grade) {
	fout.fill('0');
	fout << setw(4) << id; // (  90) -> (0090)
	fout.fill(' ');
	fout << setw(3) << avg;
	fout << setw(2) << grade << endl;
	
}
int main() {
//�ݺ�: ��� �л� ������ ó���� �� ����
	//1) ch7STUFL.DAT ���Ͽ��� 1���� �л� ������ �б�(id, s1, s2, s3)
	//2) s1, s2, s3�� �Է����� �޾� ���(avg), ����(grade)�� ���
	//3) grade.txt: id, avg, grade ������ ����
	ifstream fin("ch7STUFL.DAT"); // fin.open("")
	ofstream fout("grade.txt"); // fout.open("")
	
	int id, score1, score2, score3, avg;
	char grade;
	
	// 4) ���� ó��
	if (!fin || !fout) {
		cout << "���� ���� ����" << endl;
		exit(100);
	}

	while (readStu(fin, id, score1, score2, score3)) {//1)
		calcGrade(score1, score2, score3, avg, grade);
		writeStu(fout, id, avg, grade);
	}
	
	cout << "���α׷� ����" << endl;

	fin.close();
	fout.close();
	
	return 0;
}
