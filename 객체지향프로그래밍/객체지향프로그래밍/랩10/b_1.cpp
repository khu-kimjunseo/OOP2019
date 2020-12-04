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
	CStudent s1; // A
	s1.Display();

	CStudent s2(1999000000, "����ö", "���ؿ�ȭ��"); // B
	s2.Display();

	//C
	s1.setNumber(2006000000);
	s1.setName("�ΰ���");
	s1.setMajor("����Ʈ���");
	cout << "�й� :" << s1.getNumber() << endl;
	cout << "�̸� :" << s1.getName() << endl;
	cout << "���� :" << s1.getMajor() << endl;

	return 0;
}