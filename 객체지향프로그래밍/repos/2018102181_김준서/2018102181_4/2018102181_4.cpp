#include<iostream>
#include<string>
using namespace std;

void getData(string& _name, int& _nRow, int& _nCol) {
	cout << "<Enter the name, # of rows, # of cols>" << endl << ">>";
	cin >> _name >> _nRow >> _nCol;
}

void getData(string& filename) {
	cout << "<Set Matrix Name>" << endl;
	cin >> filename;
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

};

class ListType {
private:
	int length;
	CMatrix cMatrix[100];
private:
	void exchange(CMatrix& m1, CMatrix& m2) {
		CMatrix temp(m1);
		m1 = m2;
		m2 = temp;
	}
public:
	ListType() :length(0) {}

	int addMatrix(CMatrix m1) {
		if (length < 101) {
			for (int i = 0; i < length; i++) {
				if (cMatrix[i].getName() > m1.getName()) {
					for (int j = length; j > i; j--)
						cMatrix[j] = cMatrix[j - 1];
					cMatrix[i] = m1;
					length++;
				}
			}
			return 1;
		}
		return -1;
	}

	int deleteMatrix(CMatrix& m1, string name) {
		int i = searchMatrix(m1, name);
		if(i != -1){
			for (int j = i; j < length; j++)
				cMatrix[j] = cMatrix[j + 1];
			length--;
			return i;
		}
		return -1;
	}
	
	int searchMatrix(CMatrix& m1, string name) {
		for (int i = i; i < length; i++) {
			if (cMatrix[i].getName() == name) 
				return i;
		}
		return -1;
	}

	void printAllMatrices() {
		for (int i = 0; i < length; i++) {
			cMatrix[i].printMatrixInfo;
		}
		cout << endl << "Total # of matrices: " << length << endl;
	}
};

int main() {
	string name, command, filename;
	int nRow, nCol;
	ListType list;
	while (1) {
		cout << endl;
		cout << "1. Add New Matrix" << endl;
		cout << "2. Delete Matrix" << endl;
		cout << "3. Print Matrices" << endl;
		cout << "4. Exit" << endl;
		cout << ">>";
		cin >> command;

		if (command == "1") {
			getData(name, nRow, nCol);
			CMatrix m1(name, nRow, nCol);
			m1.setElement();
			list.addMatrix(m1);
		}
		else if (command == "2") {
			getData(filename);
			CMatrix m1;
			list.deleteMatrix(m1, name);
		}
		else if (command == "3") {
			list.printAllMatrices();
		}
		else if (command == "4") {
			exit(100);
		}
	}
	return 0;
}