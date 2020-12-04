#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

double** get_matrix(int& row, int& col) {
	do {
		cout << "Enter nRow and nCol in (nRow x nCol)" << endl << ">>";
		cin >> row;
		cin >> col;
	} while (row < 1 || col < 1);

	double** matrix = new double* [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new double [col];

	cout << "Enter elements" << endl << ">>";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];
		}
	}
	//cout << endl;
	return matrix;
}

void free_matrix(double** matrix,int row, int col) {
	for (int i = 0; i < row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

double** mult_matrix(double** mat1, double** mat2, int row1, int col1, int row2, int col2) {
	if (col1 == row2) {
		double sum;
		double** matrix = new double* [row1];
		for (int i = 0; i < row1; i++)
			matrix[i] = new double[col2];
		
		for (int i = 0; i < row1; i++) {
			for (int j = 0; j < col2; j++) {
				sum = 0.0;
				for (int k = 0; k < col1; k++) {
					sum += mat1[i][k] * mat2[k][j];
				}
				matrix[i][j] = sum;
			}
		}

		return matrix;
	}
	else {
		cout << "Error: dimension mismatch" << endl;
		free_matrix(mat1, row1, col1);
		free_matrix(mat2, row2, col2);
		exit(100);
	}
}

void save_matrix(string filename, string text, double** matrix, int row, int col) {
	ofstream fout(filename); //ofstream fout(filename, ios::app);
	//fout.precision(4);
	fout << text << endl;
	fout << setw(8) << row << setw(8) << col << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fout << setw(8) << matrix[i][j];
		}
		fout << endl;
	}
	fout.close();

	cout << text << " is saved in " << filename << endl;
}

int main() {
	int nRow1, nCol1, nRow2, nCol2;
	string filename = "mat_mult_result.txt";
	double** mat1 = get_matrix(nRow1, nCol1);
	double** mat2 = get_matrix(nRow2, nCol2);
	double** mat3 = mult_matrix(mat1, mat2, nRow1, nCol1, nRow2, nCol2);

	save_matrix(filename, "(input01)", mat1, nRow1, nCol1);
	save_matrix(filename, "(input02)", mat2, nRow2, nCol2);
	save_matrix(filename, "(output01)", mat3, nRow1, nCol2);

	free_matrix(mat1, nRow1, nCol1);
	free_matrix(mat2, nRow2, nCol2);
	free_matrix(mat3, nRow1, nCol2);

	return 0;
}