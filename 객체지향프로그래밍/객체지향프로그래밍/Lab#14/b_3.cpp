#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(const string& fname):
		message("File \"" + fname + "\" not found") {}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};
class CStudent {
private:
	string m_Name;
	int m_Number;
	string m_Major;
public:
	CStudent() {}
	~CStudent() {}
	void setAll(string _name, int _num, string _maj) {
		m_Name = _name;
		m_Number = _num;
		m_Major = _maj;
	}
	void Display() {
		cout << "�̸�: " << m_Name << endl;
		cout << "�й�: " << m_Number << endl;
		cout << "����: " << m_Major << endl << endl;
	}
};
vector<CStudent> read_file(string& filename) { 
	ifstream fin(filename);
	if (!fin) {
		throw FileNotFoundException(filename);
	}

	vector<CStudent> result;
	string m_Major, m_Name;
	int m_Number, num;
	fin >> num;
	CStudent temp;
	for (int i = 0; i < num; i++) {
		fin >> m_Name;
		fin >> m_Number;
		fin >> m_Major;
		temp.setAll(m_Name, m_Number, m_Major);
		result.push_back(temp);
	}
	return result;
}
int main() {
	string str;
	cout << "���� �̸� : ";
	cin >> str;
	try {
		vector<CStudent> numbers = read_file(str);
		for (CStudent value : numbers)
			value.Display();
	}
	catch (std::exception& e) {
		cout << e.what() << '\n';
	}
	return 0;
}