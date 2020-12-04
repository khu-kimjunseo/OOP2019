#include<iostream>
#include<string>
using namespace std;

void getData(string& _name, int& _nRow, int& _nCol) {
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
		float* row = new float[nCol];
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
	CMatrix(CMatrix& m1) : name(m1.name), nRow(m1.nRow), nCol(m1.nCol), nElemnet(nRow* nCol) {
		float* row = new float[nCol];
		matrix = new float* [nRow];
		for (int i = 0; i < nRow; i++) 
			for (int j = 0; j < nCol; j++) 
				matrix[i][j] = m1.matrix[i][j];
	}

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

	CMatrix operator+ (const CMatrix& m1) {
		if (this->nRow == m1.nRow && this->nCol == m1.nCol) {
			CMatrix result(this->name + m1.name, this->nRow, this->nCol);
			for (int i = 0; i < nRow; i++) 
				for (int j = 0; j < nCol; j++) 
					result.matrix[i][j] = this->matrix[i][j] + m1.matrix[i][j];	
			return result;
		}
		else {
			cout << "<Error : dimension mismatch>" << endl;
		}
	}

	CMatrix operator- (const CMatrix& m1) {
		if (this->nRow == m1.nRow && this->nCol == m1.nCol) {
			CMatrix result(this->name + m1.name, this->nRow, this->nCol);
			for (int i = 0; i < nRow; i++)
				for (int j = 0; j < nCol; j++)
					result.matrix[i][j] = this->matrix[i][j] - m1.matrix[i][j];
			return result;
		}
		else {
			cout << "<Error : dimension mismatch>" << endl;
		}
	}

	CMatrix operator* (const CMatrix& m1) {
		if (this->nRow == m1.nRow && this->nCol == m1.nCol) {
			CMatrix result(this->name + m1.name, this->nRow, this->nCol);
			for (int i = 0; i < nRow; i++)
				for (int j = 0; j < nCol; j++)
					result.matrix[i][j] = this->matrix[i][j] * m1.matrix[i][j];
			return result;
		}
		else {
			cout << "<Error : dimension mismatch>" << endl;
		}
	}

	CMatrix operator* (int n) {
		CMatrix result(this->name, this->nRow, this->nCol);
		for (int i = 0; i < nRow; i++)
			for (int j = 0; j < nCol; j++)
				result.matrix[i][j] = this->matrix[i][j] * n;
		return result;
	}

	void operator== (const CMatrix& m1) {
		int temp = 1;
		if (this->nRow == m1.nRow && this->nCol == m1.nCol) {
			for (int i = 0; i < nRow; i++)
				for (int j = 0; j < nCol; j++)
					if (this->matrix[i][j] != m1.matrix[i][j])
						temp = 0;
			if (temp == 1) 
				cout << this->name << " and " << m1.name << " are equal." << endl;
			else
				cout << this->name << " and " << m1.name << " are unequal." << endl;
		}
		else {
			cout << "<Error : dimension mismatch>" << endl;
		}
	}
	CMatrix operator= (const CMatrix& m1) {
		CMatrix temp(CMatrix & m1);
		return temp;
	}
};


int main() {
	string name;
	int nRow, nCol;
	cout << endl << "<1st Matrix>" << endl;
	getData(name, nRow, nCol);
	CMatrix m1(name, nRow, nCol);
	m1.setElement();
	m1.printMatrixInfo();

	cout << endl << "<2nd Matrix>" << endl;
	getData(name, nRow, nCol);
	CMatrix m2(name, nRow, nCol);
	m2.setElement();
	m2.printMatrixInfo();
	
	cout << endl << "<Results>" << endl;
	CMatrix m3 = m1 + m2;
	m3.printMatrixInfo();

	CMatrix m4 = m1 - m2;
	m3.printMatrixInfo();

	CMatrix m5 = m1 * m2;
	m3.printMatrixInfo();

	CMatrix m6 = m1 * 5;
	m3.printMatrixInfo();
}