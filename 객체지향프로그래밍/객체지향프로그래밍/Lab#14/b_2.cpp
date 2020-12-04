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
			cout << "현재 list는 " << cnt-1 << "의 크기를 가지고 있다." << endl;
			break;
		}
	}
	return 0;
}