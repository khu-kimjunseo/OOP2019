#include<iostream>
#include<string>
using namespace std;

void getData(string& _name, int& _nRow, int& _nCol) {
	cout << "<Enter the name, # of rows, # of cols>" << endl << ">>";
	cin >> _name >> _nRow >> _nCol;
}

template <class T>
class CMatrix {
private:
	string name;
	T** matrix;
	int nRow;
	int nCol;
	int nElemnet;
public:
	CMatrix() : name("Anonymous"), nRow(4), nCol(4), nElemnet(nRow* nCol) {
		T* row = new T[nCol];
		matrix = new T* [nRow];
		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < nCol; j++) {
				row[j] = 0;
			}
			matrix[i] = row;
		}
	}
	CMatrix(string _name, int _nRow, int _nCol) : name(_name), nRow(_nRow), nCol(_nCol), nElemnet(nRow* nCol) {
		T* row = new T[nCol];
		matrix = new T* [nRow];
	}
	CMatrix(CMatrix& m1);

	~CMatrix() {
		for (int i = 0; i < nRow; i++)
			delete[] matrix[i];
		delete[] matrix;
	}

	void setElement() {
		cout << "<Enter the elements of " << name << ">" << endl << ">>";
		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < nCol; j++) {
				T temp;
				cin >> temp;
				matrix[i][j] = temp;
			}
		}
	}
	void printMatrixInfo() {
		cout << name << "(" << nRow << ", " << nCol << ", " << nElemnet << ")" << endl;
		for (int i = 0; i < nRow; i++) {
			cout << "[ ";
			for (int j = 0; j < nCol; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << "]" << endl;
		}
	}
	string getName() const { return name; }

};

int main() {
	string name;
	int nRow, nCol;
	cout << endl << "<Float-type Matrix>" << endl;
	getData(name, nRow, nCol);
	CMatrix<float> m1(name, nRow, nCol);
	m1.setElement();
	m1.printMatrixInfo();

	cout << endl << "<Double-type Matrix>" << endl;
	getData(name, nRow, nCol);
	CMatrix<double> m2(name, nRow, nCol);
	m2.setElement();
	m2.printMatrixInfo();

	cout << endl << "<Integer-type Matrix>" << endl;
	getData(name, nRow, nCol);
	CMatrix<int> m3(name, nRow, nCol);
	m3.setElement();
	m3.printMatrixInfo();
}