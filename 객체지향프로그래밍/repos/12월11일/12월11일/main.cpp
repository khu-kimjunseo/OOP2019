#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

//exception class�� method(what()) overriding��: override -> throw()
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
		//catch �ߵ�
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
// ����ó�� : try{���ܰ� �߻��� �� �ִ� �ڵ�},
//			  catch{���ܰ� �߻��� ��� �����ϴ� �ڵ�}       block�� �� ���̿��� {}������� ��
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