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
		number(2018000000), name("ȫ�浿"), major("��ǻ�Ͱ��а�") {
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
		cout << "�й� :" << number << endl << "�̸� :" << name << endl << "���� :" << major << endl << endl;
	}

};

int main() {
	CStudent s[3];
	int inputNumber = 0;;
	string inputName, inputMajor;
	int length = 0;

	while (1) {
		cout << length + 1 << " ��° �л� �Է�" << endl;
		cout << "�й� : ";
		cin >> inputNumber;
		cout << "�̸� : ";
		cin >> inputName;
		cout << "���� : ";
		cin >> inputMajor;

		int x = 0;
		for (int i = 0; i < length + 1; i++) {
			if (inputNumber == s[i].getNumber()) {
				x = 1;
				break;
			}
			
		}

		if (x == 1) {
			cout << "���ߺ��� �й��� �����մϴ�." << endl << endl;
		}
		else {
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);

			cout << "���Է� �Ϸ�" << endl << endl;

			length++;
		}

		if (length == 3) {
			cout << "---����Է��� �Ϸ�Ǿ����ϴ�---" << endl;
			cout << "1�л�����" << endl;
			s[0].Display();
			cout << "2�л�����" << endl;
			s[1].Display();
			cout << "3�л�����" << endl;
			s[2].Display();

			exit(100);
		}
	}
}