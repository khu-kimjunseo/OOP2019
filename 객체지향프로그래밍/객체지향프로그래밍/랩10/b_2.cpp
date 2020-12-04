#include<iostream>
#include<string>
using namespace std;

class CStudent {
private:
	int number;
	string name;
	string major;

public:
	CStudent() :
		number(2018000000), name("홍길동"), major("컴퓨터공학과") {
	}
	CStudent(int stu_number, string stu_name, string stu_major) {
		number = stu_number;
		name = stu_name;
		major = stu_major;
	}
	void setNumber(int stu_number) {
		number = stu_number;
	}
	void setName(string stu_name) {
		name = stu_name;
	}
	void setMajor(string stu_major) {
		major = stu_major;
	}
	int getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}

	void Display() {
		cout << "학번 :" << number << endl << "이름 :" << name << endl << "전공 :" << major << endl << endl;
	}

};

int main() {
	CStudent s[3];
	int inputNumber = 0;;
	string inputName, inputMajor;
	int length = 0;

	while (1) {
		cout << length + 1 << " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;

		int x = 0;
		for (int i = 0; i < length + 1; i++) {
			if (inputNumber == s[i].getNumber()) {
				x = 1;
				break;
			}
			
		}

		if (x == 1) {
			cout << "※중복된 학번이 존재합니다." << endl << endl;
		}
		else {
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);

			cout << "※입력 완료" << endl << endl;

			length++;
		}

		if (length == 3) {
			cout << "---모든입력이 완료되었습니다---" << endl;
			cout << "1학생정보" << endl;
			s[0].Display();
			cout << "2학생정보" << endl;
			s[1].Display();
			cout << "3학생정보" << endl;
			s[2].Display();

			exit(100);
		}
	}
}