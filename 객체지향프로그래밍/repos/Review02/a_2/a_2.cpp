#include<iostream>
#include<vector>
using namespace std;

class VectorList {
	vector<double*> vItem;
	vector<int> vLength;
public:
	~VectorList() {
		for (int i = 0; i < vItem.size(); i++)
			delete[] vItem[i];
	}
	void append(double* _pArray, int _length) { vItem.push_back(_pArray); vLength.push_back(_length); }
	int findVector(double* _pArray, int _length) {
		int x = 0;
		for (int i = 0; i < vItem.size(); i++) {
			if (_length == vLength[i]) {
				x = i;

				for (int i = 0; i < vLength[x]; i++) {
					if (_pArray[i] != vItem[x][i]) {
						break;
					}
					else {
						return x;
					}
				}
			}
		}
		return -1;
	}

	void print_single_vector(int idx) {
		if (idx < 0)
			cout << "[Wrong index]" << endl;
		else {
			cout << idx << "-th vector:";
			for (int i = 0; i < vLength[idx]; i++) {
				cout << "\t" << vItem[idx][i];
			}
			cout << endl;
		}
	}
	void print_all_vectors() {
		for (int i = 0; i < vLength.size(); i++) {
			cout << i << "-th vector:";
			for (int j = 0; j < vLength[i]; j++) {
				cout << "\t" << vItem[i][j];
			}
			cout << endl;
		}
	}
};
int main() {
	VectorList vectorList;
	double* pTemp = new double[3]{ 1.1, 2.2, 3.3 };
	vectorList.append(pTemp, 3);

	pTemp = new double[5]{ 10.1, 10.2, 10.3, 10.4, 10.5 };
	vectorList.append(pTemp, 5);

	pTemp = new double[2]{ 4.5, 5.5 };
	vectorList.append(pTemp, 2);

	vectorList.print_single_vector(-1); //Wrong index
	vectorList.print_single_vector(0); // 0-th vector: 1.1 2.2 3.3
	cout << endl;

	vectorList.print_all_vectors();
	cout << endl;

	double* pTemp1 = new double[2]{ 4.5, 5.5 };
	double* pTemp2 = new double[4]{ 1.1, 2.2, 5.5, 4.4 };

	cout << "Index of vector{4.5, 5.5} :" << vectorList.findVector(pTemp1, 2) << endl;
	cout << "Index of vector{1.1, 2.2, 5.5, 4.4} : " << vectorList.findVector(pTemp2, 4) << endl;

	delete[] pTemp;
	delete[] pTemp1;
	delete[] pTemp2;

	return 0;
}