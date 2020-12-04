#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student {
private:
	string  name;
	int number;
	string major;
	vector<string> subject;
	vector<char> grade;

public:
	Student() :
		name("default"), number(0), major("default") {
	}

	Student(string stu_name, int stu_number, string stu_major) {
		name = stu_name;
		number = stu_number;
		major = stu_major;
	}

	void setName(string stu_name) {
		name = stu_name;
	}
	void setID(int stu_number) {
		number = stu_number;
	}
	void setDpt(string stu_major) {
		major = stu_major;
	}
	void print() {
		cout << name << " " << number << " " << major << endl;
	}
	
	void addGrade(string _subject, char _grade) {
		subject.push_back(_subject);
		grade.push_back(_grade);
	}
	void printGrades() {
		for (int i = 0; i < subject.size(); i++) {
			cout << subject[i] << " " << grade[i] << endl;
		}
		cout << "GPA : " << getGPA() << endl;
	}
	float getGPA() {
		float GPA = 0;
		for (int i = 0; i < grade.size(); i++) {
			switch (grade[i]) {
			case 'A':
				GPA += 4;
				break;
			case 'B':
				GPA += 3;
				break;
			case 'C':
				GPA += 2;
				break;
			case 'D':
				GPA += 1;
				break;
			case 'F':
				GPA += 0;
				break;
			}
		}
		GPA = GPA / grade.size();
		return GPA;
	}
	void getYear(int year) {
		int level = (year * 1000000 - number) / 1000000;
		switch (level) {
		case -1:
			cout << "Freshmen(1학년)" << endl;
			break;
		case 0:
			cout<< "Sophormore(2학년)"<<endl;
			break;
		case 1:
			cout<< "Junior(3학년)"<<endl;
			break;
		case 2:
			cout<< "Senior(4학년)"<<endl;
			break;
		default:
			cout << "About to graduate(5학년 이상)" << endl;
		}
	}
};

int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103969);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Machine Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}