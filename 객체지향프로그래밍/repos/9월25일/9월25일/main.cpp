#include <iostream>
#include <string>
#include <fstream>//ifstream ofsteam
using namespace std;

//File �����: ifstream, ofstream ( open(), close())
//ofstream fout: fout << ���ڿ�, fout.put(����)
//ifstrema fin: fin >> ���ڿ�(����� �ٹٲ����� ����), fin.get(����), getline(fin, ���ڿ�)-1�پ� �б�
//fin: ������ ����� ������ �ʰų�, file�� ���� �����ϸ� 0,false�� ��ȯ

int main() {
	ofstream fout;//fout�� �ʿ������ cout�� �����ϱ� ������ �ܿ�� ������ �����Բ��� ����Ͻ�
	string s1 = "Objective Oriented Programming";
	fout.open("example.txt.");//�׻� �����
//	fout.open("example.txt", ios::app);//�̾�� append

	fout << s1 << endl;
	fout << "Random Variable" << endl;
	fout << "Linear Algebra" << endl;

	fout.close();

	ifstream fin;//fin�� ���������� fin�� �ʿ����
	fin.open("example.txt");
	if (!fin) {
		cout << "Error: no such file exists" << endl;
		exit(100);//���α׷� ��������
	}

	while (getline(fin, s1)) {
		cout << s1 << endl;
	}
//	fin >> s1;//>>���� ���⳪ �ٹٲ��� �������� �ϳ��� ���ڿ��� �ν���
//	char ch;
//	while (true) {
//	//	fin >> s1;// ���ڿ� 1��(����, �ٹٲ� ����)
//		fin.get(ch);
//		if (!fin) 
//			break;
//		cout << ch << endl;
//	}
	cout << s1 << endl;
	fin.close();

	return 0;
}
/*
int main() {
	string s1 = "fred";
	cout << s1 << endl;
	cout << s1.size() << endl << endl;//size()�� member fucntion �Ǵ� method, size()�� length()�� ���� ����� �ϴ� member function

	cout << s1.empty() << endl;//empty()�� s1�� �� ���ڿ����� �ƴ��� �Ǵ��ϴ� �Լ��� ���̸� 1, �����̸� 0
	s1.clear();//s1 = ""; clear()�� s1�� �� ���ڿ��� ����, 
	cout << s1.empty() << endl;

	s1 = "Good";
	s1 += "-bye";
	//Good-bye
	//01234567 :index (zero-base indexing)
	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl;//s1[4]�� c++��ü�� operator�� �������� s1.at(4)�� member function�̶� ����
											  //��ġ�� s1.at()�� �������� ���α׷��� ���� �� ����
	cout << s1.substr(5, 3) << endl;//s1.substr(a, b)�� s1.[a]���� b���� ���ڸ� ����, a = ���� index, b = ����
	cout << s1.find("od") << endl;//s1.find()�� �ش� ���ڿ��� ���� index�� ��ȯ
	cout << (s1.find("od", 5)==string::npos) << endl;//s1.find(���ڿ�,���� n)�� n��° index ���� �ش� ���ڿ��� index�� ��ȯ�Ѵ�.
													 //string::npos�� find()�Լ� ��� �� ã������ 1, �� ã���� ��� 0�� ��ȯ�ϴ� �Լ�.

	s1 += "-od";
	int index = s1.find("od");
	cout << s1.find("od", index + 2) << endl; //�ش� ���ڿ��� ������ ���� �� �ι�° ���ڿ��� index�� ã�� ���, ���蹮���� ���� ����.
	return 0;
}
*/