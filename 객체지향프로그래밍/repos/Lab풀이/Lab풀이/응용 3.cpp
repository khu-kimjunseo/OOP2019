#include<iostream>
#include<fstream>
using namespace std;

int main() {

	ofstream ofs;
	ofs.open("temp.txt.");

	int num;

	for (int i = 0; i < 100; i++) {
		num = rand() % 101;	// rand() : 0~32767 범위의 수 중 무작위 선택
						// 101의 나머지, 즉 0 ~ 100 범위의 수를 num에 저장
		ofs << num << " ";

		if (i % 10 == 9)
			ofs << endl;
	}

	ofs.close();

	return 0;
}