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
	CStudent s1; // A
	s1.Display();

	CStudent s2(1999000000, "공지철", "연극영화과"); // B
	s2.Display();

	//C
	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;

	return 0;
}