#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void Initialize_Array(vector <vector<int>>& array) {
	for (int row = 0; row < array.size(); row++)
		for (int col = 0; col < array[row].size(); col++)
			array[row][col] = rand() & 19 - 9;
}

void Print_Array(vector<vector<int>>& array) {
	for (int row = 0; row < array.size(); row++) {
		for (int col = 0; col < array[row].size(); col++) {
			cout << setw(4) << array[row][col] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> Multiply_Array(vector<vector<int>> A_array, vector<vector<int>> B_array) {

	vector<vector<int>> AB_array(A_array.size(), vector<int>(B_array[0].size()));

	for (int row = 0; row < A_array.size(); row++)
		for (int col = 0; col < B_array[row].size(); col++)
			for (int i = 0; i < A_array[row].size(); i++)
				AB_array[row][col] += A_array[row][i] * B_array[i][col];

	return AB_array;
}
int main() { // 메인함수는 문제보고 완성
	int a_row, a_col;
	int b_row, b_col;

	cout << "A의 행, 열의 값을 입력하시오: ";
	cin >> a_row >> a_col;
	cout << "B의 행, 열의 값을 입력하시오: ";
	cin >> b_row >> b_col;

	if (a_row < 1 || a_col < 1 || b_row < 1 || b_col < 1) {
		cout << "행렬을 생성할 수 없습니다.\n" << endl;
		exit(EXIT_FAILURE);
	}

	vector<vector<int>> A_array(a_row, vector<int>(a_col));
	vector<vector<int>> B_array(b_row, vector<int>(b_col));

	Initialize_Array(A_array);
	Initialize_Array(B_array);
}