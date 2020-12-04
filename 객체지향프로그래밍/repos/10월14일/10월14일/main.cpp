#include<iostream>
#include<vector>
using namespace std;


int main() {
	int ary[3] = { 10, 20, 30 };
	int* begin, * end, * curr;

	begin = ary;
	end = ary + 3;
	
	cout << *(ary+3) << endl;
	curr = begin;
	while (curr != end) {
		cout << *curr << "\t";
		curr++;
	}

	return 0;
}


/*
int main() {
	int ary[3] = { 10, 20, 30 };

	cout << (ary + 0) << "\t" << *(ary + 0) << "\t" << ary[0] << endl;
	cout << (ary + 1) << "\t" << *(ary + 1) << "\t" << ary[1] << endl;
	cout << (ary + 2) << "\t" << *(ary + 2) << "\t" << ary[2] << endl;

	return 0;
}
*/

/*
void print(int* list, int size) {	// int* list == int list[]
	for (int i = 0; i < size; i++)
		cout << list[i] << "\t";
	cout << endl;
}

void clear(int list[], int size) {
	for (int i = 0; i < size; i++)
		list[i] = 0;
}

int main() {
	int list[3] = { 10,20,30 };

	print(list, 3);
	clear(list, 3);
	print(list, 3);

	return 0;
}
*/

/*
//using Matrix = vector<vector<int>>;
int main() {
	vector<vector<int>> vec { {1,2,3}, // Matrix { {1,2,3}, {4,5,6} };
							  {4,5,6} };

	for (vector<int>& row : vec) {
		for (int& elem : row)
			cin >> elem;
	}
	for (int row = 0; row < vec.size(); row++) {
		for (int col = 0; col < vec[row].size(); col++) {
			cout << vec[row][col] << "\t";
		}
		cout << endl;
	}
	
}
*/

/* 실행오류 생각해보기
void get_data(int& low, int& high) {
	cout << "Enter low and high numbers: ";
	cin >> low >> high;
}


bool is_prime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}


vector<int> primes(int low, int high) {
	vector<int> vec;
	for (int i = low; i <= high; i++) {
		if (is_prime(i))
			vec.push_back(i);
	}
	return vec;
}

void print(const vector<int>& vec) {
	for (int elem : vec)
		cout << elem << "\t";
	cout << endl;
}

int main() {
	int low, high;
	get_data(low, high);

	vector<int> vec = primes(low, high);

	print(vec);

	return 0;
}
*/
