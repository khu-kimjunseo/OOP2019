#include<iostream>
#include<string>
using namespace std;

void getData(string& _name, int& _nRow, int& _nCol){
	cout << "<Enter the name, # of rows, # of cols>" << endl << ">>";
	cin >> _name >> _nRow >> _nCol;
}

class CMatrix {
private:
	string name;
	float** matrix;
	int nRow;
	int nCol;
	int nElemnet;
public:
	CMatrix() : name("Anonymous"), nRow(4), nCol(4), nElemnet(nRow* nCol) {
		float* row = new float [nCol];
		matrix = new float* [nRow];
		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < nCol; j++) {
				row[j] = 0;
			}
			matrix[i] = row;
		}
	}
	CMatrix(string _name, int _nRow, int _nCol) : name(_name), nRow(_nRow), nCol(_nCol), nElemnet(nRow* nCol) {
		float* row = new float[nCol];
		matrix = new float* [nRow];
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
				int temp;
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
	getData(name, nRow, nCol);
	CMatrix m1(name, nRow, nCol);
	m1.setElement();
	m1.printMatrixInfo();

	return 0;
}