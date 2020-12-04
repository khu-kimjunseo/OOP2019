#include <iostream>
#include <string>
#include <fstream>//ifstream ofsteam
using namespace std;

//File 입출력: ifstream, ofstream ( open(), close())
//ofstream fout: fout << 문자열, fout.put(문자)
//ifstrema fin: fin >> 문자열(띄어쓰기와 줄바꿈으로 구분), fin.get(문자), getline(fin, 문자열)-1줄씩 읽기
//fin: 파일이 제대로 열리지 않거나, file의 끝에 도달하면 0,false를 반환

int main() {
	ofstream fout;//fout일 필요없지만 cout과 유사하기 때문에 외우기 쉬워서 교수님께서 사용하심
	string s1 = "Objective Oriented Programming";
	fout.open("example.txt.");//항상 덮어쓰기
//	fout.open("example.txt", ios::app);//이어쓰기 append

	fout << s1 << endl;
	fout << "Random Variable" << endl;
	fout << "Linear Algebra" << endl;

	fout.close();

	ifstream fin;//fin도 마찬가지로 fin일 필요없음
	fin.open("example.txt");
	if (!fin) {
		cout << "Error: no such file exists" << endl;
		exit(100);//프로그램 강제종료
	}

	while (getline(fin, s1)) {
		cout << s1 << endl;
	}
//	fin >> s1;//>>사용시 띄어쓰기나 줄바꿈을 기준으로 하나의 문자열로 인식함
//	char ch;
//	while (true) {
//	//	fin >> s1;// 문자열 1개(띄어쓰기, 줄바꿈 구분)
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
	cout << s1.size() << endl << endl;//size()는 member fucntion 또는 method, size()와 length()는 같은 기능을 하는 member function

	cout << s1.empty() << endl;//empty()는 s1이 빈 문자열인지 아닌지 판단하는 함수로 참이면 1, 거짓이면 0
	s1.clear();//s1 = ""; clear()는 s1을 빈 문자열로 만듬, 
	cout << s1.empty() << endl;

	s1 = "Good";
	s1 += "-bye";
	//Good-bye
	//01234567 :index (zero-base indexing)
	cout << s1 << endl;
	cout << s1[4] << ", " << s1.at(4) << endl;//s1[4]는 c++자체의 operator로 빠르지만 s1.at(4)은 member function이라 느림
											  //그치만 s1.at()은 안정적인 프로그램을 만들 때 좋음
	cout << s1.substr(5, 3) << endl;//s1.substr(a, b)는 s1.[a]부터 b개의 문자를 추출, a = 시작 index, b = 길이
	cout << s1.find("od") << endl;//s1.find()는 해당 문자열의 시작 index를 반환
	cout << (s1.find("od", 5)==string::npos) << endl;//s1.find(문자열,숫자 n)는 n번째 index 부터 해당 문자열의 index를 반환한다.
													 //string::npos는 find()함수 사용 시 찾았으면 1, 못 찾았을 경우 0을 반환하는 함수.

	s1 += "-od";
	int index = s1.find("od");
	cout << s1.find("od", index + 2) << endl; //해당 문자열이 여러번 있을 때 두번째 문자열의 index를 찾는 방법, 시험문제로 내기 좋음.
	return 0;
}
*/