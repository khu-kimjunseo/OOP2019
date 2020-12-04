#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

//exception class의 method(what()) overriding시: override -> throw()
class FileNotFound : public exception {
private:
	string message;
public:
	FileNotFound(string _filename) :message("File '" + _filename + "' is not found") {}
	virtual const char* what() const throw() {
		return message.c_str();// c_str() : string -> const char*
	}
};

vector<int> load_vector(string filename) {
	vector<int> v;
	ifstream fin(filename);
	if (!fin) {
		//catch 발동
		throw FileNotFound(filename);
	}
	else {
		int n;
		fin >> n;
		for (int i = 0; i < n; i++) {
			int value;
			fin >> value;
			v.push_back(value);
		}
	}
	return v;
}

int main() {
	try {
		vector<int> v = load_vector("vector.txt");
	}
	//catch (FileNotFound& e) {
	catch (exception& e){
		cout << e.what() << endl;
	}

	return 0;
}

/*
// 예외처리 : try{예외가 발생할 수 있는 코드},
//			  catch{예외가 발생할 경우 수행하는 코드}       block이 한 줄이여도 {}적어줘야 함
int main() {
	vector<int> v{ 1, 2, 3, 4 };
	try {
//		cout << v[100] << endl; // assertion failed
//		cout << v.at(100) << endl; // abort() has been called

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	cout << "Exit program" << endl;

	return 0;
}
*/