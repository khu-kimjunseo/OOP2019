#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> list;
	int n = rand() % 100 + 1;
	for (int i = 0; i < n; i++) 
		list.push_back(i);
	
	int cnt = -1;
	while (1) {
		cnt++;
		try { list.at(cnt); }
		catch (exception e) {
			cout << "���� list�� " << cnt-1 << "�� ũ�⸦ ������ �ִ�." << endl;
			break;
		}
	}
	return 0;
}